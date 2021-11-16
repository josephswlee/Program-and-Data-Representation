/*
    Joseph Lee (Sangwoo)
    sl5nj
    CS2150 Lab 10 - Post-Lab
    huffmanNode.h
*/

#pragma once

#include <stddef.h>

using namespace std;

class huffmanNode {
public:
	huffmanNode();
	huffmanNode(int occur, char ch); //constructor 
 	~huffmanNode(); //destructor
 	int getFreq(); //return frequency
 	char getChar(); //return character

	char character; //represent the letters
	int freq; //represent the number of occurence
	huffmanNode *left; // left child
	huffmanNode *right; // right child

	//friend class binary_heap;
	//friend class huffmanTree;
};