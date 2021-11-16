# Joseph Lee (Sangwoo)
# sl5nj
# Lab 10 - In-Lab
# Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=huffmanNode.o huffmandec.o

compile: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out
	@echo "ready to rock and roll"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmandec.o: huffmandec.cpp