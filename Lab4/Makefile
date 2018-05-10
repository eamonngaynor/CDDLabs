
#Author: Eamonn Gaynor                                                          
#Date created: 08/10/2017                                                       
#Bugs: N/A                                                                      
#Purpose: Makefile to run barrier.cpp and Semaphore.cpp                            
#File: Makefile                                                                 
#License: GPL - General Public License                                          
                                                                                
                                                                                
EXE = Barrier
CC = g++
CFLAGS = -std=c++11 -pthread -I.
CFILES = barrier.cpp Semaphore.cpp


ALL: $(CFILES)
	$(CC) $(CFILES) $(CFLAGS) -o $(EXE) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL


CLEAN:
	rm *.o
