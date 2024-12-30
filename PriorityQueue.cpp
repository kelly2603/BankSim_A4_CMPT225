/* 
 * PriorityQueue.h
 *
 * Description: Minimum Binary Heap Implementation of Priority Queue ADT class.
 *
 * Class Invariant:  Always remains in sorted FIFO order with respect to priority value
 * 
 * Author: Kelly Khuc and Charis Chu
 * Last Modification: November 15, 2023
 *
 */

#include <iostream>
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

// Priority Queue COnstructors and Destructors

//Description: Constructor
//Postcondition: Creates a Priority Queue Object
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){
  elements = new BinaryHeap<ElementType>;
}

//Description: Destructor
//Postcondition: Deletes a Priority Queue Object and free it from the heap
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
  delete elements;
  elements = nullptr;
}

// Priority Queue Methods

   // Description: Returns true if this Priority Queue is empty, otherwise false.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
template <class ElementType>
   bool PriorityQueue<ElementType>::isEmpty() const{
     return elements->getElementCount() == 0;
   }

   // Description: Inserts newElement in this Priority Queue and 
   //              returns true if successful, otherwise false.
   // Time Efficiency: O(log2 n)
template <class ElementType>
   bool PriorityQueue<ElementType>::enqueue(ElementType& newElement){
     return elements->insert(newElement);
   }

   // Description: Removes (but does not return) the element with the next
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
   // Time Efficiency: O(log2 n)
template <class ElementType>
   void PriorityQueue<ElementType>::dequeue(){
     if(elements->getElementCount() == 0){
       throw EmptyDataCollectionException("This Priority Queue is empty.");
     }
     elements->remove();
   }

   // Description: Returns (but does not remove) the element with the next 
   //              "highest" priority from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
template <class ElementType>
   ElementType & PriorityQueue<ElementType>::peek() const{
     if(elements->getElementCount() == 0){
       throw EmptyDataCollectionException("This Priority Queue is empty.");
     }
     return elements->retrieve();
   }




// print priority queue method
template <class ElementType>
void PriorityQueue<ElementType>::printPQ(){
  elements->printBH();
}