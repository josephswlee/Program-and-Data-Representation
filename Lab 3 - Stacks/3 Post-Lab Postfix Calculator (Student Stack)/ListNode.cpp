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
  this->value = value;
  next = NULL;
  previous = NULL;
}


