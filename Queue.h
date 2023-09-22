//
// Created by Kathleen Nguyen on 11/26/21.
//

#ifndef CATCHASE_QUEUE_H
#define CATCHASE_QUEUE_H
#include "LinkedList.h"
template <class T>
class Queue {
private:
    LinkedList<T> list;
public:
    T& pop();
    void push(const T& item);
    bool empty();
    int size();
    T& front();
    T& getItem(int i);
};
#include "Queue.cpp"
#endif //CATCHASE_QUEUE_H
