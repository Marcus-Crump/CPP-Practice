/** @file Queue.h */
#ifndef _QUEUE
#define _QUEUE
#include "Node.h"
#include "string"

template<class ItemType>
class Queue
{
    private:
    Node<ItemType>* head;
    Node<ItemType>* tail;
    int length;


    public:
    Queue();

    ~Queue();

    void enqueue(const ItemType& item);

    Node<ItemType>* peek();

    Node<ItemType>* dequeue();

    void clear();

    bool is_empty();

    int size() const;

    std::string to_string();
};

#include "Queue.cpp"
#endif