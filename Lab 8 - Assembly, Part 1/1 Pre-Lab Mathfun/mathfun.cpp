// Joseph Lee (Sangwoo)
// sl5nj
// prelab 8

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product (int x, int y);
extern "C" int power (int x, int y);

// Purpose: This main program produces a vector of random numbers
// between 0 and 99, then calls the externally defined function
// 'vecsum' to add up the elements of the vector.

// Originally written by Adam Ferrari, and updated by Aaron Bloomfield

int  main () {

    // delcare the local variables
    int x, y;

    // how big is the array we want to use?
    cout << "Enter integer 1:  ";
    cin >> x;

    cout << "Enter integer 2:  ";
    cin >> y;
 
    //call assembly and print the result
    int pd = product(x, y);
    int pw = power(x, y);

    cout << "Product: " << pd << endl;
    cout << "Power: " << pw << endl;

    // all done!
    return 0;
}