#pragma once
#include <iostream>
#include <string>
#include "BSTNodeHeader.h"
#include "BinarySearchTreeHeader.h"
#include "Queue.h"

using namespace std;

#ifndef HuffmanHeader
#define HuffmanHeader

// Compare class for priority queue
class Compare {
public:
    bool operator()(BSTNode* l, BSTNode* r) {
        return l->freq > r->freq;
    }
};

class Huffman {
private:
    BSTNode* root;
    BinarySearchTree huffmanCode;
public:
    Huffman();
    // class constructor of huffman 

    ~Huffman();
    // class destructor of huffman 

    string encode(const string& text);
    // Encode input string

    string decode(const string& encodedText);
    // Decode input string

    void buildTree(const string& text);
    // Build Huffman tree

    void generateHuffmanCode(BSTNode* node, string code);
    // Generate Huffman codes for each character

    void deleteTree(BSTNode* node);
    // Delete Huffman tree
};

#endif
