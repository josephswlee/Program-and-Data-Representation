/*
    Joseph Lee (Sangwoo)
    sl5nj
    15 Sep 2020
*/

#include "ListNode.h"
#include "List.h"
#include "ListItr.h"

#include <iostream>
using namespace std;

//default constructor
ListNode::ListNode()
{
  value = 0;
  next = NULL;
  previous = NULL;
}

//overloaded constructor / copy constructor
ListNode::ListNode(int value)
{
  this->value = value; // because parameter is value I had to use this->value = value to distinguish which one is which
  next = NULL;
  previous = NULL;
}


