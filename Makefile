
CC=g++

all: main

main:
	$(CC) main.cpp -o finish.out

clean:
	rm -rf *.out
	rm -rf *.o
