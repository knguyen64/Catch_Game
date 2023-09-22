//
// Created by Kathleen Nguyen on 11/26/21.
//
#ifndef CATCHASE_QUEUE_CPP
#define CATCHASE_QUEUE_CPP
#include "Queue.h"

template<class T>
T& Queue<T>::pop() {
    if(empty())
    {
        std::cout << "Error: Empty Queue.";
        exit(1);
    }
    T data = list.getItem(0);
    list.deleteNode(1);
    return data;
}

template<class T>
void Queue<T>::push(const T &item)
{
    list.push_back(item);
}

template<class T>
bool Queue<T>::empty()
{
    return list.isEmpty();
}

template<class T>
int Queue<T>::size()
{
    return list.getSize();
}

template<class T>
T& Queue<T>::front()
{
    return list.getItem(1);
}

template<class T>
T &Queue<T>::getItem(int i)
{
    return list.getItem(i);
}

#endif //CATCHASE_QUEUE_CPP