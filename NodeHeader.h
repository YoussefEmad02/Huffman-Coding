#pragma once
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

#ifndef NodeHeader.h
#define NodeHeader.h

class Node {
public:
    char ch;
    Node* left;
    Node* right;
    int freq; // to store the frequency of the value

    //it is the constructor for the node
    Node(char ch);
    Node(char ch,int freq);

    bool isLeaf() const;
    //check if the node is the last (leaf) or not 
};

#endif