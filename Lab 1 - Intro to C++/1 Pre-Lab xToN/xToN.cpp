#include <iostream>
//#include <cmath> // since I needed to use recursion I did not need this
using namespace std;


int xToN (int a, int b); // forward declaration

int main () 
{
	int a, b;
  	//cout << "What is the base number? " ;
  	cin >> a;
  //	cout << "What is the power? ";
  	cin >> b;
  	cout << xToN(a, b) << endl;

    return 0;
}

int xToN (int a, int b) 
{
	if(b == 0) // this should be power so the recursion can end once reach 0
	{
		return 1;
	}
	else
	{
		return a * xToN (a, --b); // decrement the power 
	}
}
