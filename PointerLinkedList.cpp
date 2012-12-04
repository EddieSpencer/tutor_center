// Team Diversity
// Course: CSC 260, Section 01
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Collaborative Project
// Description: Linked list header file
// Filename: PointerLinkedList.h
// Last modified on: 11/30/12

#include "PointerLinkedList.h"

//constructor
PointerLinkedList::PointerLinkedList()
{
	// ensure pointer is initialized to a valid value
	headPtr = NULL;
	currentPos = headPtr;
	length = 0;
	lastPtr = NULL;
    
}

//returns length of data structure
int PointerLinkedList::getLength()
{
    return length;
}


//adds an element to the linked list
void PointerLinkedList::addElement (User* item)
{
    
	userNodePtr currPtr, prevPtr, tempPtr;
	tempPtr = new UserNode;
	tempPtr->data = item;
	tempPtr->link = NULL;
	prevPtr = NULL;
	currPtr = headPtr;
	while (currPtr != NULL && item > currPtr-> data)
	{
		prevPtr = currPtr;
		currPtr = currPtr->link;
	}
	tempPtr->link = currPtr;
	if(prevPtr == NULL)
		headPtr = tempPtr;
	else
		prevPtr->link = tempPtr;
    
	length++;
}

//destructor for the linked list
PointerLinkedList::~PointerLinkedList()
{
    userNodePtr tempPtr;
    userNodePtr currPtr = headPtr;
    while(currPtr!=NULL)
    {
        tempPtr = currPtr;
        currPtr = currPtr->link;
        delete tempPtr;
    }
}

//overloaded copy constructor for the linked list
PointerLinkedList::PointerLinkedList(const PointerLinkedList& list)
{
    userNodePtr fromPtr;
    userNodePtr toPtr;
    if (list.headPtr == NULL)
    {
        headPtr = NULL;
        return;
    }
    fromPtr = list.headPtr;
    headPtr = new UserNode;
    headPtr->data = fromPtr->data;
    toPtr = headPtr;
    fromPtr = fromPtr->link;
    while(fromPtr != NULL)
    {
        toPtr->link = new UserNode;
        toPtr = toPtr->link;
        toPtr->data = fromPtr->data;
        fromPtr = fromPtr->link;
    }
    toPtr->link = NULL;
    lastPtr = toPtr;
}

//removes an element from the linked list
void PointerLinkedList::removeElement (User* item)
{
    
    userNodePtr prevPtr = NULL;
    userNodePtr currPtr = headPtr;
    while(currPtr!=NULL && currPtr ->data != item && currPtr->data < item)
    {
        prevPtr = currPtr;
        currPtr = currPtr->link;
    }
    if(currPtr !=NULL && currPtr->data == item)
    {
        if(currPtr == headPtr)
            headPtr = currPtr->link;
        else
            prevPtr->link = currPtr->link;
        if(currPtr == lastPtr)
            lastPtr = prevPtr;
        delete currPtr;
        length--;
    }
}

//finds an element in the linked list
void PointerLinkedList::getElement (string subject, Time t, User useravail[])
{
    int i = 0;
    int k = 0;
    User userarray[5];
    userNodePtr prevPtr = NULL;
    userNodePtr currPtr = headPtr;
    while(currPtr !=NULL)
    {
        User *ptr = currPtr->data;
        User user = *ptr;
        if(user.getID()==0)
        {
            userarray[i] = user;
            i++;
        }
        prevPtr = currPtr;
        currPtr = currPtr->link;
    }
    
    return;
}

//overloaded assignment operator for the linked list
PointerLinkedList PointerLinkedList::operator=(const PointerLinkedList& list)
{
    userNodePtr fromPtr;
    userNodePtr toPtr;
    if (list.headPtr == NULL)
    {
        headPtr = NULL;
    }
    fromPtr = list.headPtr;
    headPtr = new UserNode;
    headPtr->data = fromPtr->data;
    toPtr = headPtr;
    fromPtr = fromPtr->link;
    while(fromPtr != NULL)
    {
        toPtr->link = new UserNode;
        toPtr = toPtr->link;
        toPtr->data = fromPtr->data;
        fromPtr = fromPtr->link;
    }
    toPtr->link = NULL;
    lastPtr = toPtr;
    
    return *this;
}

//returns boolean if linked list is empty or not
bool PointerLinkedList::isEmpty()
{
    if(headPtr==NULL)
        return true;
    else
        return false;
}

//clears the linked list of all nodes
void PointerLinkedList::clearList()
{
    userNodePtr tempPtr;
    userNodePtr currPtr = headPtr;
    while(currPtr!=NULL)
    {
        tempPtr = currPtr;
        currPtr = currPtr->link;
        delete tempPtr;
    }
}

//merges two linked lists
PointerLinkedList PointerLinkedList::merge(const PointerLinkedList& rhs)
{
    PointerLinkedList list1;
    
    userNodePtr tmpPtr1 = headPtr;
    userNodePtr tmpPtr2 = rhs.headPtr;
    
    while (tmpPtr1 != NULL)
    {
        list1.addElement(tmpPtr1->data);
        tmpPtr1 = tmpPtr1->link;
    }
    while (tmpPtr2 != NULL)
    {
        list1.addElement(tmpPtr2->data);
        tmpPtr2 = tmpPtr2->link;
    }
    return list1;
}

//outputs the linked list to a file stream
ostream& operator << (ostream& outStr, PointerLinkedList& rhs)
{
	userNodePtr tmpPtr = rhs.headPtr;
	outStr << endl;
	if (rhs.isEmpty())
		outStr << "Sorry, the list is empty. Add some elements and then try again." << endl;
	else
		while (tmpPtr != NULL)
		{
			outStr << tmpPtr->data << " " << endl;
			tmpPtr = tmpPtr->link;
		}
	return outStr;
}
