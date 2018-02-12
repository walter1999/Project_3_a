




#include <vector>
#include <string>
// security code

class grid{ //declares class

private:
	vector<vector<string> > matrix;// matrix of vectors to store letters

	int column;// number of columns

	int rows;// number of words

public:
	grid(std::string new_file);// constructor that establshes the  matrix
	
	int number_of_rows();// returns the number of rows 

	int number_of_columns()//returns the number of columns

	string given_character(int new_row, int new_column);// returns a character at given location

	~grid();// destroys the object. Does not do anything else

};

