all: monprog.out

monprog.out : main.o Liste.o Element.o
	g++ -g main.o Liste.o Element.o -o monprog.out
	
main.o : main.cpp Liste.h Element.h
	g++ -g -Wall -c main.cpp
	
Liste.o : Liste.h Liste.cpp Element.h
	g++ -g -Wall -c Liste.cpp
	
Element.o : Element.h Element.cpp
	g++ -g -Wall -c Element.cpp
	
clean : rm *.o

veryclean : clean
	rm *.out
	

