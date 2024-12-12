//
// Created by Fall_ on 2024/12/12.
//


#include "arrayWGraph.h"

// 构造函数，接受初始节点个数作为参数
template<class T>
arrayWGraph<T>::arrayWGraph(int v_numx){
    // 检查初始化参数是否合法
    while(true){
        if(v_numx < 0){
            cout << "请输入正确的节点数！继续：" << endl << "> ";
            cin >> v_numx;
        }else{
            break;
        }
    }
    // 初始化图的属性
    v_num = v_numx;
    e_num = 0;
    vs_inf = vector<NodeInfo>(v_num + 1); // 注：下标从1开始
    tables = vector<Vertex>{ (v_num+ 1), Vertex() };
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
        if (tables[v1_index].conn_vertices[i].node_id == v2_id){
            a=true;
        }
    }
    for (int i = 0; i < v2c_num ; i++){
        if (tables[v2_index].conn_vertices[i].node_id == v1_id){
            b=true;
        }
    }
    return a&&b;//无向图，双向检查
}


// 根据NodeInfo的node_id编号获取ins_f<NodeInfo>中对应的索引（即对应到ins_f的存储结构），主要用途可以是访问
template<class T>
int arrayWGraph<T>::getIndex(int x) {
    for (int i = 1; i <= v_num; i++){
        if (tables[i].node_id == x){
            return i;
        }
    }
}

template<class T>//用于实现插入边的插入单向边（非完整模块）
void arrayWGraph<T>::insertEdgeSingle(int v1_id,int v2_id,T w){
    int v1_index= getIndex(v1_id);
    Node<T> V2X(v2_id,w);
    tables[v1_index].connect_v.add(V2X);
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
    for(auto i=tables[v1_index].begin();i!=tables[v1_index].end();i++){
        if((*i).node_id==v2_id){
            tables[v1_index].conn_vertices.erase(i);
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
bool arrayWGraph<T>::cycle() {
    queue<NodeInfo> q;
    while(!q.empty()){

    }
}