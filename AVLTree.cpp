//
// Created by RS64 on 03.05.2026.
//

#include "AVLTree.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>


Node::Node(int k) {
    key = k;
    left = nullptr;
    right = nullptr;
    height = 1; // Defaut height = 1
}

AVLTree::AVLTree() {
    root = nullptr;
}



int AVLTree::height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int balance = height(node->left) - height(node->right);
    return balance;
}

Node *AVLTree::rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *AVLTree::leftRotate(Node *x) {
    Node* y = x-> right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* AVLTree::insert(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }
    node->height = std::max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);



    //Left-Left (Перекос наліво, пряма)
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    //Right-Right (Перекос вправо, пряма)
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    //Left-Right (Перекос наліво, утворився зигзаг)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //Right-Left (Перекос вправо, утворився зигзаг)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

void AVLTree::printTree(Node* node, int indent) {
    if (node != nullptr) {
        if (node->right) {
            printTree(node->right, indent + 4);
        }


        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << node->key << "\n";


        if (node->left) {
            printTree(node->left, indent + 4);
        }
    }
}


void AVLTree::display() {
    printTree(root, 0);
}

void AVLTree::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

AVLTree::~AVLTree() {
    clear(root);
}
/* Історична пам'ятка того як я намагався зрозуміти повороти
 * Node* x = y->left;
 * Node* T2 = x->right;
 * x->right = y;
 * y->left = T2;
 *
 *
 * Node* x = y-> right;
 * Node* T2 = x-> left;
 * y->right = x;
 * x->left = T2;
*/

