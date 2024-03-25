all: test

test: test.o fonction.o
	g++ -o test test.o fonction.o
	
test.o: test.cpp fonction.h
	g++ -c test.cpp

fonction.o: fonction.cpp fonction.h
	g++ -c fonction.cpp
