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
bool arrayWGraph<T>::cycle() {//使用dfs判断环路
    vis=new set<int>();
    p=new unordered_map<int,int>();
    for(set<int> x:connectedSets()){//在每个联通集中查找环路
        int vx_id=*x.begin();//在联通集中取出任意一个节点，若有环则整张图就有环
        if(SingleVertexDFSforCycle(vx_id,vis,p)){return true;};
    }
    return false;
}

template<class T>
vector<set<int>> arrayWGraph<T>::connectedSets(){// 获取连通集
    vis = new int[v_num + 1];
    fill(vis, vis + v_num + 1, 0);
    int a, b;
    b = 0;
    vector<set<int>> con_uni;
    stack<int> sl;//设置待处理区
    set<int> single;//存储单个集合
    con_uni.clear();
    b = 0;
    for (int i = 1; i <=v_num; i++) {//此处基本上操作的都是index
        if (vis[i] == 0) {//如果未访问，入栈进入待处理区
            sl.push(i);
            single.insert(vs_inf[i].node_id);//单个集合里添加id不添加索引
            vis[i] = 1;
        }
        while (!sl.empty()) {//在待处理区取出元素进行操作
            a = sl.top();//此处a是index不是id
            sl.pop();
            for (int j = 0; j < tables[a].conn_vertices.size(); j++) {
                int re = getIndex(tables[a].conn_vertices[j].node_id);
                if (vis[re] == 0) {//对待处理区所相连的节点进行遍历访问，若未访问则加入待处理区
                    sl.push(re);
                    single.insert(vs_inf[i].node_id);
                    vis[re] = 1;
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
void arrayWGraph<T>::addVertex() {
    // 增加节点数量
    v_num++;
    // 为存储节点信息的向量添加新元素，初始化其度等信息
    vs_inf.push_back(NodeInfo());
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