# Generate application
main: main.o vInit.o vSum.o vAvg.o
	gcc -Wall -o main main.o vInit.o vSum.o vAvg.o

# Generate vInit.o
	gcc -Wall -c vInit.c

# Generate vAvg.o
	gcc -Wall -c vAvg.c

# Generate vSum.o
	gcc -Wall -c vSum.c
