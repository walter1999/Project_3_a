#include "wordList.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include "grid.h"
void find_matches( grid new_grid(std::string new_file), vector< vector <string> >  new_list){// global function that prints out all the matches 



	vector< std::string> words;
	int north,south,east,west;

	for (int i=0;i < new_grid.get_rows(); i++){


		for (int j=0; j< new_grid.get_columns(); j++){

			for(int north=
				
				



			}





		}









	}



	for(int i=0; i<=list.size();i++) {












}
void search(int n){

	string file_name;
	
	std::cout<<" Enter the file you want to read from"<<std::endl;

	std::cin>> file_name;
	
	wordList  list;

	switch(n){

	case 1: 
		list.merge_sort(list.getFile());
		break;
	case 2: 
	
	 list.quickSor(list.getFile(),0, list.getFile().size);
	 break;

	case 3:

	list.insertionSort(list.getFile())
	break;

	}
	// function call to find_matches 

	find_matches( grid new_grid(file_name), list.getList());

}

int main(){

	int option;

	std::cout<<" Enter 1 for merge sort, enter 2 for quick sort, enter 3 for insertio sort"<<std::endl;

	std::cin>>option 

	search(option);


	


	return 0;



}
