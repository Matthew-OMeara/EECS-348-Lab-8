#  This is a comment line
CC=g++
# CFLAGS will be the options passed to the compiler
CFLAGS=-c -Wall

all: football temp

football: football.o
	$(CC) football.o -o football

football.o: football.c
	$(CC) $(CFLAGS) football.c

temp: temp_converter.o
	$(CC) temp_converter.o -o temp

temp_converter.o: temp_converter.c
	$(CC) $(CFLAGS) temp_converter.c

clean:
	rm -rf *.o football temp
