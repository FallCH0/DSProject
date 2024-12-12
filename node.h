//
// Created by Fall_ on 2024/12/12.
//

#ifndef DSPROJECT_NODE_H
#define DSPROJECT_NODE_H


#include<iostream>
#include <utility>
using namespace std;

template<class T>
class Node {
public:
    int node_id; // 该点的编号
    T node_weight; // 权值，作为连接到此点的边权值

    Node(int num, int we=0) {
        node_id = num;
        node_weight = we;
    }

    int getn() {return node_id;}
    int getw() {return node_weight;}
    // 重载==运算符（即比较规则，编号相同的节点即为同一节点）
    bool operator==(int y) {
        if (y == this->node_id) return true;
        else return false;
    }
};
/*为什么要对节点的信息进行单独存储？
 因为在使用邻接数构建图中过程中，上边的node更多的是代表连接（边）的关系，故会出现weight属性从而以点+边的方式存到
 每一个节点的邻接表中，而下边的更注重节点本身信息，通过信息来访问图之间的关系
 */
class NodeInfo {
public:
    int node_id; // 节点编号
    int degree; // 该点的度
    string name; // 含义

    NodeInfo(int nodeinfo_id = 0, string nodeinfo_name = "", int nodeinfo_degree = 0 ){
        name = std::move(nodeinfo_name); // 使用移动语义优化
        node_id = nodeinfo_id;
        degree = nodeinfo_degree;
    }
};


#endif //DSPROJECT_NODE_H
