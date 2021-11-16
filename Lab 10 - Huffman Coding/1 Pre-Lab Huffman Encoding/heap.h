/*
    Joseph Lee (Sangwoo)
    sl5nj
    CS2150 Lab 10 - Pre-Lab
    heap.h
*/

#pragma once
#include <vector>
#include "huffmanNode.h"

using namespace std; 

class binary_heap {
private:
	vector<huffmanNode*> heap;
	unsigned int heap_size;
	void percolateUp(int hole);
	void percolateDown(int hole);

	//friend class huffmanTree;

public:
	binary_heap(); // constructor
	binary_heap(vector<huffmanNode*> vec); // parameterized constructor
	~binary_heap(); // destructor

	void insert(huffmanNode* x);
	huffmanNode* findMin();
	huffmanNode* deleteMin();
	unsigned int size();
	void makeEmpty();
	bool isEmpty();
	void print();
};