// Name: Alexis Martinez
// Date: 11/10/2023
// Description: Header file for class bTree

#ifndef B_TREE_H
#define B_TREE_H
#include <iostream> //For cout
using namespace std;

template<typename T>
class bTree {
private:
    //Node 
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T data) {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
    };
    // node pointer
    Node* root;
    //private functions
    Node* insertNode(Node* root, T data);
    Node* deleteNode(Node* root, T data);
    Node* findMin(Node* node);
    int countNodes(Node* root);
    Node* search(Node* root, T data);
    void preOrderTraversal(Node* root);
    void inOrderTraversal(Node* root);
    void postOrderTraversal(Node* root);
    void eraseTree(Node* root);

public:
    //default constructor
    bTree();
    //fucntions
    bool isEmpty() const;

    void insert(T data);

    void remove(T data);

    int count();

    bool find(T data);

    void preOrder();

    void inOrder();

    void postOrder();

    void deleteTree();
};

#include "bTree.template"
#endif
//private functions 
template<typename T>
typename bTree<T>::Node* bTree<T>::insertNode(Node* root, T data);

template<typename T>
typename bTree<T>::Node* bTree<T>::findMin(Node* node);


template<typename T>
typename bTree<T>::Node* bTree<T>::deleteNode(Node* root, T data);

template<typename T>
int bTree<T>::countNodes(Node* root);

template<typename T>
typename bTree<T>::Node* bTree<T>::search(Node* root, T data);

template<typename T>
void bTree<T>::preOrderTraversal(Node* root);

template<typename T>
void bTree<T>::inOrderTraversal(Node* root);

template<typename T>
void bTree<T>::postOrderTraversal(Node* root);

template<typename T>
void bTree<T>::eraseTree(Node* root);
