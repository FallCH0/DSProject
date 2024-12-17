//
// Created by Fall_ on 2024/12/12.
//
//定义edge类
#ifndef DSPROJECT_EDGE_H
#define DSPROJECT_EDGE_H
#include<iostream>
using namespace std;
template<class T>
class edge {//定义边
    int v1;
    int v2;
    T w;//两个顶点和权值
public:
    edge(int V1X = -1, int V2X= -1, double WX = 0) { v1 = V1X; v2 =V2X; w=WX; }//默认构造函数传递三个参数
    ~edge() {}
    // 获取三项私有数据的方法
    int get_v1() { return v1; }
    int get_v2() { return v2; }
    double get_w() { return w; }
    // 标准输出edge的信息
    void output() { cout << "(" << v1 << "," << v2 << "," << w << ")"; }
};


#endif //DSPROJECT_EDGE_H
