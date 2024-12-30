/*
 * Queue.cpp
 *
 * Description: Link-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Kelly Khuc and Charis Chu
 * Date: November 15, 2023
 */

#include "Queue.h"
#include "EmptyDataCollectionException.h"
#include <iostream>

using std::cout;
using std::endl;

//Description: Default Constructor, creates queue object
//Postcondition: initialized elementCount, front and back pointers
template <class ElementType> Queue<ElementType>::Queue() {
  elementCount = 0;
  front = NULL;
  back = NULL;
}

// Description: Destructor, deletes queue object
// Postcondition: heap memory freed
template <class ElementType> Queue<ElementType>::~Queue() {
  while (elementCount != 0) {
    dequeue();
  }
}

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType> bool Queue<ElementType>::isEmpty() const {
  return elementCount == 0;
}

// Description: Inserts newElement at the "back" of this Queue
//              (not necessarily the "back" of this Queue's data structure)
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType &newElement) {
  Node *newNode = new Node(newElement);
  if (newNode == nullptr)
    return false;
  if (elementCount == 0) {
    front = newNode;
    back = newNode;
  } else {
    back->next = newNode;
    back = newNode;
  }
  elementCount++;
  return true;
}

// Description: Removes (but does not return) the element at the "front" of this
// Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType> void Queue<ElementType>::dequeue() {
  try {
    if (elementCount == 0) {
      throw EmptyDataCollectionException("This Queue is empty.");
    }
  } catch (EmptyDataCollectionException &e) {
    cout << e.what() << endl;
    return;
  }
  if (elementCount == 1) {
    delete front;
    front = nullptr;
    back = nullptr;
  } else {
    Node *temp = front;
    front = front->next;
    delete temp;
  }
  elementCount--;
}

// Description: Returns (but does not remove) the element at the "front" of this
// Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType> ElementType &Queue<ElementType>::peek() const {
  return front->data;
}

/******* End of Queue Public Interface *******/

template <class ElementType> void Queue<ElementType>::printQ() {
  Node *temp = front;
  cout<<"[";
  while (temp != nullptr) {
    cout << temp->data<< " ";
    temp = temp->next;
  }
  cout<<"]"<<endl;
}
