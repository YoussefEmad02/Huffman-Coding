//
//  Queue.hpp
//  PriorityQueueLL
//
//  Created by Ashraf AbdelRaouf on 31/03/2022.
//  The Key have three values (0, 1, 2) where 2 skips all the elements that has 1 or 0 as keys, while 1 skip three elements only that has 0 as a key, while 0 remain on the back of the queue.

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

typedef int QueueElement;

class Queue
{
public:
    /***** Function Members *****/
    /***** Constructors *****/

    Queue();
    /*-----------------------------------------------------------------------
     Construct a Queue object.

     Precondition:  None.
     Postcondition: An empty Queue object has been constructed.
     (myFront and myBack are initialized to null pointers).
     -----------------------------------------------------------------------*/

    Queue(const Queue & original);
    /*-----------------------------------------------------------------------
     Copy Constructor

     Precondition:  original is the queue to be copied and is received
     as a const reference parameter.
     Postcondition: A copy of original has been constructed.
     -----------------------------------------------------------------------*/

    /***** Destructor *****/
    ~Queue();
    /*-----------------------------------------------------------------------
     Class destructor

     Precondition:  None.
     Postcondition: The linked list in the queue has been deallocated.
     -----------------------------------------------------------------------*/

    /***** Assignment *****/
    const Queue & operator= (const Queue & rightHandSide);
    /*-----------------------------------------------------------------------
     Assignment Operator

     Precondition:  rightHandSide is the queue to be assigned and is
     received as a const reference parameter.
     Postcondition: The current queue becomes a copy of rightHandSide
     and a reference to it is returned.
     -----------------------------------------------------------------------*/

    bool empty() const;
    /*-----------------------------------------------------------------------
     Check if queue is empty.

     Precondition:  None.
     Postcondition: Returns true if queue is empty and false otherwise.
     -----------------------------------------------------------------------*/

    void enqueue(const QueueElement & value, int key);
    /*-----------------------------------------------------------------------
     Add a value to a queue with a priority queue key.

     Precondition:  value is to be added to this queue.
     Postcondition: value is added at back of queue. The Key have three values (0, 1, 2) where 2 skips all the elements that has 1 or 0 as keys, while 1 skip three elements only that has 0 as a key, while 0 remain on the back of the queue.
     -----------------------------------------------------------------------*/

    void display(ostream & out) const;
    /*-----------------------------------------------------------------------
     Display values stored in the queue.

     Precondition:  ostream out is open.
     Postcondition: Queue's contents, from front to back, have been
     output to out.
     -----------------------------------------------------------------------*/

    QueueElement front() const;
    /*-----------------------------------------------------------------------
     Retrieve value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue is returned, unless the queue
     is empty; in that case, an error message is displayed and a
     "garbage value" is returned.
     -----------------------------------------------------------------------*/
    QueueElement back() const;


    void dequeue();
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless
     queue is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/

private:
    /*** Node class ***/
    class Node
    {
    public:
        QueueElement data;
        int key;
        Node * next;
        Node *previous;
        //--- Node constructor
        Node(QueueElement value, int k=0, Node * n = 0, Node * p = 0)
        /*-------------------------------------------------------------------
         Precondition:  value and link are received
         Postcondition: A Node has been constructed with value in its
         data part and its next part set to link (default 0).
         ------------------------------------------------------------------*/
        { data = value; key=k; next = n; previous = p;}

    };

    typedef Node * NodePointer;

    /***** Data Members *****/
    NodePointer MyFront,      // pointer to front of queue
    MyBack;       // pointer to back of queue

}; // end of class declaration

//------ Prototype of output operator
ostream & operator<< (ostream & out, const Queue & aQueue);
#endif /* Queue_hpp */
