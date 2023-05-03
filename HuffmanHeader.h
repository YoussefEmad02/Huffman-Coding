#pragma once
#include <iostream>
#include <string>
#include "NodeHeader.h"
#include "BinarySearchTreeHeader.h"

using namespace std;

#ifndef HuffmanHeader.h
#define HuffmanHeader.h

// Compare class for priority queue
class Compare {
public:
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

class Huffman {
private:
    Node* root;
    unordered_map<char, string> huffmanCode;
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

    void generateHuffmanCode(Node* node, string code);
    // Generate Huffman codes for each character

    void deleteTree(Node* node);
    // Delete Huffman tree
};

#endif