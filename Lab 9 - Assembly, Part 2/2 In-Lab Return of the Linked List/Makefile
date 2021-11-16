# Joseph Lee (Sangwoo)
# sl5nj
# In-Lab 9

# Makefile for CS 2150 In-lab 9

CXX=clang $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=linkedlist.o

compile: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out
	@echo "ready to rock and roll"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

linkedlist.o: linkedlist.c