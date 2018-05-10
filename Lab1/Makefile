



#Author: Eamonn Gaynor

#Date: 08/10/2018

#File: Semaphore.h

#Brief: Makefile to run signal.cpp and Semaphore.cpp

#Bugs: N/A

#Licence: GNU (General Public License)


EXE = signal
CC = g++
CFLAGS = -std=c++11 -pthread -I.
CFILES = signal.cpp Semaphore.cpp


ALL: $(CFILES)
	$(CC) $(CFILES) $(CFLAGS) -o $(EXE) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL


CLEAN:
	rm *.o
