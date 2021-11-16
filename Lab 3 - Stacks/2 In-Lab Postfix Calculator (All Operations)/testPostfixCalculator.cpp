
#include "postfixCalculator.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
   // int option;
    string input;
    PostfixCalculator p;
    //cout << "Enter expression: " ;
    while(cin >> input)
    {
        if(input == "+")
	  {
            p.addition();
	  }
        else if (input == "-" && input.length() == 1) //this is the special case b/c negative numbers can be read
	  {
            p.subtraction();
	  }
	else if (input == "*")
	  {
	    p.multiplication();
	  }
	else if (input == "/")
	  {
	    p.division();
	  }
	else if (input == "~")
	  {
	    p.negate();
	  }
	
        else
	  {
            //p.push(stoi(input));
            p.push(atoi(input.c_str())); // this take the input and convert it into int before pushing into stack.
	  }
    }
    
    cout << p.returnResult() << endl;
    
    //ctrl + d to push in the result and get the result
    
    //converting int -> atoi(s.c_str())
    
    return 0;
}

// when you are running this type "ctrl d" after the input
