/****************************************************************/
/* linkedlist.cpp
/* Purpose:    integration of linkedlist class
/****************************************************************/




#include <iostream>
#include <string>
#include "linkedlist.h"
#include <algorithm>

using namespace std;

LinkedList::LinkedList():headPtr(nullptr)
{	
}// end default constructor

LinkedList::LinkedList(const LinkedList& list)
{	
	Node* temp = headPtr;
	LinkedList lst;
	while(temp != nullptr){
		lst.addNode(temp->getCategory(),temp->getLine());
		temp = temp->getNext();
	}
}// end copy constructor

LinkedList::~LinkedList(){
	Node* cur = headPtr;
	while(cur != nullptr){
		Node* next = cur->getNext();
		delete cur;
		cur = next;
	}
}


void LinkedList :: addNode(string category, string line)
{
	// create node then set category and line
	Node* newNode = new Node();
	newNode->setCategory(category);
	newNode->setLine(line);
	
	//loop control
	bool loop = false;
	Node* prev = nullptr;
	Node* cur = headPtr;
	numItems ++; 
	
	
	if (headPtr==nullptr){
		headPtr = newNode;
		
	}else{
		//while loop waits for true(after node is inserted)
		while(!loop){
			//checks if categories are the same or if its the end of the list
			if(newNode->getCategory()==cur->getCategory() ){
				 
				
				//three conditions: node goes before,node goes at end, node in between after or before
				if(newNode->getLine().compare(cur->getLine()) < 0  ){
					if(cur == headPtr){
						newNode->setNext(cur);
						headPtr=newNode;
						loop=true;
					}else{
						newNode->setNext(cur);
						prev->setNext(newNode);
						loop=true;
					}
					
				}else if(cur->getNext()== nullptr){
					cur->setNext(newNode);
					loop=true;
				}else if(cur->getNext()->getCategory()!=cur->getCategory()){
					Node* tempnxt = cur->getNext();
					newNode->setNext(tempnxt);
					cur->setNext(newNode);
					loop=true;
				}
				
			}else if(cur->getNext()==nullptr){
				cur->setNext(newNode);
				loop=true;
			}
		
			prev= cur;
			cur= cur->getNext();
		}

	}
		
}//end of addnode
	

	
                          
int LinkedList::getNumItems()
{
	return numItems;
}//end of getNumItems()

vector<string> LinkedList :: toVector() const
{
	vector<string> v1;
	Node* temp= headPtr;
	v1.push_back(temp->getCategory());
	
	
	while(temp != nullptr){
		
		if(count(v1.begin(),v1.end(),temp->getCategory()) == 0){
			v1.push_back(temp->getCategory());
		}
		v1.push_back("    "+temp->getLine());
		temp = temp->getNext();
	}
	
	return v1;
}//end of toVector()

