/*
    Joseph Lee (Sangwoo)
    sl5nj
    CS2150 Lab 10 - Pre-Lab
    huffmanNode.cpp
*/

#include "huffmanNode.h"

huffmanNode::huffmanNode() {
	character = '?';
	freq = 0;
	left = NULL;
	right = NULL;
}

huffmanNode::huffmanNode(int occur, char ch) {
	character = ch;
	freq = occur;
	left = NULL;
	right = NULL;
}

huffmanNode::~huffmanNode() {
	delete left;
	delete right;
}

int huffmanNode::getFreq() {
	return freq;
}