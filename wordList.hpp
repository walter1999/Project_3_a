//
//  wordList.hpp
//  Project_3
//
//  Created by Thomas Campion on 2/8/18.
//

#ifndef wordList_hpp
#define wordList_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class wordList{
private:
    
    vector <string> s_file;
    vector <string> *quick;
    vector <string> *merge;
    vector <string> *insert;
    
public:
    
    wordList();
    
    ~wordList();
    
    void readFile(string Dir);
    
    vector <string> &getFile();
    
    friend std::ostream &operator << (std::ostream& str, wordList &word);
    
    void quickSort(vector<string> &sort, int start, int finish);
    
    void mergeSort(vector<string> &sort);
    
    void insertionSort(vector<string> &sort);
    
    int binaryLook(vector<string> &sort, string look, int begin, int end);

    
};

#endif /* wordList_hpp */
