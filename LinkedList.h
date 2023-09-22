//
// Created by Kathleen Nguyen on 11/20/21.
//

#ifndef CATCHASE_LINKEDLIST_H
#define CATCHASE_LINKEDLIST_H
#include <iostream>
#include "Node.h"

template<class T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    void addFirstNode(T item);
    Node<T>* createNode(T item);

public:
    ////Constructors and Destructor
    LinkedList();
    LinkedList(const LinkedList<T>& oldList);
    ~LinkedList();

    void push_front(T item);
    void push_back(T item);
    void insertBefore(T newItem, T item);
    void insertAfter(T newItem, T item);
    void deleteItem(T newItem);
    void deleteNode(int n);
    T& getItem(int i);
    Node<T>* findItem(T item);
    bool isEmpty();
    int getSize();

    ////Overloaded Operators
    template<class S>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list);
    void operator+=(const T item);
    LinkedList<T>& operator=(const LinkedList<T>& rhs);

};

#include "LinkedList.cpp"
#endif //CATCHASE_LINKEDLIST_H