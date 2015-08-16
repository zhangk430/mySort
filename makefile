IDIR=.
CC=g++
CFLAGS=-I$(IDIR)

DEPS=sort.h
OBJ=main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
bin/sort : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY : clean
clean :
	-rm -f *.o *~ core
