all: monprog.out

monprog.out: main.o TableauDynamique.o ElementTD.o
	g++ -g main.o TableauDynamique.o ElementTD.o -o monprog.out
	
main.o: main.cpp TableauDynamique.h ElementTD.h
	g++ -g -Wall -c main.cpp
	
TableauDynamique.o : TableauDynamique.h TableauDynamique.cpp ElementTD.h
	g++ -g -Wall -c TableauDynamique.cpp
	
ElementTD.o : ElementTD.h ElementTD.cpp
	g++ -g -Wall -c ElementTD.cpp
	
clean:
	rm *.o

veryclean: clean
	rm *.out
