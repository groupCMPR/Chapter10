#pragma once
#include <iostream>
using namespace std;

template<typename T>
class bTree {
private:
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

    Node* root;
    Node* insertNode(Node* root, T data);
    Node* deleteNode(Node* root, T data);
    int countNodes(Node* root);
    Node* search(Node* root, T data);
    void preOrderTraversal(Node* root);
    void inOrderTraversal(Node* root);
    void postOrderTraversal(Node* root);
    void eraseTree(Node* root);

public:

    bTree() {
        root = nullptr;
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    void insert(T data) {
        root = insertNode(root, data);
    }

    void remove(T data) {
        root = deleteNode(root, data);
    }

    int count() {
        return countNodes(root);
    }

    bool find(T data) {
        return search(root, data) != nullptr;
    }

    void preOrder() {
        preOrderTraversal(root);
    }

    void inOrder() {
        inOrderTraversal(root);
    }

    void postOrder() {
        postOrderTraversal(root);
    }

    void deleteTree() {
        eraseTree(root);
        root = nullptr;
    }
};

template<typename T>
typename bTree<T>::Node* bTree<T>::insertNode(Node* root, T data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

template<typename T>
typename bTree<T>::Node* bTree<T>::deleteNode(Node* root, T data) {
    if (root == nullptr) 
        return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
    }

    return root;
}

template<typename T>
int bTree<T>::countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

template<typename T>
typename bTree<T>::Node* bTree<T>::search(Node* root, T data) {
    if (root == nullptr || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

template<typename T>
void bTree<T>::preOrderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << "\n";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

template<typename T>
void bTree<T>::inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << "\n";
        inOrderTraversal(root->right);
    }
}

template<typename T>
void bTree<T>::postOrderTraversal(Node* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << "\n";
    }
}

template<typename T>
void bTree<T>::eraseTree(Node* root) {
    if (root != nullptr) {
        eraseTree(root->left);
        eraseTree(root->right);
        delete root;
    }
}