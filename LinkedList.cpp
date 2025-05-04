/** @file LinkedList.cpp */
#include "LinkedList.h"
#include <cstddef>
#include "Node.h"
#include <iostream>
#include <string>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : head(nullptr), length(0)
{
}

template<class ItemType>
void LinkedList<ItemType>::add(const ItemType& newEntry)
{
Node<ItemType>* newNodePtr = new Node<ItemType>();
newNodePtr->setItem(newEntry);
newNodePtr->setNext(head);
head = newNodePtr;
length++;
}

template<class ItemType>
void LinkedList<ItemType>::insert(const ItemType& newEntry, const int index)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>();
    newNodePtr->setItem(newEntry);
    Node<ItemType>* curPtr = head;

    for(int i = 0; i < index; i++)
    {
        curPtr = curPtr->getNext();
    }

    newNodePtr->setNext(curPtr->getNext());
    curPtr->setNext(newNodePtr);

    length++;
}

template<class ItemType>
void LinkedList<ItemType>::clear()
{
    Node<ItemType>* temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->getNext();

        temp->setNext(nullptr);
        delete temp;
    }
    
    temp = nullptr;
    length = 0;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return length == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getSize() const
{
    return length;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getPtrTo(const ItemType& target) const
{
    bool found = false;
    Node<ItemType>* curPtr = head;
    while (!found && (curPtr != nullptr))
    {
        if(target == curPtr->getItem())
        {
            found = true;
        }
        else
        {
            curPtr = curPtr->getNext;
        }
    }
    return curPtr;
}

template<class ItemType>
int LinkedList<ItemType>::getFreqOf(const ItemType& anEntry) const
{
    int freq = 0;
    int counter = 0;
    Node<ItemType>* curPtr = head;
    while ((curPtr != nullptr) && (counter < length))
    {
        if (anEntry == curPtr->getItem())
        {
            freq++;
        }
        counter++;
        curPtr = curPtr->getNext();
    }

    return freq;
}

template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType& entry) const
{
    return (getPtrTo(entry) != nullptr);
}

template<class ItemType>
bool LinkedList<ItemType>::remove(const ItemType& entry)
{
    Node<ItemType>* entryNodePtr = getPtrTo(entry);
    bool canRemove = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemove)
    {
        entryNodePtr->setItem(head->getItem());
        Node<ItemType>* nodeToDel = head;
        head = head->getNext();

        nodeToDel->setNext(nullptr);
        delete nodeToDel;
        
        length--;
    }
    return canRemove;
}

template<class ItemType>
std::string LinkedList<ItemType>::toString()
{
    std::string rString = "[";
    Node<ItemType>* curPtr = head;

    while (curPtr != nullptr)
    {
        rString+=curPtr->getItem();
        if (curPtr->getNext() != nullptr)
        {
            rString += "->";
        }

        curPtr = curPtr->getNext();
        
    }
    curPtr = nullptr;
    rString += "]";

    return rString;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}
