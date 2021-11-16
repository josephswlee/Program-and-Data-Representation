/*
    Joseph Lee (Sangwoo)
    sl5nj
    CS2150 Lab 10 - Post-Lab
    huffmandec.cpp
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "huffmanNode.h"
using namespace std;

void createTree(huffmanNode*& cur, char chars, string prefix, int i);
string decode(huffmanNode*& root, string encoded);

bool isTree(huffmanNode* root) {
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    if ((root->left) && (root->right)) {
        return (isTree(root->left) && isTree(root->right));
    }
    return false;
}

int main(int argc, char** argv) {
	// verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    //get the root
    huffmanNode* root = new huffmanNode();
    //char chars;

    //int testing = 0;
    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
        
        //cout << character[0] << endl;
        char chars = character[0];
        createTree(root, chars, prefix, 0);
    }

  	// read in the second section of the file: the encoded message
    stringstream sstm;
  
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();

    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    decode(root, allbits);
    
    // close the file before exiting
    file.close();
	return 0;
}

void createTree(huffmanNode*& cur, char chars, string prefix, int i) {
    	if(cur == NULL) {
    		cur = new huffmanNode();
    	}
    	//base case, we at leaf node
    	if(i == prefix.length()) {
    		cur->character = chars;
    		return;
    	}
    	//go left or right depending on 0 or 1
    	if(prefix[i] == '0') {
    		createTree(cur->left, chars, prefix, i+1);
    	}
    	else if(prefix[i] == '1') {
    		createTree(cur->right, chars, prefix, i+1);
    	}
    }

string decode(huffmanNode*& root, string encoded) {
    string temp = "";
    huffmanNode* r = root;
    for(int i = 0; i < encoded.size(); i++) {
        if(r == NULL) {
            return temp;
        }
        if(encoded[i] == '0') {
            r = r->left;
        }
        else if(encoded[i] == '1') {
            r = r->right;
        }
        if(r->left == NULL && r->right == NULL) {
            temp += r->getChar();
            r = root;
        }
    }
    cout << temp << endl;
    return temp;
}
