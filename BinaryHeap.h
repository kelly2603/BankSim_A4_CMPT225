/* 
 * BinaryHeap.h
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a Minimum Binary Heap.
 * 
 * Author: Kelly Khuc and Charis Chu
 * Last Modification: November 15, 2023
 *
 */ 

#ifndef BINARYHEAP_H
#define BINARYHEAP_H


template <class ElementType>
class BinaryHeap{
private:
  unsigned int capacity = 20;
  ElementType*  elements;
  unsigned int elementCount;

  // Description: Recursively reorder the array into a Minimum Binary Heap
  // Postcondition: Array is back to a Minimum Binary Heap
  void reHeapUp(unsigned int indexOfChild);

  // Description: Recursively put the array back into a Minimum Binary Heap.
  // Postcondition: Array is back to a Minimum Binary Heap
  void reHeapDown(unsigned int indexOfRoot);
  
public:

  //Description: Default Constructor
  //Postcondition: creates a new binary heap with initialized elementCount to 0
  BinaryHeap();

  //Description: Construtor
  //Postcondition: creates new binary heap with specified size, initialize elementCount to 0
  BinaryHeap(unsigned int size);

  //Description: Default Destructor
  //Postcondition: Binary heap object deleted and set to null
  ~BinaryHeap();

  /******* Start of Binary Heap  Public Interface *******/

  // Description: Returns the number of elements in the Binary Heap.
  // Postcondition: The Binary Heap is unchanged by this operation.
  // Time Efficiency: O(1)
  unsigned int getElementCount() const;

  // Description: Inserts newElement into the Binary Heap. 
  //              It returns true if successful, otherwise false.      
  // Time Efficiency: O(log2 n)
  bool insert(ElementType & newElement);

  // Description: Removes (but does not return) the necessary element.
  // Precondition: This Binary Heap is not empty.
  // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
  // Time Efficiency: O(log2 n)
  void remove();
  

   // Description: Retrieves (but does not remove) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Postcondition: This Binary Heap is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(1) 
  ElementType & retrieve() const;

  /******* End of Binary Heap Public Interface *******/

  void printBH();

};
#include "BinaryHeap.cpp"
#endif