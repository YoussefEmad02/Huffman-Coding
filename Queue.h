//
//  Queue.hpp
//  PriorityQueueLL
//
//  Created by Ashraf AbdelRaouf on 31/03/2022.
//  The Key have three values (0, 1, 2) where 2 skips all the elements that has 1 or 0 as keys, while 1 skip three elements only that has 0 as a key, while 0 remain on the back of the queue.

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include "BSTNodeHeader.h"
using namespace std;


class Queue {
private:
    BSTNode* front;
    BSTNode* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(BSTNode* node);
    char dequeue();
    bool isEmpty();
    void display();
    BSTNode* top();

};
#endif /* Queue.h */
