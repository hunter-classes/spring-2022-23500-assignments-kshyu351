main: main.o List.o Node.o
	g++ -o main main.o List.o Node.o -std=c++11


main.o: main.cpp List.cpp Node.cpp
	g++ -c main.cpp -std=c++11

Node.o: Node.cpp Node.h 

List.o: List.cpp List.h 

clean:
	rm -f *.o 