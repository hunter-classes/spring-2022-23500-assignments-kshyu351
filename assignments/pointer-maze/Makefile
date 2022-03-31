OBJECTS=Main.o Labyrinth.o MazeGenerator.o
CXXFLAGS= -g
LDFLAGS=
CXX=g++

main: $(OBJECTS)
	$(CXX) -g  -o main $(OBJECTS) -std=c++11
Labyrinth.o: Labyrinth.cpp Labyrinth.h 
	g++ -c Labyrinth.cpp -std=c++11

Main.o: Main.cpp MazeGenerator.h Labyrinth.h 
	g++ -c Main.cpp -std=c++11

MazeGenerator.o: MazeGenerator.cpp MazeGenerator.h Labyrinth.h 
	g++ -c MazeGenerator.cpp -std=c++11


clean:
	rm -f $(OBJECTS)