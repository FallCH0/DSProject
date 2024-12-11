cmake_minimum_required(VERSION 3.27)
project(DSProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(DSProject main.cpp
        graph.h
        edge.h
        vertexIterator.h
        arrayWGraph.h
        node.h
        arrayWGraph_basic.tpp)
