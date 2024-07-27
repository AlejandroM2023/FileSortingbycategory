/****************************************************************/
/* linkedlist.h
/* Purpose:    linkedlist header file.
/****************************************************************/

#ifndef LINKEDLIST_
#define LINKEDLIST_
#include <string>
#include <vector>
using namespace std;

class LinkedList
{
private:
   int numItems; 
   Node* headPtr; 
   
public:
   LinkedList();
   LinkedList(const LinkedList& list); 
   ~LinkedList();    
   void addNode(string category, string line);
   int getNumItems();
   vector<string> toVector() const;
}; // end linkedlist

#include "linkedlist.cpp"
#endif