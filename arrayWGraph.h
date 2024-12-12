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


    /// arrayWGraph基础，包含基类函数、迭代器和实用子方法（实现于arrayWGraph_basic.tpp）
    // 基类函数实现
    explicit arrayWGraph(int v_numx);
    ~arrayWGraph(){};
    int numberOfVertices() const {return v_num;}; // 获取点的个数
    int numberOfEdges() const {return e_num;}; // 获取边的个数
    bool existsEdge(int vertex1_id, int vertex2_id) const; // 判断两条边是否直接相连
    void insertEdge(edge<T>* Edge); // 插入边
    bool eraseEdge(int v1, int v2); // 删除边
    int degree(int v) const {return tables[v].degree;}; // 获取度
    bool directed()  const { return false; }; // 是否为有向图
    bool weighted()  const { return true; }; // 是否为有权图
    bool cycle();//判断是否存在环路



    ///一些其他函数
    int getIndex(int x); // 获取编号为x的点的索引
    bool isnoerrorsingleconnect();//检测有无异常单向连接（邻接数组只存了一边）
    void insertEdgeSingle(int v1_id, int v2_id,T w);//单边插入（为正常插入做准备）
    void eraseEdgeSingle(int v1_id, int v2_id);//单边删除，作用同上

};


#endif //DSPROJECT_ARRAYWGRAPH_H
