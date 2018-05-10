#Author: Eamonn Gaynor
#Date created: 08/10/2017
#Bugs: N/A
#Purpose: Makefile to run rend.cpp and Semaphore.cpp
#File: Makefile
#License: GPL - General Public License


EXE=Rendevous
CC=g++
CFLAGS= -std=c++11 -pthread
CFILES=Rendevous.cpp Semaphore.cpp
HFILES=Semaphore.h

ALL: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $(EXE)
CLEAN:
	rm *.o


