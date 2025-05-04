/** @file Stack.cpp */
#include "Stack.h"  
#include "string"
#include "iostream"

template<class ItemType>
Stack<ItemType>::Stack(): head(nullptr), length(0)
{
}

template<class ItemType>
Stack<ItemType>::Stack(const ItemType& item): head(nullptr), length(1)
{
    Node<ItemType>* newItem = new Node<ItemType>(item);
    newItem->setNext(head);
    head = newItem;
}

template<class ItemType>
void Stack<ItemType>::push(const ItemType& item)
{

    Node<ItemType>* newItem = new Node<ItemType>(item);
    newItem->setNext(head);
    head = newItem;
    length++;

}

template<class ItemType>
Node<ItemType>* Stack<ItemType>::pop()
{
    Node<ItemType>* rmv = head;
    head = rmv->getNext();
    length--;

    return rmv;
}

template<class ItemType>
void Stack<ItemType>::clear()
{
    while(!isEmpty())
    {
        pop();
    }
}

template<class ItemType>
Node<ItemType>* Stack<ItemType>::peek()
{
    return head;
}

template<class ItemType>
int Stack<ItemType>::size() const
{
    return length;
}

template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
    return length == 0;
}

template<class ItemType>
std::string Stack<ItemType>::toString() const
{

    if (length == 0)
    {
        return "\"\"";
    }

    std::string rString = "\"";
    Node<ItemType>* curPtr = head;

    while (curPtr->getNext() != nullptr)
    {
        rString += curPtr->getItem();

        rString +="\n";
        
        curPtr = curPtr->getNext();
    }
    
    rString += curPtr->getItem() + "\"";
    curPtr = nullptr;
    return rString;
}

template<class ItemType>
Stack<ItemType>::~Stack()
{
    clear();
}
