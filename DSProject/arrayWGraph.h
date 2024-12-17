//
// Created by Fall_ on 2024/12/12.
//

#ifndef DSPROJECT_ARRAYWGRAPH_H
#define DSPROJECT_ARRAYWGRAPH_H

#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <set>
#include <unordered_map>
#include "graph.h"
#include "edge.h"
#include "node.h"
#include "vertexIterator.h"
#include <queue>
template<class T>
class arrayWGraph :public graph<T>{
    ///图的基础数据结构
    protected:
    int v_num;
    int e_num;
    struct Vertex {
        int node_id;
        vector<Node<T>> connect_v;
    };//用邻接数组的方式存储连接关系（node中含有连向本节点边的权值属性）
    vector<Vertex> tables;//邻接表
    vector<NodeInfo> vs_inf;//存储节点信息
    //确保info中的索引与tables中的一样

    public:
    /// arrayWGraph基础，包含基类函数、迭代器和实用子方法（实现于arrayWGraph_basic.tpp）
    // 基类函数实现
     arrayWGraph();
    ~arrayWGraph(){};
    int numberOfVertices() const {return v_num;}; // 获取点的个数
    int numberOfEdges() const {return e_num;}; // 获取边的个数
    bool existsEdge(int vertex1_id, int vertex2_id) const; // 判断两条边是否直接相连
    void insertEdge(edge<T>* Edge); // 插入边
    bool eraseEdge(int v1, int v2); // 删除边
    int degree(int v) const {return vs_inf[v].degree;}; // 获取度
    bool directed()  const { return false; }; // 是否为有向图
    bool weighted()  const { return true; }; // 是否为有权图




    ///一些其他函数
    int getIndex(int x) const; // 获取编号为x的点的索引
    void insertEdgeSingle(int v1_id, int v2_id,T w);//单边插入（为正常插入做准备）
    void eraseEdgeSingle(int v1_id, int v2_id);//单边删除，作用同上
    bool cycle();//判断是否存在环路
    bool SingleVertexDFSforCycle(int v_id,set<int> vi, unordered_map<int,int> p);//单点dfs搜索环
    vector<set<int>> connectedSets(); // 输出连通集
    void addVertex(NodeInfo N);//增加节点
    void deleteVertex(int v_id);//删除节点
    ///其他需要的属性
    set<int> *vis0;//访问表
    int *vis1;
    unordered_map<int,int> *p;


    // 基类迭代器子类实现
    class myIterator : public vertexIterator<T> {
    public:
        myIterator(Vertex& thelist) { // 传入引用，减小开销
            newlist = thelist.connect_v;
            size = newlist.size(); // 初始化
            cur = 0;
        };
        int next() { // 取出当前，指向后一个
            if (cur > size)return 0; // 终止
            int nextVertex = newlist[cur].node_id; // 取出权值和下标
            cur++;//游标后移
            return nextVertex;
        };
        int next(T& theWeight) {
            if (cur > size)return 0; // 终止
            int nextVertex = newlist[cur].node_id; // 取出下标
            theWeight = newlist[cur].node_weight; // 取出权值，存放到传入引用参数
            cur++; // 游标后移
            return nextVertex;
        };
        int next(T& theWeight, int& pos) {
            if (cur > size) return 0; // 终止
            int nextVertex = newlist[cur].node_id; // 取出下标
            theWeight = newlist[cur].node_weight; // 取出权值，存放到传入引用参数
            pos = cur++; // 游标后移
            return nextVertex;
        };
        void reset() { cur = 0; } // 重置游标
    protected:
        vector<Node<T>> newlist;
        int x;
        int cur;
        int size;
    };

    // 图迭代器成员实现
    myIterator* iterator(int node_id) {
        return new myIterator(tables[getIndex(node_id)]); // 为类中传入边表，因为该类无法使用主类中的nodes
    };
};
// 构造函数（初始化）
template<class T>
arrayWGraph<T>::arrayWGraph(){
    // 初始化图的属性
    v_num = 0;
    e_num = 0;
}


//判断两个节点之间是否有边
template<class T>
bool arrayWGraph<T>::existsEdge(int v1_id, int v2_id) const {//填坑：无序邻接数组先用getindex获取索引在进行寻找
    int v1_index= getIndex(v1_id);
    int v2_index=getIndex(v2_id);
    int v1c_num = tables[v1_index].connect_v.size();
    int v2c_num = tables[v2_index].connect_v.size();
    bool a,b=false;
    for (int i = 0; i < v1c_num; i++){
        if (tables[v1_index].connect_v[i].node_id == v2_id){
            a=true;
        }
    }
    for (int i = 0; i < v2c_num ; i++){
        if (tables[v2_index].connect_v[i].node_id == v1_id){
            b=true;
        }
    }
    return a&&b;//无向图，双向检查
}


// 根据NodeInfo的node_id编号获取ins_f<NodeInfo>中对应的索引（即对应到ins_f的存储结构），主要用途可以是访问
template<class T>
int arrayWGraph<T>::getIndex(int x) const {
    for (int i = 0; i < v_num; i++){
        if (tables[i].node_id == x){
            return i;
        }
    }

}

template<class T>//用于实现插入边的插入单向边（非完整模块）
void arrayWGraph<T>::insertEdgeSingle(int v1_id,int v2_id,T w){
    int v1_index= getIndex(v1_id);
    Node<T> V2X(v2_id,w);
    tables[v1_index].connect_v.push_back(V2X);
}

