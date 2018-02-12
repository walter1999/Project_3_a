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
        
    vector <string> temp;
    string line;
    
 
    
    std::ifstream myfile;
    
    myfile.open(Dir.c_str());
    
        if(!myfile) //Always test the file open.
        {
            std::cout<<"Error opening output file"<<std::endl;
            system("pause");
        }
    
        while(myfile >> line)
        {
            temp.push_back(line);
        }
    
    myfile.close();
    
        s_file = temp;
    

    }

vector<string> &wordList::getFile(){
        
        return s_file;

    }

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
        
    int left=start;
    int right=finish;
    int pivot=finish;
    
        while (left < right) {
            while (sort[left]  < sort[pivot]) left++;
            while (sort[right] > sort[pivot]) right--;
            if (left <= right) {
                string temp1 = sort[left];
                sort[left] = sort[right];
                sort[right] = temp1;
                left++;
                right--;
            }
        }
        if (sort[start] < sort[right]) quickSort(sort,start,right);
        if (sort[left] < sort[finish]) quickSort(sort,left,finish);
    
    }
/*
void wordList::mergeSort(vector<string> &sort){
        
        int i = 0;  // LHS index
        int j = 0;  // RHS index
        
        while ((i < LHS.size()) && (j < RHS.size()))
        {
            if (LHS[i] < RHS[j])
            {
                ToReturn.push_back(LHS[i]);
                ++i;
            }
            else
            {
                ToReturn.push_back(RHS[j]);
                ++j;
            }
        }
        
        while (i < LHS.size())
        {
            sort.push_back(LHS[i]);
            ++i;
        }
        
        while (j < RHS.size())
        {
            sort.push_back(RHS[j]);
            ++j;
        }

        
    }
*/
void wordList::insertionSort(vector<string> &sort){
    
  
    
    int j;
    string val;
    
    int size = sort.size();
    
    //iterate through entire list
    for(int i = 1; i < size; i++){
        val = sort[i];
        
        j = i - 1;
        
        while(j >= 0 && sort[j] > val){
            
            sort[j + 1] = sort[j];
            
            std::cout<<sort[j]<<" "<<val<<std::endl;
            
            j = j - 1;
            
        }//end while
        
        sort[j + 1] = val;
        
    }//end for

    s_file = sort;
    }
    
int wordList::binaryLook(vector <string> &sort, string look, int begin, int end){
    
    if(begin >= end)
    { return -1;}
    else
    {
        int mid = (begin + end) / 2;
        if (look == sort[mid])
        { return mid;}
        
        else if(look < sort[mid])
        { return binaryLook(sort, look, begin, mid);}
        
        else if(look > sort[mid])
        { return binaryLook(sort, look, mid + 1, end);}
        
    }
    
    return 0;
}

wordList::wordList(){}

wordList::~wordList(){}
    
    

