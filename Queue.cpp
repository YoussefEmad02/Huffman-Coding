#include <iostream>

using namespace std;
#include "BSTNodeHeader.h"
#include "Queue.h"
/*class BSTNode {
public:
    char data;
    int priority;
    BSTNode* next;

    BSTNode(char data, int priority) {
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }
};
*/

void Queue::enqueue(BSTNode* node) {
    BSTNode* newNode = new BSTNode(node->ch, node->freq);
    if (front == nullptr || node->freq < front->freq) {
        newNode->right = front;
        front = newNode;
        if (rear == nullptr) {
            rear = newNode;
        }
    }
    else {
        BSTNode* curr = front;
        while (curr->right != nullptr && node->freq >= curr->right->freq) {
            curr = curr->right;
        }
        newNode->right = curr->right;
        curr->right = newNode;
    }
    if (rear == nullptr || node->freq > rear->freq) {
        rear = newNode;
    }
}

char Queue::dequeue() {
    if (front == nullptr) {
        cout<< "Queue is empty";
    }
    char data = front->ch;
    BSTNode* temp = front;
    front = front->right;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return data;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::display() {
    BSTNode* curr = front;
    while (curr != nullptr) {
        cout << curr->ch << " "<<curr->freq<<endl;
        curr = curr->right;
    }
    cout << endl;
}
BSTNode* Queue::top() {
    return front;
}