/** @file Queue.cpp */
#include "Queue.h"
#include "string"
#include "iostream"

template<class ItemType>
Queue<ItemType>::Queue(): head(new Node<ItemType>()), tail(nullptr), length(0)
{
}

template<class ItemType>
void Queue<ItemType>::enqueue(const ItemType& item)
{
        Node<ItemType>* newNodePointer = new Node<ItemType>(item, head->getNext());
    if (length == 0)
    {
        talil = newNodePointer;
        head->setNext(newNodePointer);

    }else
    {
        Node<ItemType>* last = head->getNext();
        
        head->setNext(newNodePointer);
    }
}

template<class ItemType>
Node<ItemType> Queue<ItemType>::peek()
{
    return head->getNext();
}

template<class ItemType>
Node<ItemType> Queue<ItemType>::dequeue()
{
    Node<ItemType>* del = tail;
    tail = del->getNext();
    return del;
}

template<class ItemType>
void Queue<ItemType>::clear()
{
    while (head->getNext() != nullptr)
    {
        Node<ItemType> del = head->getNext();
        head->setNext(del->getNext());
        delete del;
        del = nullptr;
    }
}

template<class ItemType>
bool Queue<ItemType>::is_empty()
{
    return length == 0;
}

template<class ItemType>
int Queue<ItemType>::size() const
{
    return length;
}

template<class ItemType>
std::string Queue<ItemType>::to_string()
{
    std::string rString ="[";
    Node<ItemType>* cur = head->getNext();
    while (cur != nullptr)
    {
        rString += cur->getItem();

        if (cur->getNext() != nullptr)
        {
            rString += "->";
        }
        
        cur = cur->getNext();
    }

    rString += "]";

    return rString;
}

template<class ItemType>
Queue<ItemType>::~Queue()
{
        clear();
}