# Makefile with variables
P = main
OBJECTS = main.o vInit.o vSum.o vAvg.o
CFLAGS = -g -Wall -O3
LDLIBS = 
CC = gcc

# Generate application
$(P): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(P) $(OBJECTS)

# Generate vInit.o
vInit.o: vInit.c funcoes.h
	$(CC) $(CFLAGS) -c vInit.c

# Generate vAvg.o
vAvg.o: vAvg.c funcoes.h
	$(CC) $(CFLAGS) -c vAvg.c

# Generate vSum.o
vSum.o: vSum.c funcoes.h
	$(CC) $(CFLAGS) -c vSum.c

# Generate main.o
main.o: main.c funcoes.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o $(P)