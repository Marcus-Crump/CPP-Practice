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
    if (tail == nullptr)
    {
        tail = newNodePointer;
        head->setNext(newNodePointer);

    }else
    {
        Node<ItemType>* n = head->getNext();
        n->setPrev(newNodePointer);
        head->setNext(newNodePointer);
    }
    length++;

}

template<class ItemType>
Node<ItemType>* Queue<ItemType>::peek()
{
    return head->getNext();
}

template<class ItemType>
Node<ItemType>* Queue<ItemType>::dequeue()
{
    if(tail == 0)
    {
        return nullptr;
    }
    Node<ItemType>* del = tail;
    tail = del->getPrev();
    length--;
    return del;
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
void Queue<ItemType>::clear()
{
    tail = nullptr;
    while (head->getNext() != nullptr)
    {
        Node<ItemType>* del = head->getNext();
        head->setNext(del->getNext());
        delete del;
        del = nullptr;
    }
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