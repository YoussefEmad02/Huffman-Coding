#include <iostream>
#include "BinarySearchTreeHeader.h"
using namespace std;

void BinarySearchTree:: inorderTraversal(Node* node) {
    if(node != nullptr) {
        inorderTraversal(node->left);
        cout <<node->ch << " " << node->freq << endl;
        inorderTraversal(node->right);
    }
}

BinarySearchTree :: BinarySearchTree() {
    root = nullptr;
}

void BinarySearchTree:: insert(char data) {
    Node* newNode = new Node(data);

    if(root == nullptr) {
        root = newNode;
    }
    else {
        Node* current = root;
        Node* parent = nullptr;

        while(current != nullptr) {
            parent = current;

            if(newNode->ch < current->ch) {
                current = current->left;
            }
            else if(newNode->ch > current->ch) {
                current = current->right;
            }
            else { // if the value already exists, increment the freq and return
                current->freq++;
                delete newNode; // delete the unused node
                return;
            }
        }

        if(newNode->ch < parent->ch) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }
}


void BinarySearchTree::inorderTraversal() {
    inorderTraversal(root);
}
