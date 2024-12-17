//
// Created by Fall_ on 2024/12/11.
//

#ifndef DSPROJECT_GRAPH_H
#define DSPROJECT_GRAPH_H


#include "edge.h"
#include "vertexIterator.h"

template<class T>
class graph{
public:
    virtual ~graph() {}
    virtual int numberOfVertices() const = 0;//点的个数
    virtual int numberOfEdges() const = 0;//边的个数
    virtual bool existsEdge(int, int) const = 0;//判断是否存在从前面点到后面点的边
    virtual void insertEdge(edge<T>*) = 0;//插入边
    virtual bool eraseEdge(int, int) = 0;//删除边
    virtual int degree(int) const = 0;//度
    virtual bool weighted() const = 0;//权重
    virtual vertexIterator<T>* iterator(int) = 0;//迭代器
};

#endif //DSPROJECT_GRAPH_H
