#pragma once
#include <iostream>
#include "BSTNodeHeader.h"
#include "Queue.h"

using namespace std;

#ifndef BinarySearchTreeHeader
#define BinarySearchTreeHeader
class BinarySearchTree
{
private:
    BSTNode* root;
    void inorderTraversal(BSTNode* node);
public:
    Queue pq;
    BinarySearchTree();
    void insert(char data);
    void inorderTraversal();
    int Freqof(char ch);
    string codeof(char ch);
};


#endif