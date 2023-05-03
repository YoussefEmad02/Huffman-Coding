#include <iostream>
#include <string>
#include "BinarySearchTreeHeader.h"
int main()
{
    string text;
    cin >>text;
    BinarySearchTree freqMap;
    for (char ch : text) {
        freqMap.insert(ch);
    }
    freqMap.inorderTraversal(); // Prints "1 2 2 4 5 5 8"
}