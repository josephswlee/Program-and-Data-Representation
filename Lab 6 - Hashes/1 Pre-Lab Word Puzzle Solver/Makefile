#Joseph Lee
#Makefile
#preLab 6

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=hashTable.o timer.o wordPuzzle.o

compile: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out
	@echo "ready to rock and roll"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h