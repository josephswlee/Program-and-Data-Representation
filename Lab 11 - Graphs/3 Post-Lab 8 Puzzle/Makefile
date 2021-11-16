# Joseph Lee (Sangwoo)
# sl5nj
# Lab 11 - Post-Lab
# Makefile

CXX=clang++ -std=c++11 $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OFILES=8puzzle.cpp

.SUFFIXES: .o .cpp

main: $(OFILES) 
	  $(CXX) $(OFILES) 
	  doxygen

8puzzle.o: 8puzzle.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out