// main.cpp

#include <iostream>
#include "heap.h"
#include <stdlib.h>
#define INT_MAX 32767
using namespace std;

struct HEAP *x;
int main(){
	char command;
	cout << endl << "CSE310 Assignment 2" << endl;
	cout << "Implementing Heap Data Structure" << endl << endl;
	
	
	do{

	cout << "Enter a command..." << endl;
	cin >> command;
	
	switch(command){
		case 'S':
		cout << "STOP" << "\n" << endl;
		break;

		case 'C':
		        int capacity;
 		        cin >> capacity;
  
 		        if(capacity < INT_MAX){
 		             cout << "CREATING HEAP" << endl;
 		             cout <<"Capacity: " << capacity << "\n" << endl;
 	 
 		             if (x != NULL){
 		                 delete[] x->E;
 		                 delete x;
 		             }
 		             x = initialize(capacity);
 		             break;
 		         }
  
  
 	         else{
 	             cout << "ERROR!! Capacity larger than maximum allowed inte    ger on 64 bit machine.\nChoose a smaller capacity\n\n" << endl;
 	             capacity = 0;
 	             break;
 	         }

		
		case 'R':
		cout << "READ IN ARRAY" << "\n" << endl;
		if(x == NULL){
			cout << "No heap exists to read data into!\nCreate a heap first.\n\n" << endl; 
			break;
		}
		readInArray(x);
		break;

		case 'W':
		cout << "WRITE HEAP" << "\n" << endl;
		if(x == NULL){
			cout << "No heap exists to write from!\nCreate a heap first.\n"  << endl;
			break;
		}
		printHeap(x);
		break;

		case 'I':
		int key;
		cin >> key;
		cout << "INSERT" << endl;
		cout << "Key = " << key << "\n" << endl;
		
		if (x == NULL){
			cout << "Error! No heap to insert elements into!" << endl;
			cout << "Create a heapfirst.\n\n " << endl; 
			break;
		}
		insert(x,key);
		break;

		case 'D':
		int min;
		cout << "DELETE" << "\n" << endl;
		if(x == NULL){
			cout << "No heap exists! \nCreate a heap first.\n\n" << endl;	
			break;
		}
		min = deleteMin(x);
		if(min != -1){
			cout << "delete " << min << endl;
		}
		break;

		case 'K':
		int index, value;
		cin >> index >> value;
		cout << "DECREASE KEY" << endl;
		if(x == NULL){
			cout << "No heap exists!\nCreate a heap first.\n\n" << endl;
			break;
		}
		decreaseKey(x, index, value);
		cout << "Index: " << index << endl;
		cout << "Value: " << value << "\n" << endl;
		break;

		default:
		cout << "Enter a valid command..." << "\n" << endl;
		break;
			
	}
	}while (command != 'S');

	return 0;
}
