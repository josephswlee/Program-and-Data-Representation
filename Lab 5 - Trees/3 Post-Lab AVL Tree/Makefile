#Joseph Lee
#Makefile - postLab 5

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=AVLNode.o AVLPathTest.o AVLTree.o

compile: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out
	@echo "ready to rock and roll"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h