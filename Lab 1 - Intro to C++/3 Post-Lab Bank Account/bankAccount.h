/*
	Joseph Lee
	sl5nj
	8 Sep 2020
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
// #include <string>
// #include <stdlib.h>
// #include <cmath>
// #include <iomanip>

class bankAccount
{
public:
	bankAccount();
	bankAccount(double amount);
	~bankAccount();
	double withdraw(double amount);
	double deposit(double amount);
	double getBalance();
private:
	double balance;
};

#endif
