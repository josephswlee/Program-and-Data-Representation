

#include "postfixCalculator.h"
using namespace std;

PostfixCalculator::PostfixCalculator()
{
    Stack myStack;
    //myStack = new Stack();
}

PostfixCalculator::~PostfixCalculator()
{
    //delete myStack; // not using new so dont have to use delete
}

void PostfixCalculator::push(int e)
{
    myStack.push(e);
}

void PostfixCalculator::addition()
{
    int second = myStack.top();
    myStack.pop();
    int first = myStack.top();
    myStack.pop();
    
    myStack.push(first+second);
}

void PostfixCalculator::subtraction()
{
    int second = myStack.top();
    myStack.pop();
    int first = myStack.top();
    myStack.pop();
    
    myStack.push(first-second);
}

void PostfixCalculator::multiplication()
{
    int second = myStack.top();
    myStack.pop();
    int first = myStack.top();
    myStack.pop();
    
    myStack.push(first*second);
}

void PostfixCalculator::division()
{
    int second = myStack.top();
    myStack.pop();
    int first = myStack.top();
    myStack.pop();
    
    myStack.push(first/second);
}

void PostfixCalculator::negate()
{
    int first = myStack.top();
    myStack.pop();
    
    myStack.push(first*-1);
}

int PostfixCalculator::returnResult()
{
    return myStack.top();
}
