/*
	Joseph Lee (Sangwoo)
	sl5nj
	11 Oct 2020
	preLab 6
*/

#include "hashTable.h"


hashTable::hashTable()
{
	//bucket = new vector< list<string> >;
}

hashTable::~hashTable()
{
	delete bucket;
}

hashTable::hashTable(int size)
{
	bucket = new vector<list<string> >;
	//hashSize = 0;
	if(checkprime(size))
	{
		hashSize = size*2;
	}
	else
	{
		hashSize = getNextPrime(size*2);
	}

	for(int i = 0; i < hashSize; i++)
	{
		list<string> temp;
		bucket->push_back(temp);
	}


}

int hashTable::setSize(int size)
{

	return 0;
}


void hashTable::insert(string x)
{
	//unsigned int hash = hash(x);
	//bucket->at(hash(x)).push_back(x);
	//if(!this->contains(x))
	//{
		//list<string> & word = bucket->at(hash(x));
        bucket->at(hash(x)).push_back(x);
	//}
}

bool hashTable::contains(string x)
{
	list<string> & word = bucket->at(hash(x));
	bool exist = find(word.begin(), word.end(), x) != word.end();
	return exist;
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

unsigned int hashTable::hash(string key)
{
	unsigned int hash = 0;
	//int hashSize = 0;
	for(int i = 0; i < key.length(); i++)
	{
		//hash += key[i] * pow(37, i);
		hash = 37*hash + key[i];
	}
	return hash % hashSize;
}
