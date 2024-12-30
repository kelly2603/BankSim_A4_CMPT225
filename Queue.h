/*
 * Queue.h
 *
 * Description: Link-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Kelly Khuc and Charis Chu
 * Date: November 15, 2023
 */


#ifndef QUEUE_H
#define QUEUE_H

template <class ElementType>
class Queue{ 

private:
  class Node{
    public:
    ElementType data;
    Node* next;
    Node(){
      next = nullptr;
    }
    Node(ElementType & stuff){
      data = stuff;
      next = nullptr;
    }
    ~Node(){
      next = nullptr;
    }
  };
  Node* front;
  Node* back;
  unsigned int elementCount;
public:
  
/******* Start of Queue Public Interface *******/

   // Class Invariant:  FIFO or LILO order
  //Description: Constructor creates a new Queue object
  Queue();
  //Description: Destructor, deletes queue object
  //Postcondition: heap memory freed
  ~Queue();

   // Description: Returns true if this Queue is empty, otherwise false.
   // Postcondition: This Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement at the "back" of this Queue 
   //              (not necessarily the "back" of this Queue's data structure) 
   //              and returns true if successful, otherwise false.
   // Time Efficiency: O(1)
   bool enqueue(ElementType & newElement);

   // Description: Removes (but does not return) the element at the "front" of this Queue 
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
   // Time Efficiency: O(1)
   void dequeue(); 

   // Description: Returns (but does not remove) the element at the "front" of this Queue
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   ElementType & peek() const;

/******* End of Queue Public Interface *******/
   void printQ();
};
#include "Queue.cpp"
#endif