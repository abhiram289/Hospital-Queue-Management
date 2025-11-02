# Makefile for Hospital Patient Queue Management
CC = gcc
CFLAGS = -Wall

all: hospital

hospital: main.o patient.o
	$(CC) $(CFLAGS) -o hospital main.o patient.o

main.o: main.c patient.h
	$(CC) $(CFLAGS) -c main.c

patient.o: patient.c patient.h
	$(CC) $(CFLAGS) -c patient.c

clean:
	rm -f *.o hospital
