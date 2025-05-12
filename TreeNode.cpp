/** @file TreeNode.cpp */
#include "TreeNode.h"
#include <cstddef>

template< class ItemType>
TreeNode<ItemType>::TreeNode() : left(nullptr), right(nullptr)
{
} // end default constructor


template< class ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& anItem) : item(anItem), left(nullptr),
                    right(nullptr) 
{
} // end constructor

template< class ItemType>
void TreeNode<ItemType>::setItem(const ItemType& anItem)
{
item = anItem;
} // end setItem


template< class ItemType>
void TreeNode<ItemType>::setLeft(TreeNode<ItemType>* treeNodePtr)
{
left = treeNodePtr;
} // end setleft

template< class ItemType>
void TreeNode<ItemType>::setRight(TreeNode<ItemType>* treeNodePtr)
{
right = treeNodePtr;
} // end setright


template< class ItemType>
ItemType TreeNode<ItemType>::getItem() const
{
return item;
} // end getItem


template< class ItemType>
TreeNode<ItemType>* TreeNode<ItemType>::getLeft() const
{
return left;
} // end getleft

template< class ItemType>
TreeNode<ItemType>* TreeNode<ItemType>::getRight() const
{
return right;
} // end getright