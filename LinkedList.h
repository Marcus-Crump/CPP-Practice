/** @file LinkedList.h */
#ifndef _LINKED_LIST
#define _LINKED_LIST
// #include "LinkedList.h"
#include "Node.h"
#include <vector>
#include <string>

template<class ItemType>

class LinkedList
{
private:
Node<ItemType>* head;
// Node::Node tail
int length;

Node<ItemType>* getPtrTo(const ItemType& target) const;

public:
LinkedList();
LinkedList(const LinkedList<ItemType>& aList);
virtual ~LinkedList();
int getSize() const;
bool isEmpty() const;
void add(const ItemType& newEntry);
void insert(const ItemType& newEntry, const int index);
bool remove(const ItemType& entry);
void clear();
bool contains(const ItemType& entry) const;
int getFreqOf(const ItemType& entry) const;
std::vector<ItemType> toVector() const;
std::string toString();
};

#include "LinkedList.cpp"
#endif
