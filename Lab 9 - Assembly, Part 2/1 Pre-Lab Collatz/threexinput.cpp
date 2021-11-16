/*
	Joseph Lee (Sangwoo)
	sl5nj
	CS2150 Lab 9 - Pre-Lab
	threexinput.cpp
*/

#include <iostream>
#include "timer.h"
#include <string>
#include <cstdlib>

using namespace std;

extern "C" int threexplusone(int);

int main(){

	int inum = 0; 
	int itr = 0;
	timer myTimer;
	int output;

	cout << "Enter a number: " << endl;
	cin >> inum;

	cout << "Enter iterations of subroutine: " << endl;
	cin >> itr;

	myTimer.start();
	for(int i = 0; i < itr; i++){
		threexplusone(inum);
	}
	myTimer.stop();

	output = threexplusone(inum);

	cout << "Steps: " << output << endl;

	double average = myTimer.getTime() * 1000 / itr;

	//cout << "Time spent: " << average << "s "<< endl;

	return 0;
}