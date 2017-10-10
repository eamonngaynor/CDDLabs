#Author: Eamonn Gaynor
#Date created: 08/10/2017
#Bugs: N/A
#Purpose: Makefile to run signal.cpp and Semaphore.cpp

CC=g++
CFLAGS= -std=c++11 -pthread
FILES= signal.cpp Semaphore.cpp
OUT_EXE=signal

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(CFLAGS)
