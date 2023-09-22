//
// Created by Kathleen Nguyen on 11/20/21.
//

#ifndef CATCHASE_LINKEDLIST_CPP
#define CATCHASE_LINKEDLIST_CPP
#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList()
{

}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& oldList) : LinkedList()
{
    if(oldList.head == nullptr)
        head = nullptr;
    else
    {
        Node<T>* temp = oldList.head;
        while(temp != nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* temp = head;
    while(temp != nullptr)
    {
        Node<T>* next = temp->next;
        delete temp;
        temp = next;
    }
}



template<class T>
Node<T>* LinkedList<T>::createNode(T item)
{
    Node<T>* n = new Node<T>;
    n->data = item;
    n->next = nullptr;
    return n;
}

template<class T>
void LinkedList<T>::push_front(T item)
{
    if(head == nullptr)
        addFirstNode(item);
    else
    {
        Node<T>* n = createNode(item);
        n->next = head;
        head = n;
    }
}

template<class T>
void LinkedList<T>::push_back(T item)
{
    if(head == nullptr)
        addFirstNode(item);
    else {
        Node<T>* n = createNode(item);
        tail->next = n;
        tail = n;
    }
}

template<class T>
void LinkedList<T>::addFirstNode(T item)
{
    Node<T>* n = createNode(item);
    head = n;
    tail = n;
}

template<class T>
void LinkedList<T>::insertBefore(T newItem, T item)
{
    if(head == nullptr)
        addFirstNode(item);
    else
    {
        Node<T>* temp = head;
        Node<T>* newNode = createNode(newItem);
        while(temp->next != findItem(item) && temp != nullptr)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

template<class T>
void LinkedList<T>::insertAfter(T newItem, T item)
{
    Node<T>* temp = head;
    Node<T>* newNode = createNode(newItem);

    if(head == nullptr)
        addFirstNode(item);
    else
    {
        while(temp != findItem(item) && temp != nullptr)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    if(newNode->next == nullptr)
        tail = newNode;
}

template<class T>
void LinkedList<T>::deleteItem(T item)
{
    Node<T>* temp = head;
    if (head->data == item)
    {
        head = head->next;
    }
    else if(tail->data == item)
    {
        while(temp->next != tail && temp->next != nullptr)
            temp = temp->next;
        tail = temp;
        tail->next = nullptr;
    }
    else
    {
        while(temp->next != findItem(item) && temp->next != nullptr)
            temp = temp->next;
        temp->next = findItem(item)->next;
    }
}

template<class T>
void LinkedList<T>::deleteNode(int n)
{
    Node<T>* temp = head;
    if(n == 1)
    {
        head = head->next;
    } else if(n == getSize())
    {
        while(temp->next != tail && temp->next != nullptr)
            temp = temp->next;
        tail = temp;
        tail->next = nullptr;
    }
    else
    {
        for(int i=0; i < n-1 && temp->next != nullptr; i++)
            temp = temp->next;
        if(temp->next->next != nullptr)
            temp->next = temp->next->next;
        else
            temp->next = nullptr;
    }
}

template<class T>
Node<T>* LinkedList<T>::findItem(T item)
{
    Node<T>* temp = head;
    while(temp != nullptr)
    {
        if(temp->data == item)
            return temp;
        temp = temp->next;
    }
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    if(head == nullptr)
        return true;
    return false;
}

template<class T>
T& LinkedList<T>::getItem(int i)
{
    Node<T>* temp = head;
    for(int j=0; temp->next != nullptr && j < i; i--)
        temp = temp->next;
    return temp->data;
}

template<class T>
int LinkedList<T>::getSize()
{
    Node<T>* temp = head;
    int size = 0;
    while(temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

template<class T>
void LinkedList<T>::operator+=(const T item)
{
    push_back(item);
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
    LinkedList<T> tempList(rhs);
    Node<T>* tempNode = tempList.head;
    while(tempNode != nullptr)
    {
        push_back(tempNode->data);
        tempNode = tempNode->next;
    }
    return *this;
}

template<class S>
std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list)
{
    Node<S>* temp = list.head;
    while(temp != nullptr)
    {
        out << temp->data;
        temp = temp->next;
    }
    return out;
}
#endif //CATCHASE_LINKEDLIST_CPP