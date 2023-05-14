#include <iostream>
#include "BinarySearchTreeHeader.h"
#include "string"
#include "Queue.h"
using namespace std;

void BinarySearchTree:: inorderTraversal(BSTNode* node) {
    if(node != nullptr) {
        inorderTraversal(node->left);

       //cout <<node->ch << " " << node->freq << endl;
        pq.enqueue(node);
        inorderTraversal(node->right);
        //cout <<node->ch << " " << node->freq << endl;
    }
}

BinarySearchTree :: BinarySearchTree() {
    root = nullptr;
}

void BinarySearchTree:: insert(char data) {
    BSTNode* newNode = new BSTNode(data);

    if(root == nullptr) {
        root = newNode;

    }
    else {
        BSTNode* current = root;
        BSTNode* parent = nullptr;

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
int BinarySearchTree::Freqof(char ch)
{
    BSTNode* current = root;
    BSTNode* parent = nullptr;

    while(current != nullptr) {
        parent = current;

        if(ch < current->ch) {
            current = current->left;
        }
        else if(ch > current->ch) {
            current = current->right;
        }
        else {
            return current->freq;
        }
    }
}

