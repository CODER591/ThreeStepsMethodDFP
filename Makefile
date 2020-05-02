
CC=g++

all: main

debug: CC += -g
debug: main

main:
	$(CC) main.cpp -o finish.out

clean:
	rm -rf *.out
	rm -rf *.o
	rm -rf *.dSYM
