
#Author: Eamonn Gaynor                                                          
#Date created: 07/05/2018                                                       
#Bugs: N/A                                                                      
#Purpose: Makefile to run SafeBuffer.cpp and Semaphore.cpp                            
#File: Makefile                                                                 
#License: GPL - General Public License                                          
                                                                                
                                                                                
EXE = SafeBuffer
CC = g++
CFLAGS = -std=c++11 -pthread -I.
CFILES = SafeBuffer.cpp Semaphore.cpp


ALL: $(CFILES)
	$(CC) $(CFILES) $(CFLAGS) -o $(EXE) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL


doc:ALL
	if [ -e "Doxyfile" ] ; then  rm 'Doxyfile';  fi
	cp ~/Doxyfile .
	if [ -d "docs" ] ; then  rm -rf 'docs';  fi
	mkdir docs
	echo "PROJECT_NAME = Lab5" >> Doxyfile
	echo "PROJECT_BRIEF = Producer/Consumer program" >> Doxyfile
	echo "PROJECT_NUMBER = 5" >> Doxyfile
	echo "OUTPUT_DIRECTORY = ./docs"  >> Doxyfile
	echo "EXTRACT_ALL = YES" >> Doxyfile
	echo "RECURSIVE = YES" >> Doxyfile
	echo "SOURCE_BROWSER = YES" >> Doxyfile
	echo "GENERATE_LATEX = NO" >> Doxyfile
	echo "DOT_IMAGE_FORMAT = svg" >> Doxyfile
	echo "INPUT = ." >> Doxyfile
	doxygen Doxyfile


CLEAN:
	rm *.o
