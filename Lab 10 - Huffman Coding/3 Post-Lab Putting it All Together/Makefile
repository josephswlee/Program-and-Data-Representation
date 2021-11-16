# Joseph Lee (Sangwoo)
# sl5nj
# Lab 10 - Post-Lab
# Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=huffmanNode.o heap.o
.SUFFIXES: .o .cpp
tartget: encoder decoder
encoder : huffmanenc.o huffmanNode.o heap.o
	$(CXX) $(OFILES) huffmanenc.o huffmanNode.o heap.o -o encoder
	@echo "Huffman encoder is up and running"
decoder : huffmandec.o huffmanNode.o
	$(CXX) $(OFILES) huffmandec.o huffmanNode.o -o decoder
	@echo "Huffman decoder is up and running"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

heap.o: heap.cpp heap.h huffmanNode.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmandec.o: huffmandec.cpp huffmanNode.h
huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h