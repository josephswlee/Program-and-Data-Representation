# Joseph Lee (Sangwoo)
# sl5nj
# Lab 11 - In-Lab
# Makefile

CXX=clang++ -std=c++11 $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OFILES=traveling.cpp middleearth.cpp

.SUFFIXES: .o .cpp

main: $(OFILES) 
	  $(CXX) $(OFILES) 
	  doxygen

traveling.o: traveling.cpp middleearth.h
middleearth.o: middleearth.cpp middleearth.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out