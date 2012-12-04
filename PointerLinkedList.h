// Team Diversity
// Course: CSC 260, Section 01
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Collaborative Project
// Description: Linked list to hold user pointers
// Filename: PointerLinkedList.cpp
// Last modified on: 11/30/12

#if!defined _PointerLinkedList_h
#define _PointerLinkedList_h

#include "User.h"
#include "Time.h"
#include "Tutor.h"
#include <string>
#include <iostream>
using namespace std;


//Node of holding a User pointer
struct UserNode
{
	User *data;
	UserNode* link;
};
typedef UserNode* userNodePtr;


class PointerLinkedList
{
    
private:
    //instance data for use by the pointer linked list
	userNodePtr headPtr;
	userNodePtr currentPos;
	userNodePtr lastPtr;
    int length;
    
public:
    //constructor, destructor, and rest of big 3
    PointerLinkedList();
	~PointerLinkedList();
	PointerLinkedList(const PointerLinkedList&);
    PointerLinkedList merge(const PointerLinkedList&);
    
    //functions to manipulate the linked list
    void addElement(User*);
	void removeElement (User*);
	bool isEmpty();
	void clearList(); 
    int getLength();
    
    void getElement(string, Time, User[]);
    
    //functions for the input/output of the list
    void writeToFile(string outFileName);
    bool inputFromFile(string inFileName);
    
    PointerLinkedList operator=(const PointerLinkedList&);
    
	friend ostream& operator <<(ostream&, PointerLinkedList&);
    
};
#endif