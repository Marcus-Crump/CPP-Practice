/** @file Stack.h */
#ifndef _STACK
#define _STACK
#include "Node.h"
#include "string"

template<class ItemType>
class Stack
{

    private:
        Node<ItemType>* head;
        int length;

    public:
    Stack();

    Stack(const ItemType& item);

    virtual ~Stack();

    void push(const ItemType& item);

    Node<ItemType>* pop();

    void clear();

    Node<ItemType>* peek(); 

    int size() const;

    bool isEmpty() const;

    std::string toString() const;

};

#include "Stack.cpp"
#endif