# Hospital Queue Management - Makefile

CC = gcc
CFLAGS = -Wall

all: hospital

hospital: main.o patient.o
	$(CC) $(CFLAGS) -o hospital.exe main.o patient.o

main.o: main.c patient.h
	$(CC) $(CFLAGS) -c main.c

patient.o: patient.c patient.h
	$(CC) $(CFLAGS) -c patient.c

clean:
	del *.o hospital.exe
