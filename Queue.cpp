//
//  Queue.cpp
//  PriorityQueueLL
//
//  Created by Ashraf AbdelRaouf on 31/03/2022.
//

#include "Queue.hpp"
//--- Definition of Queue constructor
Queue::Queue()
        : MyFront(0), MyBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original){
    MyFront = MyBack = 0;
    if (!original.empty()){
        // Copy first node
        MyFront = MyBack = new Queue::Node(original.front());

        // Set pointer to run through original's linked list
        Queue::NodePointer origPtr = original.MyFront->next;
        while (origPtr != 0){
            MyBack->next = new Queue::Node(origPtr->data);
            MyBack->next->previous=MyBack;
            MyBack = MyBack->next;
            origPtr = origPtr->next;
        }
    }
}

//--- Definition of Queue destructor
Queue::~Queue(){
    // Set pointer to run through the queue
    Queue::NodePointer prev = MyFront, ptr;
    while (prev != 0){
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide){
    if (this != &rightHandSide){         // check that not q = q
        this->~Queue();                  // destroy current linked list
        if (rightHandSide.empty())       // empty queue
            MyFront = MyBack = 0;
        else{                                // copy rightHandSide's list
            // Copy first node
            MyFront = MyBack = new Queue::Node(rightHandSide.front());

            // Set pointer to run through rightHandSide's linked list
            Queue::NodePointer rhsPtr = rightHandSide.MyFront->next;
            while (rhsPtr != 0)
            {
                MyBack->next = new Queue::Node(rhsPtr->data);
                MyBack->next->previous=MyBack;
                MyBack = MyBack->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{
    return (MyFront == 0);
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value, int key){
    int cnt=0;
    Queue::NodePointer newptr = new Queue::Node(value, key), loc=MyBack;
    if (empty()){
        MyFront = MyBack = newptr;
        return;
    }
    if(key<=MyBack->key){
        MyBack->next = newptr;
        newptr->previous=MyBack;
        MyBack = newptr;
        return;
    }
    while(((key==2)&&(loc->key<2))||
          ((key==1)&&(loc->key<1)&&(cnt++<3))){
        loc=loc->previous;
        if(loc==0)  break;
    }
    if(loc==0){
        newptr->next=MyFront;
        newptr->previous=0;
        MyFront=newptr;
        newptr->next->previous=newptr;
    }
    else{
        newptr->next=loc->next;
        newptr->previous=loc;
        loc->next=newptr;
        newptr->next->previous=newptr;
    }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
    Queue::NodePointer ptr;
    for (ptr = MyFront; ptr != 0; ptr = ptr->next)
        out << ptr->data<<"--> "<<ptr->key << ",  ";
    out << endl;

}

//--- Definition of output operator
ostream & operator<< (ostream & out, const Queue & aQueue)
{
    aQueue.display(out);
    return out;
}

//--- Definition of front()
QueueElement Queue::front() const
{
    if (!empty())
        return (MyFront->data);
    else
    {
        cerr << "*** Queue is empty "
                " -- returning garbage ***\n";
        QueueElement * temp = new(QueueElement);
        QueueElement garbage = *temp;     // "Garbage" value
        delete temp;
        return garbage;
    }
}

//--- Definition of back()
QueueElement Queue::back() const
{
    if (!empty())
        return (MyBack->data);
    else
    {
        cerr << "*** Queue is empty "
                " -- returning garbage ***\n";
        QueueElement * temp = new(QueueElement);
        QueueElement garbage = *temp;     // "Garbage" value
        delete temp;
        return garbage;
    }
}


//--- Definition of dequeue()
void Queue::dequeue()
{
    if (!empty())
    {
        Queue::NodePointer ptr = MyFront;
        MyFront = MyFront->next;
        delete ptr;
        if (MyFront == 0)     // queue is now empty
            MyBack = 0;
    }
    else
        cerr << "*** Queue is empty -- can't remove a value ***\n";
}
