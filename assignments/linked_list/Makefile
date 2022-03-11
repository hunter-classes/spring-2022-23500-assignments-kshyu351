main: main.o OList.o List.o Node.o ONode.o 
	g++ -o main main.o OList.o List.o Node.o ONode.o -std=c++11

tests: tests.o OList.o ONode.o
	g++ -o tests tests.o OList.o ONode.o -std=c++11
	
main.o: main.cpp OList.cpp List.cpp Node.cpp ONode.cpp
	g++ -c main.cpp -std=c++11

Node.o: Node.cpp Node.h 

List.o: List.cpp List.h 

OList.o: OList.cpp OList.h 

ONode.o: ONode.cpp ONode.h 

tests.o: tests.cpp OList.cpp ONode.cpp 

clean:
	rm -f *.o 