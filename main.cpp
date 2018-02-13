#include "wordList.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include "grid.h"
#include "matrix.h"
#include <time.h>
void find_matches( grid& new_grid, wordList& new_dic){// global function that prints out all the matches 



	vector< std::string> words;// temporary array that holds the words found in the matrix

	std::string word;// temp variable to add content to vector words

	vector< vector<std::string> > temp_matrix= new_grid.get_matrix();// copies the matrix from class to a global variable

	vector<std::string> temp_dic= new_dic.getList();// copies the dictonary 

	for (int i=0;i < new_grid.get_rows(); i++){// outer loop to traverse matrix


		for (int j=0; j< new_grid.get_columns(); j++){// inner loop to traverse matrix

			for(int north=i; north<=0; north--){// loop to add words in the north direction

				if(north==i){// firts character is added as single letter

				 word= matrix[i][j]; 

				 words.push_back(word);
				
					}
				else if(north % new_grid.get_rows() -1 >0 && north==0){// wrapping around the edges 

					for(int k= new_grid.get_rows()-1; k<i;k--){

							word+= matrix[k][j];
							 words.push_back(word);

						}

				}
				
				else{// adds all the possible words in the north direction



					word+=matrix[north][j];


					words.push_back(word);
				}


				}
				
				
				for(int south=i; north<=new_grid.get_rows() -1 ; north++){// same a norht but possite direction

                                if(north==i){

                                 word= matrix[i][j];

                                 words.push_back(word);

                                        }
                                else if(i % new_grid.get_rows() -1 >0 && north==new_grid.get_rows()){// switch start and ending values. Reverse from north

                                        for(int k=0; k<i;k++){

                                                        word+= matrix[k][j];
                                                         words.push_back(word);

                                                }

                                }

                                else{



                                        word+=matrix[south][j];


                                        words.push_back(word);
                                }


                                }
			 for(int east=j; east<=new_grid.get_columns() -1; east++){// loop to travel right 

                                if(east==j){

                                 word= matrix[i][east];

                                 words.push_back(word);

                                        }
                                else if(j % new_grid.get_rows() -1 >0 && east==new_grid.get_columns() -1){// wrap around edges

                                        for(int k= 0; k<i;k++){

                                                        word+= matrix[i][k];
                                                         words.push_back(word);

                                                }

                                }

                                else{// adds all possible words in the east direction



                                        word+=matrix[i][east];


                                        words.push_back(word);
                                }


                                }

			     for(int west=j; westt<=0; west--){// does the oppsite of east

                                if(west==j){

                                 word= matrix[i][west];

                                 words.push_back(word);

                                        }
                                else if(j % new_grid.get_rows() -1 >0 && west==0){

                                        for(int k= new_grid.get_columns() -1; k<i;k--){

                                                        word+= matrix[i][k];
                                                         words.push_back(word);

                                                }

                                }

                                else{



                                        word+=matrix[i][west];


                                        words.push_back(word);

                               		 }


                                }


			}

		}

	}

	int found;// temporary value. Hold index of found element

	for(int i=0; i<=list.size();i++) {// loop that traverses the hold dictionary

	found=new_dic.binaryLook(dic, words[i],0, dic.size());// uses binary search to find the word
	
		if(found){// if the word was found print it to the screen

		std::cout<<dic[found]<<std::endl;

		}

	}









}
void search(int n){// global function that allows users to pick which sorting method to use

	string file_name;// name of file

	clock_t start_time_sort, start_time_find;// measures time 	
	
	std::cout<<" Enter the file you want to read from"<<std::endl;// prompts user

	std::cin>> file_name;// gets name from the user
	
	wordList  list;// instnace of a wordList
	
	grid obj(filename);// instance of grid

	start_time_sort= clock();// start time 
	
	switch(n){// switches n for which algo. to use 	

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

	int diff= clock()-start_time_sort;// difference gives toltal time to sort
	
	std::cout<<" Time to sort: " << diff << std::endl;// prints it to the screen 
	// function call to find_matches 
		
	start_time_find=clock//
	
	find_matches(obj , list));// fucntion call to find matches 
	
	int diff_2= clock()-start_time_find;// time to find matches 

	std::cout<<" Time to search for all the words : " << diff_2 << std::endl;

	int total_time= diff + diff_2;// total time 
	
	std::cout<<" Total time : " << total_time << std::endl;// prints it to the screen 
}

int main(){

	int option;// user input 

	std::cout<<" Enter 1 for merge sort, enter 2 for quick sort, enter 3 for insertio sort"<<std::endl;

	std::cin>>option // switches the input 

	search(option); // call search

	return 0;



}
