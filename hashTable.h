// all my includes
#include <string>
#include <iostream>
#include <vector>
#include <string> 
// include node 
#include "Node.h"
 

template <class T>

class hashTable{
	private:
	 std::vector <Node*> hashT; 

	 int tableSize; 



	public:

	hashTable(int Size);

	void addItem(T item);

	void deleteItem(T index);

	int hash(T item); 
	
	T inList(T item);
	
	~hashTable();







};
