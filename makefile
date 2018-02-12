word.exe: wordList.o main.o
	g++ wordList.o main.o -o word

wordList.o: wordList.cpp wordList.hpp
	g++ -c wordList.cpp

main.o: main.cpp wordList.hpp
	g++ -c main.cpp
