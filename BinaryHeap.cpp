/* 
 * BinaryHeap.cpp
 *
 * Description: Array-Based Implementation of Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a Minimum Binary Heap.
 * 
 * Author: Kelly Khuc and Charis Chu
 * Last Modification: November 15, 2023
 *
 */  

#include <iostream>
#include "BinaryHeap.h"  // Header file
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;

// Constructors and Destructors

//Description: Constructor
//Postcondition: creates a new binary heap with initialized elementCount to 0
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() {
  elementCount = 0;
  elements = new ElementType[capacity];
}

//Description: Construtor with parameter size
//Postcondition: creates new binary heap with specified size, initialize elementCount to 0
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(unsigned int size){
  elementCount = 0;
  elements = new ElementType[size];
  capacity = size;
}

//Description: Default Destructor
//Postcondition: Binary heap object deleted and set to null
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap(){
  delete[] elements;
  elements = nullptr;
}

// Getter and setters

// Description: Returns the number of elements in the Binary Heap.
 // Postcondition: The Binary Heap is unchanged by this operation.
 // Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
  return elementCount;
}

// Helper Function

// Description: Recursively put the array back into a Minimum Binary Heap.
// Postcondition: Array is back to a Minimum Binary Heap
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;

   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount-1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {

      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;

      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 

// Description: Recursively reorder the array into a Minimum Binary Heap
// Postcondition: Array is back to a Minimum Binary Heap
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfChild){

  // find index of parent
  unsigned int indexOfParent = (indexOfChild - 1) / 2;

  // if current element is root, return
  if(indexOfChild == 0) return;

  //if child is smaller or equal to parent then swap
  if(elements[indexOfChild] <= elements[indexOfParent]){
    ElementType temp = elements[indexOfChild];
    elements[indexOfChild] = elements[indexOfParent];
    elements[indexOfParent] = temp;
  }
  // repeat recursive call with index of parent as parameter
  reHeapUp(indexOfParent);
  return;
}

// Public Methods

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");
    if(elementCount == 1) {
      elementCount--;
      return;
    }
   elements[0] = elements[elementCount - 1];
   elementCount--;
   reHeapDown(0);

   return;   
}


// Description: Inserts newElement into the Binary Heap. 
//              It returns true if successful, otherwise false.      
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType & newElement){
  unsigned int indexOfBottom = elementCount;
  if(elementCount >= capacity-1){
    ElementType *temp = elements;
    elements = new ElementType[capacity * 2];
    capacity *= 2;
    for(unsigned int x=0;x<elementCount;x++){
      elements[x] = temp[x];
    }
    delete[] temp;
    temp = nullptr;
  }
  elements[indexOfBottom] = newElement;
  elementCount++;
  reHeapUp(indexOfBottom);
  return true;
}

// Description: Retrieves (but does not remove) the necessary element.
 // Precondition: This Binary Heap is not empty.
 // Postcondition: This Binary Heap is unchanged.
 // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
 // Time Efficiency: O(1) 
template <class ElementType>
ElementType & BinaryHeap<ElementType>::retrieve() const{
  if(elementCount <= 0){
    throw EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.");
  }
  return elements[0];
}

// Print binary heap function
template <class ElementType>
void BinaryHeap<ElementType>::printBH() {
  /*
  cout <<"[";
  for(unsigned int x=0;x<elementCount;x++){
    cout << elements[x] << " ";
  }
  cout<<"]"<<endl;
  */
  
  for(unsigned int x=0;x<elementCount;x++){
    elements[x].print();
    cout<<endl;
  }
  
}

