output: wordList.o main.o grid.o hashTable.o heap.o
	g++ wordList.o main.o grid.o hashTable.o heap.o -o output

wordList.o: wordList.cpp wordList.hpp
	g++ -c wordList.cpp


grid.o: grid.cpp grid.h matrix.h 
	g++ -c grid.cpp

hashTable.o: hashTable.cpp hashTable.h
	g++ -c hashTable.cpp

heap.o: heap.cpp heap.hpp
	g++ -c heap.cpp

main.o: main.cpp wordList.hpp grid.h hashTable.h 
	g++ -c main.cpp
