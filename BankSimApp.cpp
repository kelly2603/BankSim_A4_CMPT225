
/* 
 * BankSimApp.cpp
 *
 * Description: Bank Simulator App using Priority Queue implementation with
 *              Minimum Binary Heap as the underlying structure
 *
 * 
 * Author: Kelly Khuc and Charis Chu
 * Last Modification: November 15, 2023
 *
 */  


#include <iostream>
#include <fstream>
#include <iomanip>
#include "Queue.h"
#include "BinaryHeap.h"
#include "Event.h"
#include "PriorityQueue.h"


using std::endl;
using std::cout;
using std::cin;
using std::ws;
using std::setw;
using std::left;
using std::right;

void processArrival(Event &event, PriorityQueue<Event> &pq, Queue<Event> &q,
                                  bool &teller,int &currenttime,int&totalwait){
  pq.dequeue();
  if(q.isEmpty()&&teller){
    int deptime = currenttime + event.getLength();
    Event departure = Event('D',deptime);
    pq.enqueue(departure);
    teller = false;
  }
  else{
    q.enqueue(event);
    totalwait = totalwait - event.getTime();
  }
} 

void processDeparture(Event &event, PriorityQueue<Event> &pq, Queue<Event> &q, 
                                  bool &teller, int &currenttime,int&totalwait){
  pq.dequeue();
  if(!q.isEmpty()){
    Event customer = q.peek();
    q.dequeue();
    int deptime = currenttime + customer.getLength();
    Event departure = Event('D',deptime);
    pq.enqueue(departure);
    totalwait = totalwait + currenttime;
  }else{
    teller = true;
  }
}


int main(int argc, char* argv[]) {
  cout << "Simulation Begins" << endl;
  std::istream *str = & cin;
  PriorityQueue<Event> pq;
  Queue<Event> q;
  bool end = false, teller = true;
  int currenttime = 0;
  int people = 0;
  int totalwait = 0;

  // Reading input from file
  while(!end){
    char d[3];
    char t[3];
    int i=0;
    while (str->peek()!= ' '){
      t[i]=str->get();
      i++;
    }
    i=0;
    while(str->peek()!= '\n'&&str->peek()!=EOF){
      d[i]=str->get();
      i++;
    }
    int time = atoi(t);
    int duration = atoi(d);
    Event event = Event(Event::ARRIVAL,time,duration);
    pq.enqueue(event);
    
    for(int i=0; i<3; i++){
      d[i]=0;
      t[i]=0;
    }
    people++;
    if(str->peek()==EOF) {end=true;}
    
  }
  
  //Processing Events
  while(!pq.isEmpty()){
    Event event = pq.peek();
    currenttime = event.getTime();
    if(event.isArrival()){
      processArrival(event, pq, q, teller,currenttime,totalwait);
      cout << setw(36) << left << "Processing an arrival event at time:";
      cout<< setw(6) << right << currenttime << endl;
    }
    else{
      processDeparture(event, pq, q, teller, currenttime,totalwait);
      cout << setw(37) << left << "Processing a departure event at time:";
      cout<< setw(5) << right << currenttime << endl;
    }
  }  

  cout << "Simulation Ends" << endl;

  cout <<endl<< "Final Statistics: "<<endl<<endl;
  cout << "  Total number of people processed: " << people << endl;
  cout << "  Average amount of time spent waiting: " << (float)totalwait/people << endl <<endl;
  
  return 0;
} 