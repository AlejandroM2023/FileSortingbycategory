/****************************************************************/
/* node.cpp
/* Purpose:    integration of node class.
/****************************************************************/
#include "Node.h"


Node::Node() : next(nullptr)
{
} // end default constructor
Node::~Node(){
	delete next;
}

void Node::setLine(const string& aLine)
{
   line = aLine;
} // end setItem

void Node::setCategory(const string& aCategory)
{
   category = aCategory;
} // end setItem


void Node::setNext(Node* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext


string Node::getLine() const
{
   return line;
} // end getItem

string Node::getCategory() const
{
   return category;
} // end getItem


Node* Node::getNext() const
{
   return next;
} // end getNext