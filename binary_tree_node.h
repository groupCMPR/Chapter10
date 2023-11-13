// Name: prof Q
// Date: 11-3-2021
// Description: binary tree node for growing a tree
// documentation: Vivian

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H
#include <iostream>
#include <string>

using namespace std;

template <class Item>
class binary_tree_node
{
private:
    Item data;
    binary_tree_node* left;
    binary_tree_node* right;

public:

    //constructor
    binary_tree_node(const Item&, binary_tree_node*, binary_tree_node*); //argument

    //accessors
    Item& getData();
    binary_tree_node*& getLeft();
    binary_tree_node*& getRight();
    const Item& getData() const;
    const binary_tree_node* getLeft() const;
    const binary_tree_node* getRight() const;
    bool isLeaf() const;

    //mutators
    void setData(const Item& new_data);
    void setLeft(binary_tree_node* new_left);
    void setRight(binary_tree_node* new_right);
};

#include "binary_tree_node.template"
#endif
template<class Item>
void delete_tree(binary_tree_node<Item>* leaf);

template<class Item>
void print_tree(const string& prefix, const binary_tree_node<Item>* node, bool isLeft, bool root, bool last);



