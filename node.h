/****************************************************************/
/* node.h
/* Purpose:    header file for node class.
/****************************************************************/
#ifndef NODE_
#define NODE_

using namespace std;

class Node
{
private:
   string        line; // A data item
   string    category;
   Node* next; // Pointer to next node
   
public:
   Node();
   ~Node();
   void setLine(const string& aLine);
   void setCategory(const string& aCategory);
   void setNext(Node* nextNodePtr);
   string getLine() const ;
   string getCategory() const ;
   Node* getNext() const ;
}; // end Node

#include "Node.cpp"
#endif