#include <iostream>
#include <string>
#include "BinarySearchTreeHeader.h"
#include "HuffmanHeader.h"
int main()
{
    string text;
    cout << "Write a text" << endl;
    getline(cin, text);
    BinarySearchTree freqMap;
    for (char ch : text) {
        freqMap.insert(ch);
    }
    freqMap.inorderTraversal();
   // cout << "Freq of x is "<<freqMap.Freqof('x')<<endl;
    //cout << "Freq of z is "<<freqMap.Freqof('z')<<endl;
  // cout << "Freq of c is "<<freqMap.Freqof('c')<<endl;
   // freqMap.pq.display();
    cout <<"Top of queue is "<< freqMap.pq.top()->ch<<endl;
    cout << freqMap.pq.isEmpty()<<endl;


    Huffman huffman;
    huffman.buildTree(text);
    /*string encodedText = huffman.encode(text);
    string decodedText = huffman.decode(encodedText);
    cout << "Original text: " << text << endl;
    cout << "Encoded  text: " << encodedText << endl;
    cout << "Decoded text: " << decodedText << endl;*/
    /*
    string text;
    cout << "Write a text" << endl;
    getline(cin, text);
    Huffman huffman;
    huffman.buildTree(text);
    string encodedText = huffman.encode(text);
    string decodedText = huffman.decode(encodedText);
    cout << "Original text: " << text << endl;
    cout << "Encoded  text: " << encodedText << endl;
    cout << "Decoded text: " << decodedText << endl;
*/
}
