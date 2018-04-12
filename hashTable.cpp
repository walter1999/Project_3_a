// all my includes 
#include <string>
#include <iostream>
#include <vector>
#include "hashTable.h"
#include "Node.h"

// include hashTable 

template <class  T>
hashTable<T> :: hashTable(int size ){

	tableSize=(size/100);

	hashT(tableSize, Node* pointer);

	for(int i=0; i<tableSize; i++){			

								
			hashT[i]=new Node; 
			
			hashT[i]->word="empty";
			
			hashT[i]->next= NULL;

	 






}

void hashTable<T>  :: addItem( T item){
	int index= hash(item);

	if ( hashT[index]->word== "empty"){

		hashT[index]->word= item; 


	}
	else{

		Node* prt= hashT[index];

		Node*  newEntry= new Node;
		
		newEntry->word= item;
		
		newEntry->next= NULL;

		while( prt->next != NULL){

			prt= prt->next;
		
	
		}

		prt->next = newEntry;
	}
	

}

void hashTable :: deleteItem( T item) {
	
	int index= hash( item);

	Node* deleteEl;
	
	Node* temp1;

	Node* temp2;

	if( hashT[index]->word == "empty"){


		std::cout<< " Word was not found " << std::endl;
	}
	else if( hashT[index]->word == item && hashT[index]->next == NULL){
	
		hashT[index]->word= "empty" ; 
		
		std::cout<< " The item has been deleted" << std:: endl;

	}

	else if( hashT[index]->word == item){

		deleteEL = hashT[index];
	
		hashT[index]= hashT[index]->next;
		
		delete deleteEl;



	}
	else{

		temp1= hashT[index]->next;
		
		temp2= hashT[index];

		while( temp1 != NULL && temp1->name != item){


			temp2 = temp1;

			temp1 = temp1->next;

		}


		if( temp1 == NULL){

			std::cout<< " No item found " << std:: endl;

		}
		
		else {


			deleteEl = temp1;
		
			temp1 = temp1->next;

			temp2-> next = temp1;
			
			delete deleteEl;

			std:cout<< " the elemen " << item << " was removed from the list " << std:: endl; 

		}
	}




}



int hashTable<T> :: hash( T item){

	int hashValue=0;
	
	int index;
	
	for(int i =0; i<item.length(); i++){

		
		hashValue= hashValue + (int)item[i];
	}
	
	index= hashValue % tableSize;

	return index;


}


T hashTable<T> :: inList( T item ){

	int index= hash( item ); 

	Node* prt= hashT[index];

	while(prt != NULL){

		if(prt->word== item){
		
		std::cout<<" The element ", item, " was found in the table "<<std::endl;		

		}
		
		prt= prt->next; 
	

	}


}


hashTable<T> :: ~hashTable(){}







