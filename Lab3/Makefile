
#Author: Eamonn Gaynor                                                          
#Date created: 08/10/2017                                                       
#Bugs: N/A                                                                      
#Purpose: Makefile to run mutex.cpp and Semaphore.cpp                            
#File: Makefile                                                                 
#License: GPL - General Public License                                          
                                                                                
                                                                                
EXE = TheMutex
CC = g++
CFLAGS = -std=c++11 -pthread -I.
CFILES = mutex.cpp Semaphore.cpp


ALL: $(CFILES)
	$(CC) $(CFILES) $(CFLAGS) -o $(EXE) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL


CLEAN:
	rm *.o
