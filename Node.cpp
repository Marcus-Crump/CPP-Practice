/** @file Node.cpp */
#include "Node.h"
#include <cstddef>

template< class ItemType>
Node<ItemType>::Node() : next(nullptr), prev(nullptr)
{
} // end default constructor


template< class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr),
                    prev(nullptr) 
{
} // end constructor


template< class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
item(anItem), next(nextNodePtr), prev(nullptr)
{
} // end constructor


template< class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
item = anItem;
} // end setItem


template< class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nodePtr)
{
next = nodePtr;
} // end setNext

template< class ItemType>
void Node<ItemType>::setPrev(Node<ItemType>* nodePtr)
{
prev = nodePtr;
} // end setPrev


template< class ItemType>
ItemType Node<ItemType>::getItem() const
{
return item;
} // end getItem


template< class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
return next;
} // end getNext

template< class ItemType>
Node<ItemType>* Node<ItemType>::getPrev() const
{
return prev;
} // end getPrev