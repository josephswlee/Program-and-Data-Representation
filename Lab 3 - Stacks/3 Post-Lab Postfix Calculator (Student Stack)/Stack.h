
#pragma once
#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <stack>
#include "List.h"
#include "ListItr.h"
//#include "ListNode.h"
//#include "postfixCalculator.h"

class List;
class ListItr;

class Stack
{
private:
    List myList; // 
    int count;
 public:
    //List *myList; //creating reference to List as myList
    //std::stack<> myStack;
    Stack(); //constructor // dont need it really in this case
    ~Stack(); //destructor // same
    void push(int e); //push an item into the top of the stack
    void pop(); //remove an item from the top of the stack
    int top(); //look at the top of the stack
    bool empty();
//    void push(int e); //push number into an stack
//    void addition(); //pop the top and bottom and add them
//    void subtraction(); //pop the top and bottom and subtract them bot - top
//    void multiplication(); //pop the top and bottom and multiply them
//    void division(); //calc op //pop the top and bottom and divide them bot/top
//    void negate(); //calc op
//    int returnResult(); //return the value of the top
    
    //for push just insert at tail and change peek to top
    
//    friend class ListItr;
//    friend class List;
//    friend class ListNode;
//    friend class PostfixCalculator;
};
