//
// Created by Kathleen Nguyen on 11/26/21.
//

#ifndef CATCHASE_STACK_CPP
#define CATCHASE_STACK_CPP
#include "Stack.h"
template<class T>
Stack<T>::Stack()
{

}

template<class T>
T Stack<T>::pop()
{
    if(empty())
    {
        std::cout << "Error: Empty stack.";
        exit(1);
    }
    T data = list.getItem(1);
    list.deleteNode(1);
    return data;
}

template<class T>
void Stack<T>::push(const T &item)
{
    list.push_front(item);
}

template<class T>
int Stack<T>::size()
{
    return list.getSize();
}

template<class T>
T &Stack<T>::top()
{
    return list.head;
}

template<class T>
T Stack<T>::peek(int n)
{
    return list.getItem(n);
}

template<class T>
bool Stack<T>::empty()
{
    return list.isEmpty();
}


#endif //CATCHASE_STACK_CPP
