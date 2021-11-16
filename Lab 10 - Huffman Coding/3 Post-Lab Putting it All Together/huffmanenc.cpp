/*
    Joseph Lee (Sangwoo)
    sl5nj
    CS2150 Lab 10 - Post-Lab
 	huffmanenc.cpp
*/

#include <iostream>
#include <fstream>
#include <map>
#include "heap.h"
#include "huffmanNode.h"
//#include "huffmanTree.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void getPrefix(huffmanNode* cur, string prefixCode, map<char, string> &prefixTable);

int count2 = 0;

int main(int argc, char** argv) {
   
   	if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

   	// attempt to open the supplied file
   	// ifstream stands for "input file stream"
   	ifstream file(argv[1]);
   	// if the file wasn't found, output an error message and exit
   	if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    char g;
    map<char, int> freqTable;

    binary_heap heap;

    // 1. Create frequency table = freqTable

    int count1 = 0;
    while (file.get(g)) {
    	//push back g to the vector 
   		if((g >= 0x20) && (g <= 0x7e)){
   			
   			if(freqTable.find(g) != freqTable.end()) {
   					freqTable[g]++;
   				}
   			else {
   				freqTable[g] = 1;
   			}
   			count1++;
   		}
    }
		//it->second; do something with int (key)
        //it->first; do something with value
    for (map<char, int>::iterator it = freqTable.begin(); it != freqTable.end(); it++) {
    	huffmanNode* node = new huffmanNode(it->second, it->first); 
    	heap.insert(node);
    	//cout << it->first << " " << it->second << endl;
    }

    //cout << heap.findMin()->character << endl;

    // 2. Create huffman tree
    while(heap.size() > 1) {
    	huffmanNode* root = new huffmanNode();
    	huffmanNode* nleft = heap.deleteMin();
    	huffmanNode* nright = heap.deleteMin();
    	root->freq = nleft->getFreq() + nright->getFreq();

    	root->left = nleft;
    	root->right = nright;
    	heap.insert(root);
    }

    // 3. Create prefix table = prefix
    huffmanNode* root = heap.deleteMin();
    
    // getPrefix(root, "", prefixTable);

    // Section 1

    //it->second; do something with int (key)
    //it->first; do something with value
    //cout << prefixTable->first << endl;
    // for (map<char, string>::iterator itr = prefixTable.begin(); itr != prefixTable.end(); ++itr) {
    // 	if (itr->first == ' ') {
    // 		cout << "space" << " " << itr->second << endl;
    // 	}
    // 	else{
    // 		cout << itr->first << " " << itr->second << endl;
    // 	}
    // }

    map<char, string> prefixTable;
    getPrefix(root, "", prefixTable);


    cout << "----------------------------------------" << endl;

  	// Section 2

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    // first == key = char  second == value = string

    //cout << prefixTable['a'] << endl;
   

    string encode = "";
    int count4 = 0;
    while(file.get(g)) {
    	cout << prefixTable[g];
    	count4 += prefixTable[g].length();
    }
    cout << endl;

    cout << "----------------------------------------" << endl;

    // Section 3
    int count3 = count1 *8;

    double count5 = (double) count3 / (double) count4;
    double count6 = (double) count4 / (double) count1;
    cout << "There are a total of " << count1 << " symbols that are encoded." << endl;
    cout << "There are a total of " << count2 << " distinct symbols used." << endl;
    cout << "There were " << count3 <<" bits in the original file." << endl;
    cout << "There are " << count4 <<" bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << count5 << "." << endl;
    cout << "The cost of the Huffman Tree is " << count6 << " bits per character" << endl;

  	// close the file
    file.close();
	
    return 0;
}

void getPrefix(huffmanNode* cur, string prefixCode, map<char, string> &prefixTable) {
	//base case
	if (cur == NULL){return;}
	else if (cur->left == NULL && cur-> right == NULL){
		//put this in data structure 
		cout << cur->character << " " << prefixCode << endl;
		//cout << "Prefix of the " << cur->character << "is " << prefixCode << endl;
		count2++;
		prefixTable.insert(pair<char,string>(cur->character,prefixCode));

	}
	else {
		// recursive case
		// go left --> add 0 to the prefix
		getPrefix(cur->left, prefixCode+"0", prefixTable);
		// go right --> add 1 to the prefix
		getPrefix(cur->right, prefixCode+"1", prefixTable);
	}
}
