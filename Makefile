
CC=g++

debug: CC += -g
debug: all


all: main

main:
	$(CC) main.cpp -o finish.out

clean:
	rm -rf *.out
	rm -rf *.o
	rm -rf *.dSYM
