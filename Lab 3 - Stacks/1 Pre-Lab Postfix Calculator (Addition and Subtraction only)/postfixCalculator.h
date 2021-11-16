
#pragma once
#include <iostream>
#include <cstdlib>
#include <stack>

class PostfixCalculator
{
 public:
    std::stack<int> myStack;
    //PostfixCalculator(); //constructor
    //~PostfixCalculator(); //destructor
    //void push(int e); //push an item into the top of the stack
    //void pop(); //remove an item from the top of the stack
    //int peek(); //look at the top of the stack
    void push(int e); //push number into an stack
    void addition(); //pop the top and bottom and add them
    void subtraction(); //pop the top and bottom and subtract them bot - top
    void multiplication(); //pop the top and bottom and multiply them
    void division(); //calc op //pop the top and bottom and divide them bot/top
    void negate(); //calc op
    int returnResult(); //return the value of the top
};
