#pragma once
#include <iostream>
#include "NodeHeader.h"

using namespace std;

#ifndef BinarySearchTreeHeader.h
#define BinarySearchTreeHeader.h
class BinarySearchTree
{
private:
    Node* root;
    void inorderTraversal(Node* node);
public:
    BinarySearchTree();
    void insert(char data);
    void insert(char data,int freq);
    void inorderTraversal();
};


#endif