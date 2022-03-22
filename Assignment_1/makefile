# Makefile with variables
P = test_app
OBJECTS = test_app.o MySAGInit.o MySAGInsert.o MySAGMax.o MySAGMin.o MySAGAvg.o MySAGFreq.o
CFLAGS = -g -Wall -O3
LDLIBS = 
CC = gcc

# Generate application
$(P): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(P) $(OBJECTS)

# Generate MySAGInit.o
MySAGInit.o: MySAGInit.c functions.h
	$(CC) $(CFLAGS) -c MySAGInit.c

# Generate MySAGInsert.o
MySAGInsert.o: MySAGInsert.c functions.h
	$(CC) $(CFLAGS) -c MySAGInsert.c

# Generate MySAGMax.o
MySAGMax.o: MySAGMax.c functions.h
	$(CC) $(CFLAGS) -c MySAGMax.c

# Generate MySAGMin.o
MySAGMin.o: MySAGMin.c functions.h
	$(CC) $(CFLAGS) -c MySAGMin.c

# Generate MySAGAvg.o
MySAGAvg.o: MySAGAvg.c functions.h
	$(CC) $(CFLAGS) -c MySAGAvg.c

# Generate MySAGFreq.o
MySAGFreq.o: MySAGFreq.c functions.h
	$(CC) $(CFLAGS) -c MySAGFreq.c

# Generate test_app.o
test_app.o: test_app.c functions.h
	$(CC) $(CFLAGS) -c test_app.c

clean:
	rm *.o $(P)