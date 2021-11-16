#Joseph Lee
#Makefile - inlab5

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=BinaryNode.o BinarySearchTree.o BSTPathTest.o

compile: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out
	@echo "program is up and running"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h