#Joseph Lee
#Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
OBJECTS=TreeCalc.o TreeCalcTest.o TreeNode.o

compile: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	@echo "program is up and running"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
	$(CXX) -c TreeCalc.cpp

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
	$(CXX) -c TreeCalcTest.cpp

TreeNode.o: TreeNode.cpp TreeNode.h
	$(CXX) -c TreeNode.cpp