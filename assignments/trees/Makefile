main: main.o BSTree.o Node.o 
	g++ -o main main.o BSTree.o Node.o  -std=c++11

tests: tests.o BSTree.o Node.o 
	g++ -o tests tests.o BSTree.o Node.o  -std=c++11
	
main.o: main.cpp BSTree.cpp Node.cpp 
	g++ -c main.cpp -std=c++11

Node.o: Node.cpp Node.h 
	g++ -c -std=c++11 Node.cpp

BSTree.o: BSTree.cpp BSTree.h
	g++ -c -std=c++11 BSTree.cpp


tests.o: tests.cpp BSTree.cpp Node.cpp 
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f *.o 