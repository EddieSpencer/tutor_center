// Team Diversity
// Course: CSC 260, Section 01
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Collaborative Project
// Description: Linked list header file
// Filename: PointerLinkedList.h
// Last modified on: 11/30/12

#include "PointerLinkedList.h"


PointerLinkedList::PointerLinkedList()
{
	// ensure pointer is initialized to a valid value
	headPtr = NULL;
	currentPos = headPtr;
	length = 0;
	lastPtr = NULL;
    
}

int PointerLinkedList::getLength()
{
    return length;
}


//sorted version
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

bool PointerLinkedList::isEmpty()
{
    if(headPtr==NULL)
        return true;
    else
        return false;
}

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
