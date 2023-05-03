#include <iostream>
#include <string>
#include "NodeHeader.h"
#include "HuffmanHeader.h"

using namespace std;

//Definition of class constructor
Huffman::Huffman() {
    root = nullptr;
}

// Definition of class destructor 
Huffman::~Huffman() {
    deleteTree(root);
}

// Definition of Encode input string
string Huffman::encode(const string& text) {
    if (root == nullptr) {
        return "";
    }
    string encodedText = "";
    for (char ch : text) {
        encodedText += huffmanCode[ch];
    }
    return encodedText;
}

// Definition of Decode input string
string Huffman::decode(const string& encodedText) {
    if (root == nullptr) {
        return "";
    }
    string decodedText = "";
    Node* current = root;
    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        }
        else {
            current = current->right;
        }
        if (current->isLeaf()) {
            decodedText += current->ch;
            current = root;
        }
    }
    return decodedText;
}

// Definition of Build Huffman tree
void Huffman::buildTree(const string& text) {
    if (text.empty()) {
        return;
    }
    BinarySearchTree freqMap;
    for (char ch : text) {
        freqMap.insert(ch);
    }

    generateHuffmanCode(root, "");

}

// Definition of Generate Huffman codes for each character
void Huffman::generateHuffmanCode(Node* node, string code) {
    if (node == nullptr) {
        return;
    }
    if (node->isLeaf()) {
        huffmanCode[node->ch] = code;
    }
    generateHuffmanCode(node->left, code + "0");
    generateHuffmanCode(node->right, code + "1");
}

// Definition of Delete Huffman tree
void Huffman::deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}