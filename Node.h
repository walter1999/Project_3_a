#ifndef Node_h
#include <cstddef>
#include <string>
#define Node_h


template <typename T>

class Node{// creates node class
public:
     T word;
    Node *next;// node pointer

    Node() : next(NULL){}// default constructor sets next pointer to null
    
   
};

#endif /* Node_h */

