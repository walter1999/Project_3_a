//
//  wordList.cpp
//  Project_3
//
//  Created by Thomas Campion on 2/8/18.
//

#include "wordList.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;

    
void wordList::readFile(string Dir){
     //creating a temp vector to store file, and line to store line strings
    vector <string> temp;
    string line;
    
    std::ifstream myfile;
    
    myfile.open(Dir.c_str());
    
        if(!myfile) //Always test the file open.
        {
            std::cout<<"Error opening output file"<<std::endl;
            system("pause");
        }
//while the file is inputting strings into line it will continue to add to the vector
        while(myfile >> line)
        {
            temp.push_back(line);
        }
 //closes file
    myfile.close();
// sets the class vector equal to the stored values
        s_file = temp;
    

    }
//returns stored vector of the file strings
vector<string> &wordList::getFile(){
        
        return s_file;

    }
//overloading the cout operator
std::ostream& operator << (std::ostream& str, wordList &word){
        
        int num;
    
        vector<string> print = word.getFile();
    
        num = print.size();
    
        for(int i = 0; i<num; i++){
            std::cout<<print[i]<<std::endl;
        }
    
    return str;
}
    
void wordList::quickSort(vector<string> &sort, int start, int finish){
    //setting the right left and pivot values of quicksort
    int left=start;
    int right=finish;
    int pivot=finish;
    // iterating through and comparing values to the pivout
        while (left < right) {
            while (sort[left]  < sort[pivot]) left++;
            while (sort[right] > sort[pivot]) right--;
            if (left <= right) {
                //swapping values on either side of the sorted portions
                string temp1 = sort[left];
                sort[left] = sort[right];
                sort[right] = temp1;
                left++;
                right--;
            }
        }
        //calling quicksort for the higher and lower portions that arent sorted
        if (sort[start] < sort[right]) quickSort(sort,start,right);
        if (sort[left] < sort[finish]) quickSort(sort,left,finish);
    //setting value of the class equal to that
    s_file = sort;
    
    }


vector<string> wordList::mergeSort(vector<string> &input){
    //makes sure that you try to split and sort a vector that is less than 1
    if(input.size()<=1) return input;
    
    vector<string> output(input.size());
    
    //Split Vector//
    int midpoint=0.5*input.size();
    vector<string> input_left(input.begin(),input.begin()+midpoint);
    vector<string> input_right(input.begin()+midpoint,input.end());
    //calls mergeSort again until the input size <= 1, calls recursively
    input_left=mergeSort(input_left);
    input_right=mergeSort(input_right);
    //merges the smaller vectors back into the original but sorted
    merge(input_left.begin(),input_left.end(),input_right.begin(),input_right.end(),output.begin());
    
    if(output.size() == s_file.size()){
        s_file = output;}
    
    
    return output;
    
    }

void wordList::insertionSort(vector<string> &sort){
    
    int j;
    string val;
    //determining how big the for loop is
    int size = sort.size();
    
    //iterate through entire list
    for(int i = 0; i < size; i++){
        //creating the comparitive value
        val = sort[i];
        //
        j = i - 1;
        
        while(j >= 0 && sort[j] > val){
            
            sort[j + 1] = sort[j];
            
            std::cout<<sort[j]<<" "<<val<<std::endl;
            
            j = j - 1;
         
            iteration++;
        }//end while
        
        sort[j + 1] = val;
        
    }//end for
    
    s_file = sort;
    }
    
int wordList::binaryLook(vector <string> &sort, string look, int begin, int end){
    //making sure that there are values to search and if the value is not in the data to return -1
    if(begin >= end)
    { return -1;}
    else
    { //setting the middle value
        int mid = (begin + end) / 2;
        if (look == sort[mid])
        { return mid;}
       //recursively searching the halves if the value was less than that of the middle
        else if(look < sort[mid])
        { return binaryLook(sort, look, begin, mid);}
        
        else if(look > sort[mid])
        { return binaryLook(sort, look, mid + 1, end);}
        
    }
    
    return 0;
}

wordList::wordList(){}

wordList::~wordList(){}
    
    

