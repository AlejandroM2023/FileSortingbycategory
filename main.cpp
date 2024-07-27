/****************************************************************/
/* main.cpp
/* Purpose:    main method inlcluding user menu.
/****************************************************************/


#include <iostream>
#include "Node.h"
#include "Linkedlist.h"
#include <fstream>
using namespace std;


int main()
{
	string file;
	LinkedList list;
	vector<string> printvector;

	//get file name
	cout<<"Enter file name: ";
	cin>>file;
		
	//open text file
	ifstream TextFile(file);
		
	//variables for node
	string ctgr;
	string txt;
		
	//reads until no lines left. Gets category and line at same time
	while (getline (TextFile, ctgr) && getline (TextFile, txt)) {
	    list.addNode(ctgr,txt);
	}
	
	//close the text file		
	TextFile.close();
	
	//convert to vector and print
	printvector = list.toVector();
	
	for (int i = 0; i < printvector.size(); i++) {
        cout << printvector[i] <<endl;
    }
	
	
	
	
	return 0;
}

