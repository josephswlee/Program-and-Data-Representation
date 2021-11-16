
#include "Stack.h"

using namespace std;

Stack::Stack()
{
    List myList; //this will call the constructor of List(which create without "new") 
    //myList = new List; // you can use this when you are using pointer
    count = 0;
}

Stack::~Stack()
{
    //delete myList; // do not need destructor because it is in list
    // but if you want to use pointer because you are using "new" you need destructor
}

void Stack::push(int e)
{
    myList.insertAtTail(e); // insert an item into the back of the list
    count++;
}

void Stack::pop()
{
    //ListItr lastItem = myList.last(); // create a reference to the last object of the list
    myList.removeAtTail(); // remove that item // you have to create function in List so it can function as Stack
    count--;
}

int Stack::top()
{
    ListItr lastItem = myList.last(); // not to make it const because last() is not const cant be used
    
    return lastItem.retrieve();
}

bool Stack::empty()
{
    if(count == 0)
    {
        return true;
    }
    else
        return false;
}

//Stack::Stack()
//{
//    Stack = new List;
//    count = 0;
//}
//
//Stack::~Stack()
//{
//    Stack.makeEmpty();
//    delete Stack;
//}