template<class T>
void arrayWGraph<T>::insertEdge(edge<T> *Edge) {// 插入边(默认两个点都存在)
    int v1=Edge->get_v1();
    int v2=Edge->get_v2();
    int v1_index=getIndex(v1);
    int v2_index= getIndex(v2);
    T w=Edge->get_w();
    if(existsEdge(v1,v2)){
        cout<<"已经有边！";
        return;
    }
    else{
        insertEdgeSingle(v1,v2,w);
        insertEdgeSingle(v2,v1,w);
        vs_inf[v1_index].degree++;
        vs_inf[v2_index].degree++;
        e_num++;
    }
}

template<class T>
void arrayWGraph<T>::eraseEdgeSingle(int v1_id, int v2_id) {// 删除单向边（同上，非完整模块）
    int v1_index= getIndex(v1_id);
    for(auto i=tables[v1_index].connect_v.begin();i!=tables[v1_index].connect_v.end();i++){
        if((*i).node_id==v2_id){
            tables[v1_index].connect_v.erase(i);
            break;
        }
    }



}

template<class T>
bool arrayWGraph<T>::eraseEdge(int v1_id, int v2_id){// 删除边（默认边存在）
    int v1_index= getIndex(v1_id);
    int v2_index= getIndex(v2_id);
    eraseEdgeSingle(v1_id,v2_id);
    eraseEdgeSingle(v2_id,v1_id);
    vs_inf[v1_index].degree--;
    vs_inf[v2_index].degree--;
    e_num--;
}

template<class T>
bool arrayWGraph<T>::SingleVertexDFSforCycle(int v_id,set<int> vi, unordered_map<int,int> p){
    p.insert({v_id,-1});
    for (auto neighbor : tables[getIndex(v_id)]) {
        int nei_id=neighbor.node_id;
        if(!(vi.find(nei_id)!=vi.end())){
            vi.insert(nei_id);
            p.insert({nei_id,v_id});
            if(SingleVertexDFSforCycle(nei_id,vi,p)){return true;}
        }
        else{
            if(p[nei_id]!=v_id){
                return true;
            }
        }
    }

    return false;
}

template<class T>
bool arrayWGraph<T>::cycle(){//使用dfs判断环路
    vis0=new set<int>();
    p=new unordered_map<int,int>();
    for(set<int> x:connectedSets()){//在每个联通集中查找环路
        int vx_id=*x.begin();//在联通集中取出任意一个节点，若有环则整张图就有环
        if(SingleVertexDFSforCycle(vx_id,vis0,p)){return true;};
    }
    return false;
}

template<class T>
vector<set<int>> arrayWGraph<T>::connectedSets(){// 获取连通集
    vis1 = new int[v_num];
    fill(vis1, vis1 + v_num, 0);
    int a, b;
    b = 0;
    vector<set<int>> con_uni;
    stack<int> sl;//设置待处理区
    set<int> single;//存储单个集合
    con_uni.clear();
    b = 0;
    for (int i = 0; i <v_num; i++) {//此处基本上操作的都是index
        if (vis1[i] == 0) {//如果未访问，入栈进入待处理区
            sl.push(i);
            single.insert(vs_inf[i].node_id);//单个集合里添加id不添加索引
            vis1[i] = 1;
        }
        while (!sl.empty()) {//在待处理区取出元素进行操作
            a = sl.top();//此处a是index不是id
            sl.pop();
            for (int j = 0; j < tables[a].conn_vertices.size(); j++) {
                int re = getIndex(tables[a].conn_vertices[j].node_id);
                if (vis1[re] == 0) {//对待处理区所相连的节点进行遍历访问，若未访问则加入待处理区
                    sl.push(re);
                    single.insert(vs_inf[i].node_id);
                    vis1[re] = 1;
                }
            }
        }
        if (!single.empty()) {//将单个集合加入整体联通集
            con_uni.push_back(single);
            b++;
            single.clear();
        }
    }
    return con_uni;
}

template<class T>
void arrayWGraph<T>::addVertex(NodeInfo N) {
    // 增加节点数量
    v_num++;
    // 为存储节点信息的向量添加新元素，初始化其度等信息
    vs_inf.push_back(N);
    // 为邻接表添加新的顶点结构，初始化其连接向量为空
    tables.push_back(Vertex());
}

template<class T>
void arrayWGraph<T>::deleteVertex(int v_id) {
    // 先获取要删除节点的索引
    int indexTodelete = getIndex(v_id);
    if (indexTodelete == -1) {
        // 如果没找到对应索引，说明节点不存在，输出提示信息并返回
        cout << "要删除的节点不存在，无法执行删除操作！" << endl;
        return;
    }

    // 步骤一：删除与该节点相连的所有边
    for (int i = 0; i < tables[indexTodelete].connect_v.size(); i++) {
        int neighborId = tables[indexTodelete].connect_v[i].node_id;
        int neighborIndex = getIndex(neighborId);
        // 在邻居节点的连接向量中删除指向当前要删除节点的记录
        for (auto it = tables[neighborIndex].connect_v.begin(); it != tables[neighborIndex].connect_v.end(); it++) {
            if ((*it).node_id == indexTodelete) {
                tables[neighborIndex].connect_v.erase(it);
                break;
            }
        }
        // 更新邻居节点的度
        vs_inf[neighborIndex].degree--;
    }

    // 步骤二：从节点信息向量和邻接表中移除该节点
    vs_inf.erase(vs_inf.begin() + indexTodelete);
    tables.erase(tables.begin() + indexTodelete);

    // 更新节点数量和边数量
    v_num--;
    e_num -= tables[indexTodelete].connect_v.size();
}




#endif //DSPROJECT_ARRAYWGRAPH_H
