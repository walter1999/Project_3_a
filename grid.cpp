#include <vector>
#include <string>
#include "grid.h"
// include fstream

grid::grid(){

	ifstream fin;// creates ifstream object

	std::cout<< " Enter the name of the file that you want to read in"<<std::endl;

	string file_name;// file that the user wants to read

	std::cin<<file_name;// assigns the name to file_name

	fin.open(file_name.c_str());// opens the file input 
	
	if(!fin){//if the file could be open then the following message will be display 
	
	std::cout<<" File could not be open"<<std::endl;


	}

	fin >> rows >> columns;// reads the first line which contanis the number of rows and columns

	for(int i=0; i<row; i++){//outer loops 

	for(int j=0; j<columns){// inner loops 
		
	fin>>matrix[i][j];// inputs letter into matrix 


		}	
	}

	
}
        
int grid:: number_of_rows(){

	return rows;// returns the number of rows in the file 
}

int grid:: number_of_columns(){

	return columns;// retunrs number of columns in the file 

}

string grid::given_character(int new_row, int new_column)){

	return matrix[row][column];




}
