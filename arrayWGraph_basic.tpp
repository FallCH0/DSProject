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
    tables = vector<NodeInfo>(v_num + 1); // 注：下标从1开始
    vs_inf = vector<Vertex>{ (v_num+ 1), Vertex() };
}


// 根据NodeInfo的node_id编号获取V<NodeInfo>中对应的索引（即对应到V的存储结构），主要用途可以是访问
template<class T>//潜在优化：二分查找
int arrayWGraph<T>::getIndex(int x) {
    for (int i = 1; i <= v_num; i++){
        if (tables[i].node_id == x){
            return i;
        }
    }
}

//判断两个节点之间是否有边
template<class T>
bool arrayWGraph<T>::existsEdge(int v1_id, int v2_id) const {
    int c = tables[v1_id].connect_v.size();
    for (int i = 0; i < c; i++){
        if (tables[v1_id].conn_vertices[i].node_id == v2_id){
            return true;
        }
    }
    return false;
}

//
template<class T>
