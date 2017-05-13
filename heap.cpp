// This program inmplements all of the heap methods

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "heap.h"
#include "util.h"
#include <fstream>
using namespace std;

HEAP *h;

// Creates a new heap with capacity as specified and size 0
HEAP*  initialize(int n){
	HEAP* h = new HEAP();
	h->capacity = n;
	h->size = 0;
	h->E = new ELEMENT[n];
	cout << "New Heap Initialized\n" << endl;
	return h;
}



// Reads from HEAPinput.txt file into created heap
// If capacity of heap is less than the number of elements is HEAPinput.txt
// then capacity is expanded to accomodate the file
void readInArray(HEAP *A){
	string line;
	int heapSize = 0;
	
	ifstream inputFile("HEAPinput.txt");	// file object for "HEAPinput.txt
	if(inputFile.is_open()){				// check file has been opened
	getline(inputFile,line);				// read in first line (heap capacity)
	A->size = atoi(line.c_str());			
	A->capacity = max(A->size, A->capacity);// expand heap capacity if needed
	delete[] A->E;							
	A->E = new ELEMENT[A->capacity];		// create element pointer
	
	cout << "Capacity is "<< A->capacity << endl;	// write capacity and size to screen
	cout << "Size is : " << A->size << endl;		

	while(getline(inputFile,line)){			// read in each line and create elements
		A->E[heapSize].key = atoi(line.c_str());
		cout << A->E[heapSize].key << endl;	// write key ofeach element to screen
			heapSize++;						// expand heapsize counter
		}
	inputFile.close();						// close input file
	
	A->size = heapSize;						// update size of heap
	buildHeap(A);							// call buildheap, which in turn
}										// 		calls minHeap
	else cout << "Unable to open file! \n";	// if unable to open file, complain
}




// Builds new heap after reading in array 
void buildHeap(HEAP *A){
	int j = A->size / 2;					// from leftmost parent node, 
	for(int i = j; i>=1; i--){				// recursively heapify
		minHeapify(A, i);
	}
}

// Heapify for minHeap
void minHeapify(HEAP *A, int i){
	int smallest = i;						// current smallest is parent
	int l = left(i);						// identify left child
	int r = right(i);						// identify right child
	
	if(A->size >= l){						// check l is within bounds of array
		if(A->E[l-1].key < A->E[smallest-1].key){	// if l is smaller than current smallest
			smallest = l;							// then l is now smallest
		}	
	}
		
	if (A->size >= r){						// check r is within bounds of array
		if(A->E[r-1].key < A->E[smallest - 1].key){	// if r is smaller than current smalles
			smallest = r;							// smallest is now r
		}
	}	
	if(smallest != i){						// check if either l or r is smaller than parent
		//cout << "Swapping..." << A->E[smallest - 1].key << ", " << A->E[i-1].key << endl;// used for testing
		swap(&(A->E[smallest-1]),&(A->E[i-1]));	// swap parent and smallest
		minHeapify(A,smallest);	// recursively call to leaf nodes
	}
}





//	Prints out heap capacity, size and current heap information
void printHeap(HEAP *A){
	cout << "Heap Capacity: " << A->capacity << endl;
	cout << "Heap Size : " << A->size << endl;

	for(int i=0; i<A->size; i++){
		cout << A->E[i].key << " ";			// print out key of each element
	}
	cout << endl << endl;
}




// insert new element with specified key into the heap
void insert(HEAP *A, int key){
	if(A->size == A->capacity){				// if heap is already full, complain
		cout << "Could not insert key, heap is full!" << endl;
		return;
	}
	A->size = A->size + 1;					// if heap is NOT full, increase size by 1
	int i = A->size;						// determine where to place new element
	while((i > 1) && A->E[parent(i)-1].key < key){
		A->E[i-1] = A->E[parent(i)-1];
		i = parent(i);
	}
	A->E[i-1].key = key;
	
}




// delete minimum (root) element and print to screen
int deleteMin(HEAP *A){
	if(A->size < 1){						// if heap is empty, there is no min element
		cout << "Error: no elements to be extracted!" << endl;
		return -1;
	}
	int min = A->E[0].key;
	A->E[0] = A->E[A->size - 1];			// swap root and last element
	A->size = A->size - 1;					// reduce size of heap by 1
	minHeapify(A, 1);						// heapify to fix broken heap property
	return min;								// return minimum value
}





//	decreases priority (key) of element at index i 	
void decreaseKey(HEAP *A, int i, int key){
	if(key > A->E[i-1].key){				// check new key is ess than current key
		cout << "Error: new key is greater than current key!" << endl;
	}
	else{
		A->E[i-1].key = key;				// set the new key
		while(i>1 && (A->E[parent(i)-1].key > A->E[i-1].key)){	// place updated element in its correct place
			swap(&(A->E[i-1]), &(A->E[parent(i)-1]));
			i = parent(i);
		}
	}
}
