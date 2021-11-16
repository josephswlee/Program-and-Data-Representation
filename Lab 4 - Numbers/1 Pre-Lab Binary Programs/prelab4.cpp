/*
  Joseph Lee (Sangwoo)
  sl5nj
  25 Sep 2020
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <math.h>
#include <cmath>
using namespace std;

void sizeOfTest();
void overflow();
void outputBinary(unsigned int input);

int main()
{
  int input;
  cin >> input;
  sizeOfTest();
  overflow();
  outputBinary(input);
}

//function to print the size of all primitive data types
void sizeOfTest()
{
  //primitive data types and pointers
   cout << "Size of int: " << sizeof(int) << endl;
   cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
   cout << "Size of float: " << sizeof(float) << endl;
   cout << "Size of double: " << sizeof(double) << endl;
   cout << "Size of char: " << sizeof(char) << endl;
   cout << "Size of bool: " << sizeof(bool) << endl;
   cout << "Size of int*: " << sizeof(int*) << endl;
   cout << "Size of char*: " << sizeof(char*) << endl;
   cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow()
{
  //make sure it is UINT_MAX not UNIT_MAX !! such a dumb mistake
  //from microsoft website I found UINT_MAX is the maximum value for unsigned int
  //https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=vs-2019
  unsigned int i = UINT_MAX + 1; // UINT_MAX is same as (2^32 - 1)
  cout << UINT_MAX << " + " << 1 << " = " << i << endl;
  //when you hit the maximum digit then it turns everything into 0 but last digit does not exist so it just becomes zero
  // same as if the max is 4 digit and after 9999 and reaches 10000 fifth digit doesnt exist so it becomes 0000
}

void outputBinary(unsigned int input)
{
    string output = "";
    for (int i = 31; i > -1; i--)
    {
      if((pow(2, i)) <= input) // when 2^i is less than input you just add 1 to the output
        {
            output += "1";
            input -= pow(2, i); // then you subtract that out so you don't add everything that follows
        }
        else
        {
	          output += "0"; // if not just simply add 0
        }
        if (i%4==0){
            output += " "; // add space after every 4th digit
        }
    }
    cout << output << endl;
}

