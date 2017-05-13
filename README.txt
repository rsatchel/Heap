This program is designed to implement a Heap in the form of a min Heap.

It contains a terminal user interface with the following commands:
	
	S		stops program and returns to command prompt
	
	C i		creates a new heap with capacity i (where i is an integer)

	R		reads in heap data from file "HEAPinput.txt"

	W		writes heap data (capacity, size and element keys) to screen

	I n		inserts new element with key n (where n is an integer) into heap

	D		deletes min value from heap

	K i n 	decreases key of element with index i to new key value n (where both i and n are integers)

	///////////////////////////////////////////////////

	The heap operations are in heap.h and heap.cpp.
	Various utility functions are in util.h and util.cpp

	//////////////////////////////////////////////////////

	Make sure that your input file is named "HEAPinput.txt"

	Makefile commands are as follows:
		make
		make cleanAll
		make clean (then name of object file)
