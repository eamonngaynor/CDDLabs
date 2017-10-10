#Author: Eamonn Gaynor
#Date created: 08/10/2017
#Bugs: N/A
#Purpose: Makefile to run rend.cpp and Semaphore.cpp



CC=g++
CFLAGS= -std=c++11 -pthread
FILES= rend.cpp Semaphore.cpp
OUT_EXE=rend

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(CFLAGS)

clean:
	rm *.o
