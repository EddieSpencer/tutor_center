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



struct UserNode
{
	User *data;
	UserNode* link;
};
typedef UserNode* userNodePtr;



/* ################################################################
 *
 * The class has the following methods:
 *
 * LinkedList()
 *        default constructor that creates an empty list
 *
 * addElement(int)
 *   Parameters: item, integer, data to be inserted into the list
 *   Precondition: Object is a valid list
 *   Postcondition: item is inserted into the list - list remains in sorted order
 *
 * removeElement(int)
 *   Parameters: none
 *   Precondition: List is not empty
 *   Postcondition: specified item is removed from the list if found
 *                  - list remains in sorted order
 *
 * isEmpty()
 *   Parameters: none
 *   Postcondition: return true if list is empty, false otherwise
 *
 * clearList()
 *   Parameters: none
 *   Postcondition: return empty list
 *
 * overloaded operator << () - friend function
 *   Parameters: outStr, ostream, output stream
 *               rhs, LinkedList object
 *   Precondition: List is not empty
 *   Postcondition: items in the list are displayed on the screen
 *
 * ################################################################ */

class PointerLinkedList
{
    
private:
    
	userNodePtr headPtr;
	userNodePtr currentPos;
	userNodePtr lastPtr;
    int length;
    
public:
    
    PointerLinkedList();
	~PointerLinkedList();
	PointerLinkedList(const PointerLinkedList&);
    PointerLinkedList merge(const PointerLinkedList&);
    
    void addElement(User*);
	void removeElement (User*);
	bool isEmpty();
	void clearList(); 
    int getLength();
    
    void getElement(string, Time, User[]);
    
    void writeToFile(string outFileName);
    bool inputFromFile(string inFileName);
    
    PointerLinkedList operator=(const PointerLinkedList&);
    
	friend ostream& operator <<(ostream&, PointerLinkedList&);
    
    // add other methods needed for safe memory management
};
#endif