/*
	Joseph Lee (Sangwoo)
	sl5nj
	13 Oct 2020
	postLab 6
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using namespace std;

class hashTable 
{
private:
	//array that each element have list //prevents collision 
	vector <list<string> > * bucket;
	int hashSize;

public:
	hashTable();
	~hashTable();
	hashTable(int size);
	int setSize(int size);
	void insert(string x);
	bool contains(string x);
	bool checkprime(unsigned int p);
	int getNextPrime (unsigned int n);
	unsigned int hash(string key);

};

#endif