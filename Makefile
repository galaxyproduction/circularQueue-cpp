run: queue
	./queue

queue: QueType.o QueDr.o
	g++ -Wall -ggdb -O0 -pedantic-errors -o queue QueType.o QueDr.o 

QueType.o: QueType.h QueType.cpp
	g++ -g -c QueType.cpp

QueDr.o: QueDr.cpp
	g++ -g -c QueDr.cpp

clean:
	rm -f *.o queue