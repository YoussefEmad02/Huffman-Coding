#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef BSTNodeHeader
#define BSTNodeHeader

class BSTNode {
public:
    char ch;
    string code;
    BSTNode* left;
    BSTNode* right;
    int freq; // to store the frequency of the value

    //it is the constructor for the node
    BSTNode(char ch);
    BSTNode(char ch, int freq);


    bool isLeaf() const;
    //check if the node is the last (leaf) or not 
};

#endif

