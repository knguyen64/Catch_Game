//
// Created by Kathleen Nguyen on 11/26/21.
//

#ifndef CATCHASE_STACK_H
#define CATCHASE_STACK_H
#include "LinkedList.h"

template <class T>
class Stack
{
private:
    LinkedList<T> list;
public:
    Stack();

    T pop();
    void push(const T& item);
    bool empty();
    int size();
    T& top();
    T peek(int n);
};

#include "Stack.cpp"
#endif //CATCHASE_STACK_H
