//
// Created by Fall_ on 2024/12/12.
//

#ifndef DSPROJECT_VERTEXITERATOR_H
#define DSPROJECT_VERTEXITERATOR_H

using namespace std;
template<class T>
class vertexIterator{
public:
    virtual ~vertexIterator() {}
    virtual int next() = 0;
    virtual int next(T&) = 0;

};
#endif //DSPROJECT_VERTEXITERATOR_H
