#include <vector>
#include <string>
#include "grid.h"
#include <fstream>
#include <string>
#include <iostream>
#include "matrix.h"
grid::grid(){}//default constructor does nothing 

grid::grid(std::string new_file){

	std::ifstream fin;// creates ifstream object
	
	std::string character;//
	
	fin.open(new_file.c_str());// opens the file input 
	int rows2=0, columns2=0;
	if(!fin){//if the file could be open then the following message will be display 
	
	std::cout<<" File could not be open"<<std::endl;

		
	}
	
	while(fin>> rows >> column){
	//std::cout<<rows<< " " <<column<<std::endl;
	new_matrix.resize(rows,column); 
	while( fin>>character){
	//	std::cout<<character;
		new_matrix[rows2][columns2]=character;
		columns2++;
		std::cout<<rows2<< " "<<columns2<< " " <<new_matrix[rows2][columns2]<<std::endl;
		if(columns2==column-1){
			rows2++;
			columns2=0;
			}
		}
		break;
	}
		
	fin.close();
	
	       
	
} 
int grid:: number_of_rows(){

	return rows;// returns the number of rows in the file 
}

int grid:: number_of_columns(){

	return column;// retunrs number of columns in the file

}

string grid::given_character(int new_row, int new_column){// returns the characte at given location

	return new_matrix[new_row][new_column];
}

matrix<string>  grid::get_matrix(){//returns the matrix
	
	return new_matrix;
}
grid::~grid(){}
