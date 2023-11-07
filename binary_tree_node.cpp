// Name: prof Q
// Date: 11-3-2021
// Description: cpp file for binary tree node for growing a tree
// documentation: Vivian

#include "binary_tree_node.h"

//---------------------------------------------------------------------
//							CONSTRUCTORS
//---------------------------------------------------------------------
//Precondition : N/A
//Postcondition: Initialize the private members
template <class Item>
binary_tree_node<Item>::binary_tree_node()
{
    const Item& init_data = Item();
    binary_tree_node* init_left = NULL;
    binary_tree_node* init_right = NULL;
}
//Precondition : Passing in the private members
//Postcondition: Change the private members
template <class Item>
binary_tree_node<Item>::binary_tree_node(const Item& init_data, binary_tree_node* init_left, binary_tree_node* init_right)
{
    data = init_data;
    left = init_left;
    right = init_right;
}

//---------------------------------------------------------------------
//							ACCESSORS
//---------------------------------------------------------------------
//Precondition : N/A
//Postcondition: Return private member data
template <class Item>
Item& binary_tree_node<Item>::getData()
{
    return data;
}
//Precondition : N/A
//Postcondition: Return private member left
template <class Item>
binary_tree_node<Item>*& binary_tree_node<Item>::getLeft()
{
    return left;
}
//Precondition : N/A
//Postcondition: Return private member right
template <class Item>
binary_tree_node<Item>*& binary_tree_node<Item>::getRight()
{
    return right;
}
//Precondition : N/A
//Postcondition: Return const private member data 
template <class Item>
const Item& binary_tree_node<Item>::getData() const
{
    return data;
}
//Precondition : N/A
//Postcondition: Return const private member left 
template <class Item>
const binary_tree_node<Item>* binary_tree_node<Item>::getLeft() const
{
    return left;
}
//Precondition : N/A
//Postcondition: Return const private member right  
template <class Item>
const binary_tree_node<Item>* binary_tree_node<Item>::getRight() const
{
    return right;
}
//Precondition : N/A
//Postcondition: Return left and right NULL
template <class Item>
bool binary_tree_node<Item>::isLeaf() const
{
    return (left == NULL && right == NULL);
}

//---------------------------------------------------------------------
//							MUTATORS
//---------------------------------------------------------------------
//Precondition : Passing in a valid data type
//Postcondition: Change the private member data
template <class Item>
void binary_tree_node<Item>::setData(const Item& new_data)
{
    data = new_data;
}
//Precondition : Passing in the new class object
//Postcondition: Changing the private member left
template <class Item>
void binary_tree_node<Item>::setLeft(binary_tree_node* new_left)
{
    left = new_left;
}
//Precondition : Passing in the new class object
//Postcondition: Changing the private member right
template <class Item>
void binary_tree_node<Item>::setRight(binary_tree_node* new_right)
{
    right = new_right;
}


//Precondition : Passing in template class leaf
//Postcondition: Delete all the nodes
template<class Item>
void delete_tree(binary_tree_node<Item>* leaf) // Recursive
{
    if (leaf == NULL)
        return;

    /* first delete both subtrees */
    delete_tree(leaf->getLeft());
    delete_tree(leaf->getRight());

    /* then delete the node */
    cout << "\n\t\tDeleting: " << leaf->getData();
    delete leaf;

}
//Precondition : Passing in valid parameters
//Postcondition: Display the entire tree
template<class Item>
void print_tree(const string& prefix, const binary_tree_node<Item>* node, bool isLeft, bool root, bool last)
{
    if (node != NULL)
    {
        cout << prefix;
        if (!root)
        {
            if (isLeft)
            {
                if (node->getLeft() == NULL && node->getRight() == NULL)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            else
            {
                if (last)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            cout << " " << node->getData() << '\n';
        }
        else
            cout << "    " << node->getData() << '\n';


        // enter the next tree level - left and right branch
        string s = "    ";
        s[0] = char(179);
        print_tree(prefix + (isLeft ? s : "    "), node->getLeft(), true, false, false);
        print_tree(prefix + (isLeft ? s : "    "), node->getRight(), false, false, true);
    }
}