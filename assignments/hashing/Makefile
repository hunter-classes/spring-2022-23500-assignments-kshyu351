
main: main.o ONode.o OList.o Dictionary.o Person.o
	g++ -o main main.o ONode.o OList.o Dictionary.o Person.o -std=c++11

tests: tests.o ONode.o OList.o Dictionary.o Person.o
	g++ -o tests tests.o ONode.o OList.o Dictionary.o Person.o -std=c++11

main.o: main.cpp ONode.h OList.h
	g++ -c main.cpp -std=c++11

ONode.o: ONode.cpp ONode.h Person.h
	g++ -c ONode.cpp -std=c++11

Person.o: Person.cpp Person.h
	g++ -c Person.cpp -std=c++11

OList.o: OList.cpp OList.h ONode.h
	g++ -c OList.cpp -std=c++11

Dictionary.o: Dictionary.cpp Dictionary.h OList.h
	g++ -c Dictionary.cpp -std=c++11

tests.o: tests.cpp Dictionary.cpp
	g++ -c tests.cpp -std=c++11

clean:
	rm -f main tests *.o *.gch