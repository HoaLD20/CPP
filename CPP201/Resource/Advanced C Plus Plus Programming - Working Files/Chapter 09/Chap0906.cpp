#include <iostream>

using namespace std;

class Node {
    public:
       string data;
       Node *left;
       Node *right;
       Node(string d) {
           data = d;
           left = NULL;
           right = NULL;
       }
};

class BST {
    private:
       Node *root;
       void Insert(string data, Node *aNode);
       Node *Search(string data, Node *aNode);
    public:
       BST();
       void Insert(string data);
       Node *Search(string data);
};

BST::BST() {
    root = NULL;
}

void BST::Insert(string data, Node *aNode) {
    if (data < aNode->data) {
        if (aNode->left != NULL)
           Insert(data, aNode->left);
        else {
            aNode->left = new Node(data);
            aNode->left->left = NULL;
            aNode->left->right = NULL;
        }
    }
    else if (data >= aNode->data) {
        if (aNode->right != NULL) {
            Insert(data, aNode->right);
        }
        else {
            aNode->right = new Node(data);
            aNode->right->left = NULL;
            aNode->right->right = NULL;
        }
    }
}

Node* BST::Search(string data, Node *aNode) {
    if (aNode != NULL) {
        if (data == aNode->data) {
            return aNode;
        }
        if (data < aNode->data) {
            return Search(data, aNode->left);
        }
        else {
            return Search(data, aNode->right);
        }
    }
    else {
        return NULL;
    }
}

void BST::Insert(string data) {
    if (root != NULL) {
        Insert(data, root);
    }
    else {
        root = new Node(data);
        root->left = NULL;
        root->right = NULL;
    }
}

Node* BST::Search(string data) {
    return Search(data, root);
}

int main()
{
    BST *btree = new BST;
    btree->Insert("apple");
    btree->Insert("mango");
    btree->Insert("kiwi");
    Node *found = btree->Search("kiwi");
    cout << found->data;
    return 0;
}
