CC = gcc
output: main.c lab.o
	gcc -o output main.c lab.o
lab.o : lab.c 
	gcc -c lab.c 
clean:		
	rm *.o output
