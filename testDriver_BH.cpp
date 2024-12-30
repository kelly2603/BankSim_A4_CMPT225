#include <iostream>
#include "BinaryHeap.h"

using std::cout;
using std::endl;

int main(){
  BinaryHeap <int> *bh = new BinaryHeap<int>(5);
  int a=5,b=6,c=7,d=8,e=9,f=10;
  try{bh->printBH(); bh->remove();}
  catch(EmptyDataCollectionException &ed){
    cout << ed.what() << endl;
    }

  try{bh->retrieve();}
    catch(EmptyDataCollectionException &ed){
      cout << ed.what() << endl;
      }

  cout << "count: " << bh->getElementCount() << endl;
  
  bh->insert(c);
  bh->printBH();
  bh->insert(f);
  bh->printBH();
  bh->insert(a);
  bh->printBH();
  bh->insert(d);
  bh->printBH();
  bh->insert(b);
  bh->printBH();
  bh->insert(e);
  bh->printBH();

  cout << "count: " << bh->getElementCount() << endl;
  
  cout<<bh->retrieve()<<" ";
  bh->remove();
  cout<<bh->retrieve()<<" ";
  bh->remove();
  cout<<bh->retrieve()<<" ";
  bh->remove();
  cout<<bh->retrieve()<<" "<<endl;
  bh->remove();
  bh->printBH();

  cout << "count: " << bh->getElementCount() << endl;
  
  delete bh;
  bh=nullptr;
  return 0;
}