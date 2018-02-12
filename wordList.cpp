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
    
    s_file = sort;
    
    }


vector<string> wordList::mergeSort(vector<string> &input){
    if(input.size()<=1) return input;
    
    vector<string> output(input.size());
    
    //Split Vector//
    int midpoint=0.5*input.size();
    vector<string> input_left(input.begin(),input.begin()+midpoint);
    vector<string> input_right(input.begin()+midpoint,input.end());
    
    input_left=mergeSort(input_left);
    input_right=mergeSort(input_right);
    merge(input_left.begin(),input_left.end(),input_right.begin(),input_right.end(),output.begin());
    
    if(output.size() == s_file.size()){
        s_file = output;}
    
    
    return output;
    
    }

void wordList::insertionSort(vector<string> &sort){
    
    int j;
    string val;
    int iteration = 0;
    
    int size = sort.size();
    
    //iterate through entire list
    for(int i = 0; i < size; i++){
        val = sort[i];
        
        j = i - 1;
        
        while(j >= 0 && sort[j] > val){
            
            sort[j + 1] = sort[j];
            
            std::cout<<sort[j]<<" "<<val<<std::endl;
            
            j = j - 1;
         
            iteration++;
        }//end while
        
        sort[j + 1] = val;
        
    }//end for
    std::cout<<iteration<<std::endl;
    
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
    
    

