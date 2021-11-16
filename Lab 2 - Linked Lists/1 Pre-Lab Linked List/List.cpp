#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
using namespace std;

//default constructor
List::List()
{
  head = new ListNode();
  tail = new ListNode();
  head -> next = tail; 
  tail -> previous = head;
  count = 0;
}

//copy constructor
List::List(const List& source) //whenever dealing with an object
{
  head = new ListNode();
  tail = new ListNode();
  head -> next = tail;
  tail -> previous = head;
  count = 0;

  // Make a deep copy of the list //full independent copy
  ListItr iter(source.head -> next); // head is empty so calling the next of head is calling the beginning
  while(!iter.isPastEnd())
  {
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

//destructor
List::~List()
{
  makeEmpty(); //this deletes the curretn position of the list
  delete head;
  delete tail;
}

List& List::operator=(const List& source)
{
  if (this == &source)
  {
    // The two are the same list; no need to do anything
    return *this;
  }
  else
  {
    //Clear out anything this list contained
    //before copying over the items from the other list
    makeEmpty();

  // Make a deep copy of the list
  ListItr iter(source.head -> next);
  while (!iter.isPastEnd())
    {
    insertAtTail(iter.retrieve());
    iter.moveForward();
    }
  }

return *this;
}

bool List::isEmpty() const
{
    if(count == 0) //if(head->next->next == NULL || tail->previous->previous == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void List::makeEmpty()
{
  ListItr frontNode  = first();
  while(!frontNode.isPastEnd())
    {
      ListNode *n = frontNode.current;
   //   n = frontNode.current;
      frontNode.moveForward();
      delete n;
    }
  count = 0;
  head -> next = tail;
  tail -> previous = head;
}

ListItr List::first()
{
  return ListItr (head -> next);
}

ListItr List::last()
{
  return ListItr ((*tail).previous);
}

// Inserts x after current iterator position
void List::insertAfter(int x, ListItr position)
{
  ListNode *n = new ListNode(x);
    n->next = position.current->next; // set n next to n1 next
    position.current->next = n; // set n1 next to n
    n->next->previous = n; // set n2 previous to n
    n->previous = position.current; // set n1 previous to n
    count++; // increment count
}

//When creating an insert and remove function drawing circles helps
//the key thing to make sure is that you don't lose the scope of previous or next node
//order does matter a lot

void List::insertBefore(int x, ListItr position)
{
    ListNode *n = new ListNode(x);
    n->previous = position.current->previous;
    position.current->previous = n; // this is the opposite order from insertAfter function
    n->previous->next = n; // just write backward
    n->next = position.current;
    count++;
}

void List::insertAtTail(int x)
{
    ListItr n = last(); //create reference n to the last place in the node
    insertAfter(x, n); //pass argument x with the position n ß
}

ListItr List::find(int x)
{
    //to find the x you have to create reference to the beginning of the node //ask why it has to be ListItr
    ListItr n = first();
    while(n.current->value != x && !n.isPastEnd()) //when current value of n is not equal to x and not the end of the node
    {
        n.moveForward(); // keep going
    }
    if(n.current->value == x)
    {
        return n; //if the value matches x return n
    }
    else
    {
        ListItr notFound = tail;
        return notFound; //otherwise just return notFound as a dummy tail
    }
    
}

void List::remove(int x)
{
    ListItr n = first();
    while(n.current->value != x && !n.isPastEnd())
    {
        n.moveForward(); // n is not pointer so we use . but n.current gives you pointer so we use ->
    }
    if(n.current->value == x)
    {
        n.current->previous->next = n.current->next; // set previous node's next to current's next
        n.current->next->previous = n.current->previous; // set next node's previous to current's previous
        delete n.current; // delete current
        count--; // decrement the count
        //before removal set the previous to the next then set next to previous
    }
}

int List::size() const
{
  return count;
}

void printList(List& source, bool forward)
{
  if(forward)
    {
      ListItr iter = source.first();
        
      while(!iter.isPastEnd())
      {
      cout << iter.retrieve() << endl;
      iter.moveForward();
      }
    }
  else
    {
     // ListItr iter(source.getTail()->getPrevious());
    ListItr iter = source.last();
    while(!iter.isPastBeginning())
    {
      cout << iter.retrieve() << endl;
      iter.moveBackward();
    }
    }
}
