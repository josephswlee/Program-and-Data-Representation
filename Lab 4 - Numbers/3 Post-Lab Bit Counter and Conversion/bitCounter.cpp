/*
  Joseph Lee (Sangwoo)
  sl5nj
  1 Oct 2020
  bitCounter.cpp
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

int binaryCount(int e);
int charToNumber(char point);
string obTo10(string input, int ob, int nb);
string decimalToNB(string input, int ob, int nb);
string baseConvert(string input, int ob, int nb);


int main(int argc, char *argv[]) // ** is equivalent to [] in this case char array
{
	if (argc == 1)
	{
		cout << "Program is going to exit gracefully" << endl;
		exit(1);
	}

    int num = atoi(argv[1]);
    int callCounter = binaryCount(num);
    cout << num << " has " << callCounter << " bit(s)" << endl;

    string s = argv[2];
    int oldBase = atoi(argv[3]);
    int newBase = atoi(argv[4]);

    string result = baseConvert(s, oldBase, newBase);
    cout << argv[2] << " (base " << argv[3] << ") = " << result << " (base " << argv[4] << ")" << endl;

    return 0;
}

int binaryCount(int n) 
{
	if (n == 1) 
	{
		return 1;
	}
	return (n%2) + binaryCount(n/2);
}

string baseConvert(string input, int ob, int nb) // * is same as [] therefore, **argv is double array
{
	if (nb == 1)
	{
		string t = "";
		int num = stoi(input);
		for (int i = 0; i < num; i++)
		{
			t = t + "1";
		}
		return t;
	}
	else if (nb == 10)
	{
		return obTo10(input, ob, nb);
	}
	else if(ob == 10)
	{
		return decimalToNB(input, ob, nb);
	}
	else
	{
		string result = obTo10(input, ob, nb);
		return decimalToNB(result, ob, nb);
	}
}

int charToNumber(char pointer)
{
	if (pointer >= '0' && pointer <= '9')
	{
		return (int)pointer - '0';
	}
	else
	{
		return (int)pointer - 'A' + 10;
	}
}

string obTo10(string input, int ob, int nb)
{
	int cumulativeSum;
	int leng = input.length();

	for(int i = leng-1; i >= 0; i--)
	{
		cumulativeSum += charToNumber(input[i]) * pow(ob, leng-1-i);
	}

	string result = to_string(cumulativeSum);

	return result;
}

string decimalToNB(string input, int ob, int nb)
{
	// string secondLoop = obTo10(input, ob, nb);
	// int secondLeng = secondLoop.length();
	string secCumSum = "";
	int num = stoi(input);
	while(num > 0)
	{
		int remainder = num%nb;
		if(remainder > 9) // because 0 thru 9 is represtable with numbers
		{
			if(remainder == 10)
			{
				secCumSum += "A";
			}
			else if(remainder == 11)
			{
				secCumSum += "B";
			}
			else if(remainder == 12)
			{
				secCumSum += "C";
			}
			else if(remainder == 13)
			{
				secCumSum += "D";
			}
			else if(remainder == 14)
			{
				secCumSum += "E";
			}
			else if(remainder == 15)
			{
				secCumSum += "F";
			}
			else if (remainder == 16) {
				secCumSum += "G";
			}
			else if (remainder == 17) {
				secCumSum += "H";
			}
			else if (remainder == 18) {
				secCumSum += "I";
			}
			else if (remainder == 19) {
				secCumSum += "J";
			}
			else if (remainder == 20) {
				secCumSum += "K";
			}
			else if (remainder == 21) {
				secCumSum += "L";
			}
			else if (remainder == 22) {
				secCumSum += "M";
			}
			else if (remainder == 23) {
				secCumSum += "N";
			}
			else if (remainder == 24) {
				secCumSum += "O";
			}
			else if (remainder == 25) {
				secCumSum += "P";
			}
			else if (remainder == 26) {
				secCumSum += "Q";
			}
			else if (remainder == 27) {
				secCumSum += "R";
			}
			else if (remainder == 28) {
				secCumSum += "S";
			}
			else if (remainder == 29) {
				secCumSum += "T";
			}
			else if (remainder == 30) {
				secCumSum += "U";
			}
			else if (remainder == 31) {
				secCumSum += "V";
			}
			else if (remainder == 32) {
				secCumSum += "W";
			}
			else if (remainder == 33) {
				secCumSum += "X";
			}
			else if (remainder == 34) {
				secCumSum += "Y";
			}
			else if (remainder == 35) {
				secCumSum += "Z";
			}
		}
		else 
		{
			secCumSum = to_string(remainder) + secCumSum;
		}
		num = num/nb;
	}
	return secCumSum;
}

//sudo
	//string total = to_string(secCumSum);
	//secCumSum.at(i) to check with ASCII code
	//convert to 10 // for each digit i muliply value by 10^i and add
	//https://commons.wikimedia.org/wiki/File:ASCII-Table-wide.svg
	// 1st: if statement for char ( input >= 65 ) -55 else -48
	// 2nd: (ob^(length-1-i))  
	//for each i int preconvert = argv[i]
	// shift to actualval
	// digitval = ob ^(length-i-1)
	// cumsum += digitval * actualval
	//conver to nb (new base)

	//need 2 for loops to convert 
	// 1st loop determines the length of the loop 
	// 
	// 2nd loop it iterate over the each digit with new base
	

