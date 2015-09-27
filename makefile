IDIR=.
CC=g++ -std=c++11
CFLAGS=-I$(IDIR)

DEPS=sort.h intro2alg.h heap.h sort.hpp
OBJ=main.o intro2alg.o

bin/sort : $(OBJ) 
	$(CC) -o bin/sort $(OBJ) $(CFLAGS)
main.o: main.cpp $(DEPS)
	$(CC) -c main.cpp
intro2alg.o: intro2alg.cpp $(DEPS)
	$(CC) -c intro2alg.cpp
.PHONY : clean
clean :
	-rm -f *.o *~ core
