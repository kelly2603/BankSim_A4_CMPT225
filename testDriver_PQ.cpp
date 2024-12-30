#include <iostream>
#include "Event.h"
#include "PriorityQueue.h"

using std::cout;
using std::endl;

int main() {
  PriorityQueue<Event> pq;
  cout<<"made empty PQ"<<endl;
  cout<< pq.isEmpty() << endl; //1
  
  Event e1=Event(Event::ARRIVAL, 1, 5);
  Event e2=Event(Event::ARRIVAL, 2, 7);
  Event e3=Event(Event::ARRIVAL, 3, 9);
  Event e4=Event(Event::ARRIVAL, 4, 11);
  Event e5=Event(Event::ARRIVAL, 5, 13);
  Event e6=Event(Event::ARRIVAL, 6, 15);
  Event e7=Event(Event::DEPARTURE, 6, 17);
  Event e8=Event(Event::ARRIVAL, 1, 10);

  try{pq.dequeue();}
  catch(EmptyDataCollectionException &ed){
    cout << ed.what() << endl;
  }
  pq.printPQ();cout<<endl;
  
  pq.enqueue(e3);
  pq.printPQ();cout<<endl;  // 3

  cout<< pq.isEmpty() << endl; // 0
  
  pq.enqueue(e1);
  pq.printPQ();cout<<endl;  // 1 3
  
  pq.enqueue(e4);
  pq.printPQ();cout<<endl;  // 1 3 4

  pq.enqueue(e8);
  pq.printPQ();cout<<endl; // 1(e1) 1(e8) 4 3
  
  pq.enqueue(e2);
  pq.printPQ();cout<<endl;  // 1(e1) 1(e8) 4 3 2
  
  pq.enqueue(e1);
  pq.printPQ();cout<<endl;  // 1(e1) 1(e8) 1(e1) 3 2 4
  
  pq.dequeue();
  pq.printPQ();cout<<endl; // 1(e8) 2 1(e1) 3 4
  
  pq.enqueue(e6);
  pq.printPQ();cout<<endl; // 1(e8) 2 1(e1) 3 4 6
  
  pq.enqueue(e5);
  pq.printPQ();cout<<endl; // 1(e8) 2 1(e1) 3 4 6 5
  
  pq.dequeue();
  pq.printPQ();cout<<endl; // 1(e1) 2 5 3 4 6 
  
  pq.enqueue(e7);
  pq.printPQ();cout<<endl; // 1(e1) 2 5 3 4 6 6

  pq.enqueue(e8);
  pq.printPQ();cout<<endl; // 1(e1) 1(e8) 5 2 4 6 6 3

  pq.enqueue(e5);
  pq.printPQ();cout<<endl; // 1(e8) 2 1(e1) 3 4 6 5


}