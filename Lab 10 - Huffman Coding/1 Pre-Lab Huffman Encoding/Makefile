# Joseph Lee (Sangwoo)
# sl5nj
# Lab 10 - Pre-Lab
# Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=heap.o huffmanNode.o huffmanenc.o

compile: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out
	@echo "ready to rock and roll"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

heap.o: heap.cpp heap.h huffmanNode.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h