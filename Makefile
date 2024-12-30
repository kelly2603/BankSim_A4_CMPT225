
all: tdQ tdBH tdPQ

tdQ: testDriver_Q.o Queue.h Event.o EmptyDataCollectionException.o
	g++ -o tdQ -Wall testDriver_Q.o Event.o EmptyDataCollectionException.o

tdBH: testDriver_BH.o BinaryHeap.h Event.o EmptyDataCollectionException.o
	g++ -o tdBH -Wall testDriver_BH.o Event.o EmptyDataCollectionException.o

tdPQ: testDriver_PQ.o PriorityQueue.h Event.o EmptyDataCollectionException.o
	g++ -o tdPQ -Wall testDriver_PQ.o Event.o EmptyDataCollectionException.o

testDriver_Q.o: testDriver_Q.cpp  
	g++ -c -Wall testDriver_Q.cpp

Event.o: Event.cpp Event.h
	g++ -c -Wall Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h 
	g++ -c -Wall EmptyDataCollectionException.cpp

testDriver_BH.o: testDriver_BH.cpp
	g++ -c -Wall testDriver_BH.cpp

testDriver_PQ.o: testDriver_PQ.cpp
	g++ -c -Wall testDriver_PQ.cpp

clean:	
	rm -f tdQ tdBH tdPQ *.o