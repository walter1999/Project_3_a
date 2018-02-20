//
//  heap.cpp
//  Project_3
//
//  Created by Thomas Campion on 2/19/18.
//  Copyright © 2018 Thomas Campion. All rights reserved.
//

#include "heap.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <tgmath.h>


int heap::parent(int num){
    int par = floor(num/2);
    return par;
}
int heap::left(int num){
    int i;
    i = num*2;
    
    return i;
}
int heap::right(int num){
    int i;
    i = num*2;
    return i;
}
string heap::nth(int nth, bool SoU){
    if(SoU == true){
        return hsorted[nth];
    }
    else{
        return unsort[nth];}
}

void heap::initializeMaxHeap(vector<string> unsorted){
    
    unsort = unsorted;
}

void heap::maxHeapify(vector<string> &unsorted, int n, int i){
    
    int largest = i;
    int r = right(i);
    int l = left(i);
    
    if (l < n && unsorted[l] > unsorted[largest])
        largest = l;
    
    // If right child is larger than largest so far
    if (r < n && unsorted[r] > unsorted[largest])
        largest = r;
    
    // If largest is not root
    if (largest != i)
    {
        swap(unsorted[i], unsorted[largest]);
        
        // Recursively heapify the affected sub-tree
        maxHeapify(unsorted, n, largest);
    }
}

void heap::minHeapify(vector<string> &unsorted, int n, int i){
    
    int smallest = i;
    int r = right(i);
    int l = left(i);
    
    if (l < n && unsorted[l] < unsorted[smallest])
        smallest = l;
    
    // If right child is smaller than smallesest so far
    if (r < n && unsorted[r] < unsorted[smallest])
        smallest = r;
    
    // If largest is not root
    if (smallest != i)
    {
        swap(unsorted[i], unsorted[smallest]);
        
        // Recursively heapify the affected sub-tree
        minHeapify(unsorted, n, smallest);
    }
}

void heap::heapSort(vector<string> &unsorted, int n){
    
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(unsorted, n, i);
    
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(unsorted[0], unsorted[i]);
        
        // call max heapify on the reduced heap
        maxHeapify(unsorted, i, 0);
    }
}
