/*
    Joseph Lee 
    sl5nj
    8 Sep 2020
*/

#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include <iostream>
#include <string>
using namespace std;

class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

MyObject getMaxMyObj(const MyObject o1, const MyObject o2);
int cmpMyObj(const MyObject o1, const MyObject o2);
void swapMyObj(MyObject& o1, MyObject& o2);

#endif

//putting prototype in header is better. in the header you declare all the functions but not 
//define them. It is better to put all the declaration inside header file. 
//implementation is in cpp file. This is a good practice to program this way.

/*
 When we comment out the getMaxObj() prototype, the program no longer compiles
 because main() does not know where to access getMaxObj function without having
 getMaxObj() prototype declared in header
 */

/*
 Possible questions
 1) What is the purpose of adding the const in the parameters of various functions.
 
 2) From the class slides friend is being used we want to access private but in our lifecycle exemples,
 we used friend in public with ostream operator. I want to know the purpose of using them.
 
 3) Does it matter if you put prototypes in TestLifeCycle.cpp or in header file?
 
 */
