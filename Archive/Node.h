//
// Created by Kathleen Nguyen on 11/20/21.
//

#ifndef CATCHASE_NODE_H
#define CATCHASE_NODE_H
#include <iostream>

template<class T>
struct Node
{
    T data;
    Node<T>* next = nullptr;
    Node() : data(data){

    }
};

#endif //CATCHASE_NODE_H
