// util.h

#ifndef UTIL_H
#define UTIL_H 

#include <iostream>
#include "heap.h"

using namespace std;

void swap(struct ELEMENT *E1, struct ELEMENT *E2);
int parent(int i);
int left(int i);
int right(int i);
int heapSize(int *A);
void minHeapify(int *A, int i);

#endif
