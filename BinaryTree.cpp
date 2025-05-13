/** @file BinaryTree.cpp */
#include "BinaryTree.h"
#include "vector"

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
void BinaryTree<ItemType>::add(ItemType& item)
{
    TreeNode<ItemType>* cur = root;
    while (cur->getLeft() != nullptr && cur->getRight() != nullptr)
    {
        stack->push_back(cur->getRight());
        stack->push_back(cur->getLeft());

    }
    
}