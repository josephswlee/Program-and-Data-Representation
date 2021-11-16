#include "bankAccount.h"

bankAccount::bankAccount()
{
	balance = 0.00;
}

bankAccount::bankAccount(double amount)
{
	if(amount >= 0)
	{
		balance = balance + amount;
	}
	else
		balance = 0.00;

}

bankAccount::~bankAccount()
{
	
}

double bankAccount::withdraw(double amount)
{
	if(amount >= 0 && amount <= balance)
	{
		balance = balance - amount;
	}
	return balance;
}

double bankAccount::deposit(double amount)
{
	if(amount >= 0)
	{
		balance = balance + amount;
	}
	return balance;
}

double bankAccount::getBalance()
{
	return balance;
}

