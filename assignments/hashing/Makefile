
main: main.o ONode.o OList.o Dictionary.o Person.o
	g++ -o main main.o ONode.o OList.o Dictionary.o Person.o

tests: tests.o ONode.o OList.o Dictionary.o Person.o
	g++ -o tests tests.o ONode.o OList.o Dictionary.o Person.o

main.o: main.cpp ONode.h OList.h
	g++ -c main.cpp

ONode.o: ONode.cpp ONode.h Person.h
	g++ -c ONode.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

OList.o: OList.cpp OList.h ONode.h
	g++ -c OList.cpp

Dictionary.o: Dictionary.cpp Dictionary.h OList.h
	g++ -c Dictionary.cpp

tests.o: tests.cpp Dictionary.h
	g++ -c tests.cpp 

clean:
	rm -f main tests *.o *.gch