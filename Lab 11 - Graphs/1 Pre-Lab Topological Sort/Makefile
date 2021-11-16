# Joseph Lee (Sangwoo)
# sl5nj
# Lab 11 - Pre-Lab
# Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OFILES=topological.cpp

.SUFFIXES: .o .cpp

main: $(OFILES) 
	  $(CXX) $(OFILES) 
	  doxygen

topological.o: topological.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out