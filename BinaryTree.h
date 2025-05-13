/** @file BinaryTree.h */
#ifndef _BINARYTREE
#define _BINARYTREE
#include "TreeNode.h"

template<class ItemType>
class BinaryTree
{
    private:
    TreeNode<ItemType>* root;
    int num_nodes;

    public:
    BinaryTree();
    BinaryTree(ItemType& rootItem);
    ~BinaryTree();
    void add(ItemType& item);
    bool remove(ItemType& item) const;
    int size() const;
    void clear();
};

#include "BinaryTree.cpp"
#endif