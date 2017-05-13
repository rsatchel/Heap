run: 		main.o util.o heap.o
	g++ main.cpp heap.cpp util.cpp -o run

clean:	
	rm *.o

cleanAll:
	rm *.o run
