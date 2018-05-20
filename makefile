PROG1=frequencies
PROG2=huffman
PROG3=encode
PROG4=decode
CC=g++
CPPFLAGS=-g -Wall -std=c++11

.PHONY: all


all:
	$(CC) $(CPPFLAGS) frequencies.cpp -o $(PROG1)
	$(CC) $(CPPFLAGS) huffman.cpp -o $(PROG2)
	$(CC) $(CPPFLAGS) encode.cpp -o $(PROG3)
	$(CC) $(CPPFLAGS) decode.cpp -o $(PROG4)

clean:
	rm -f *.o $(PROG1) core
	rm -f *.o $(PROG2) core
	rm -f *.o $(PROG3) core
	rm -f *.o $(PROG4) core