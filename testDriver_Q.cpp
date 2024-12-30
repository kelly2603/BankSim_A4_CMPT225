#include <iostream>
#include "Queue.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;

int main(){
  Queue<char> *Q = new Queue<char>();
  cout << Q->isEmpty()<<endl;
  //int a=5,b=6,c=7;
  char a='a',b='b',c='c';
  Q->enqueue(a);
  Q->printQ();
  Q->enqueue(b);
  Q->printQ();
  Q->enqueue(c);
  Q->printQ();
  Q->dequeue();
  Q->printQ();
  Q->dequeue(); 
  Q->dequeue();
  Q->dequeue();
  Q->printQ();
  Q->enqueue(a);
  Q->enqueue(c);
  Q->printQ();
  delete Q;
  Q=nullptr;
  return 0;
}