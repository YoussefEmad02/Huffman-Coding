#include <iostream>
#include <string>
#include "BSTNodeHeader.h"
#include "HuffmanHeader.h"
#include "Queue.h"

using namespace std;
BinarySearchTree freqMap;
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
        encodedText += freqMap.codeof(ch);
    }
    return encodedText;
}

// Definition of Decode input string
string Huffman::decode(const string& encodedText) {
    if (root == nullptr) {
        return "";
    }
    string decodedText = "";
    BSTNode* current = root;
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
    cout << "I Entered Build tree"<<endl;
    if (text.empty()) {
        return;
    }

    for (char ch : text) {
        freqMap.insert(ch);
    }
    freqMap.inorderTraversal();

    while (!freqMap.pq.isEmpty()) {
        BSTNode* left = freqMap.pq.top();
        cout << "Left "<<left->ch <<endl;
        freqMap.pq.dequeue();
        BSTNode* right = freqMap.pq.top();
        cout << "Right "<<right->ch <<endl;
        freqMap.pq.dequeue();
        BSTNode* parent = new BSTNode('p', left->freq + right->freq);
        cout << "Parent "<<parent->freq <<endl;
        parent->left = left;
        parent->right = right;
        freqMap.pq.enqueue(parent);
    }
    freqMap.pq.display();
    root = freqMap.pq.top();
    freqMap.pq.dequeue();
    generateHuffmanCode(root, "");

}

// Definition of Generate Huffman codes for each character
void Huffman::generateHuffmanCode(BSTNode* node, string code) {
    if (node == nullptr) {
        return;
    }
    if (node->isLeaf()) {
        node->code = code;

    }
    generateHuffmanCode(node->left, code + "0");
    generateHuffmanCode(node->right, code + "1");
    cout <<"code of " << node->ch<<" "<<node->code<<endl;
}

// Definition of Delete Huffman tree
void Huffman::deleteTree(BSTNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
