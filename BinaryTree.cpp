/** @file BinaryTree.cpp */
#include "BinaryTree.h"
#include "Queue\Queue.h"


template<class ItemType>
BinaryTree<ItemType>::BinaryTree(): root(nullptr)
{
}

template<class ItemType>
BinaryTree<ItemType>::BinaryTree(ItemType& rootItem): 
                        root(new TreeNode<ItemType>(rootItem))
{
}

template<class ItemType>
TreeNode<ItemType>* BinaryTree<ItemType>::get_leaf()
{
    if(root == nullptr)
    {
        return nullptr;
    }

    Queue<ItemType>* q = new Queue<ItemType>();
    TreeNode<ItemType>* cur = root;

    while (cur->getLeft() != nullptr && cur->getRight() != nullptr)
    {
        q->enqueue(cur->getLeft());
        q->enqueue(cur->getRight());
        cur = q->dequeue();
    }

    if (cur->getLeft() == nullptr)
    {
        return cur->getRight();
    }
    else if (cur->getRight() == nullptr)
    {
        return cur->getLeft();
    }

    return cur;

}

template<class ItemType>
void BinaryTree<ItemType>::add(ItemType& item)
{
    TreeNode<ItemType>* newNode = new TreeNode<ItemType>(item);
    if(root ==  nullptr)
    {

    }else
    {
        TreeNode<ItemType>* cur = root;
        Queue<ItemType>* q = new Queue<ItemType>();

        while (cur->getLeft() != nullptr && cur->getRight() != nullptr)
        {
            q->enqueue(cur->getLeft());
            q->enqueue(cur->getRight());

            cur = q->dequeue();

        }

        if(q->length() != 0)
        {
            newNode->setParent(cur)
        }
        
        if(cur->getLeft() == nullptr)
        {
            //new left node
            cur->setLeft(newNode);

        } else
        {
            //new right node
            cur->setRight(newNode);
        }

        q->~Queue();
    }
}

template<class ItemType>
bool BinaryTree<ItemType>::remove(ItemType& item) const
{
    if (root == nullptr)
    {
        return false;
    }
    
    TreeNode<ItemType>* cur;
    TreeNode<ItemType>* temp;
    TreeNode<ItemType>* del;

    Queue<ItemType>* q = new Queue<ItemType>();
    q->enqueue(root);
    
    while (q->length() != 0)
    {
        cur = q->dequeue();

        if(cur->getLeft()->getItem() == item)
        {
            temp = get_leaf();
            del = cur->getLeft();
            temp->setParent(cur);
            temp->setLeft(del->getLeft());
            temp->setRight(del->getRight());
        }
        else if (cur->getRight()->getItem() == item)
        {
            temp = get_leaf();
            del = cur->getRight();
            temp->setParent(cur);
            temp->setLeft(del->getLeft());
            temp->setRight(del->getRight());
        }
        

        q->enqueue(cur->getLeft());
        q->enqueue(cur->getRight());
    }
    return false;
}