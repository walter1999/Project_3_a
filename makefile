word.exe: wordList.o main.o grid.o
	g++ wordList.o main.o grid.o -o word

wordList.o: wordList.cpp wordList.hpp
	g++ -c wordList.cpp


grid.o: grid.cpp grid.h matrix.h 
	g++ -c grid.cpp

main.o: main.cpp wordList.hpp grid.h 
	g++ -c main.cpp
