#include<iostream>
#include"util.h"

using namespace std;


// swaps 2 elements
void swap(struct ELEMENT *E1, struct ELEMENT *E2){
	int temp = E1->key;
	E1->key = E2->key;
	E2->key = temp;
}



// return parent of current node
int parent(int i){
	int var1 = (i)/2; 
	return var1;
}



// return left child of current node
int left(int i){
	int var2 = 2*i;//+1;
	return var2;
}



// return right child of current node
int right(int i){
	int var3 = 2 * i+1;
	return var3;
}



// return max of 2 parameters
// used to compare heap capacity and size
// to expand heap capacity if needed
int max(int a, int b){
	if (a > b) return a;
	else return b;
}
