# Makefile with variables
P = test_app
OBJECTS = test_app.o MySAG.o 
CFLAGS = -g -Wall -O3
LDLIBS = 
CC = gcc

# Generate application
$(P): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(P) $(OBJECTS)

# Generate MySAG.o
MySAGInit.o: MySAG.c functions.h
	$(CC) $(CFLAGS) -c MySAG.c

# Generate test_app.o
test_app.o: test_app.c functions.h
	$(CC) $(CFLAGS) -c test_app.c

clean:
	rm *.o $(P)