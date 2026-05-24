#ifndef AVLTree_HPP
#define AVLTree_HPP

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k);
};

class AVLTree {
private:
    Node* root;
    void clear(Node* node);

    int height(Node* n);
    int getBalance(Node* n);

    Node* insert(Node* node, int key);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);

    void printTree(Node* root, int indent);
public:
    AVLTree();
    ~AVLTree();

    void insert(int key);
    void display();
};

#endif
