#include <iostream>
#include "NodeHeader.h"

using namespace std;

//Definition of class constructor
Node::Node(char ch) {
    this->ch = ch;
    left = nullptr;
    right = nullptr;
    freq = 1;
}
Node::Node(char ch,int freq) {
    this->ch = ch;
    left = nullptr;
    right = nullptr;
    this->freq = freq;
}

//Definition of isleaf()
bool Node::isLeaf() const
{
    return (left == nullptr && right == nullptr);
}
