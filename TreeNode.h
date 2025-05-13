/** @file TreeNode.h */
#ifndef _TREENODE
#define _TREENODE

template< class ItemType>
class TreeNode
{
private:
ItemType item; // A data item
TreeNode<ItemType>* parent;
TreeNode<ItemType>* left; // Pointer to next Treenode
TreeNode<ItemType>* right; // Pointer to prev Treenode


public :
TreeNode();

TreeNode(const ItemType& anItem);

void setItem(const ItemType& anItem);

void setLeft(TreeNode<ItemType>* nextTreeNodePtr);

void setRight(TreeNode<ItemType>* nextTreeNodePtr);

void setParent(TreeNode<ItemType>* parentNode);

ItemType getItem() const ;

TreeNode<ItemType>* getLeft() const ;

TreeNode<ItemType>* getRight() const ;

TreeNode<ItemType>* getParent() const;

}; // end TreeNode

#include "TreeNode.cpp"
#endif