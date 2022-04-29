main: main.o Stack.o Node.o List.o Queue.o
	g++ -o main main.o Stack.o Node.o List.o Queue.o -std=c++11

tests: tests.o Stack.o Node.o List.o Queue.o
	g++ -o tests tests.o Stack.o Node.o List.o Queue.o -std=c++11
	
main.o: main.cpp Stack.cpp Node.cpp List.cpp Queue.cpp
	g++ -c main.cpp -std=c++11

Node.o: Node.cpp Node.h 
	g++ -c -std=c++11 Node.cpp

Stack.o: Stack.cpp Stack.h 
	g++ -c -std=c++11 Stack.cpp

List.o: List.cpp List.h
	g++ -c -std=c++11 List.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c -std=c++11 Queue.cpp

tests.o: tests.cpp Stack.cpp Node.cpp List.cpp Queue.cpp
	g++ -c -std=c++11 tests.cpp


clean:
	rm -f *.o 