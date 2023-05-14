#include <iostream>
#include "BSTNodeHeader.h"

using namespace std;

//Definition of class constructor
BSTNode::BSTNode(char ch) {
    this->ch = ch;
    left = nullptr;
    right = nullptr;
    freq = 1;
}
BSTNode::BSTNode(char ch, int freq) {
    this->ch = ch;
    left = nullptr;
    right = nullptr;
    this->freq = freq;
}

//Definition of isleaf()
bool BSTNode::isLeaf() const
{
    return (left == nullptr && right == nullptr);
}
