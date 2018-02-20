
#ifndef GRID_H
#define GRID_H


#include <string>
#include <iostream>
#include <vector>
#include "matrix.h"
// security code

class grid{ //declares class

private:
	matrix<std::string> new_matrix;// matrix of strings to store letters

	int column;// number of columns

	int rows;// number of words

public:

	grid();// defualt constructor 
	
	grid(std::string new_file);// constructor that establshes the  matrix
	
	int number_of_rows();// returns the number of rows 

    int number_of_columns();//returns the number of columns

	string given_character(int new_row, int new_column);// returns a character at given location
	
	matrix<std::string> get_matrix(); // returns the matrix

	~grid();// destroys the object. Does not do anything else

};

#endif // GRID_H
