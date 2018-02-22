//
//  heap.hpp
//  Project_3
//
//  Created by Thomas Campion on 2/19/18.
//  Copyright © 2018 Thomas Campion. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;



class heap{
public:
    vector<string> hsorted;
    vector<string> unsort;
    
    int parent(int num);
    int left(int num);
    int right(int num);
    string nth(int nth, bool SoU); //SoU determinse whether you are searching the sorted or unsorted lists
    
    void initializeMaxHeap(vector<string> unsorted);
    
    void maxHeapify(vector<string> &unsorted, int offset);
    
    void minHeapify(vector<string> &unsorted, int cur, int offset);
    
    void buildmaxh(vector<string> &unsorted);
    
    void heapSort(vector<string> &unsorted, int n);
    
};

#endif /* heap_hpp */
