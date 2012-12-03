// Team Diversity
// Course: CSC 260, Section 01
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Collaborative Project
// Description: Linked list to hold meetings
// Filename: MeetingList.cpp
// Last modified on: 11/30/12


#include "MeetingList.h"


MeetingList::MeetingList()
{
	// ensure pointer is initialized to a valid value
	headPtr = NULL;
	currentPos = headPtr;
	length = 0;
	lastPtr = NULL;

}


//sorted version
void MeetingList::addElement (ItemType item)
{

	nodePtr currPtr, prevPtr, tempPtr;
	tempPtr = new MeetingNode;
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
MeetingList::~MeetingList()
{
    nodePtr tempPtr;
    nodePtr currPtr = headPtr;
    while(currPtr!=NULL)
    {
        tempPtr = currPtr;
        currPtr = currPtr->link;
        delete tempPtr;
    }
}

MeetingList::MeetingList(const MeetingList& list)
{
    nodePtr fromPtr;
    nodePtr toPtr;
    if (list.headPtr == NULL)
    {
        headPtr = NULL;
        return;
    }
    fromPtr = list.headPtr;
    headPtr = new MeetingNode;
    headPtr->data = fromPtr->data;
    toPtr = headPtr;
    fromPtr = fromPtr->link;
    while(fromPtr != NULL)
    {
        toPtr->link = new MeetingNode;
        toPtr = toPtr->link;
        toPtr->data = fromPtr->data;
        fromPtr = fromPtr->link;
    }
    toPtr->link = NULL;
    lastPtr = toPtr;
}

void MeetingList::removeElement (ItemType item)
{

   nodePtr prevPtr = NULL;
   nodePtr currPtr = headPtr;
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

ItemType MeetingList::getElement (string stud, Time t)
{

   nodePtr prevPtr = NULL;
   nodePtr currPtr = headPtr;
   while(currPtr !=NULL && currPtr->data.getStudent().getName() < stud && currPtr->data.getTime() != t)
   {
       prevPtr = currPtr;
       currPtr = currPtr->link;
   }
   if(currPtr !=NULL && currPtr->data.getStudent().getName() == stud && currPtr->data.getTime() == t)
   {
        return currPtr->data;
   }
}

MeetingList MeetingList::operator=(const MeetingList& list)
{
    nodePtr fromPtr;
    nodePtr toPtr;
    if (list.headPtr == NULL)
    {
        headPtr = NULL;
    }
    fromPtr = list.headPtr;
    headPtr = new MeetingNode;
    headPtr->data = fromPtr->data;
    toPtr = headPtr;
    fromPtr = fromPtr->link;
    while(fromPtr != NULL)
    {
        toPtr->link = new MeetingNode;
        toPtr = toPtr->link;
        toPtr->data = fromPtr->data;
        fromPtr = fromPtr->link;
    }
    toPtr->link = NULL;
    lastPtr = toPtr;

    return *this;
}

bool MeetingList::isEmpty()
{
    if(headPtr==NULL)
        return true;
    else
        return false;
}

void MeetingList::clearList()
{
    nodePtr tempPtr;
    nodePtr currPtr = headPtr;
    while(currPtr!=NULL)
    {
        tempPtr = currPtr;
        currPtr = currPtr->link;
        delete tempPtr;
    }
}

MeetingList MeetingList::merge(const MeetingList& rhs)
{
    MeetingList list1;

    nodePtr tmpPtr1 = headPtr;
    nodePtr tmpPtr2 = rhs.headPtr;

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

ostream& operator << (ostream& outStr, MeetingList& rhs)
{
	nodePtr tmpPtr = rhs.headPtr;
	outStr << endl;
	if (rhs.isEmpty())
		outStr << "Sorry, the list is empty. Add some elements and then try again." << endl;
	else
		while (tmpPtr != NULL)
		{
			tmpPtr->data.output();
            outStr << " " << endl;
			tmpPtr = tmpPtr->link;
		}
	return outStr;
}

bool MeetingList::inputFromFile(string inFileName, MeetingList &meet)
{
    bool worked = true;
    ifstream inStr;
    Meeting element;
    
    do
    {
        inStr.open (inFileName.c_str());
        if (inStr.fail())
        {
            cerr << "Error opening file. Try again." << endl;
            inStr.clear();
            inStr.ignore(80, '\n');
            worked = false;
            return worked;
        }
        else
            worked = true;
        
    } while (!worked);
    
    while (!inStr.eof())
    {
        inStr >> element;
        meet.addElement(element);
    }
    
    inStr.close();
    return worked;
}


void MeetingList::writeToFile(string outFileName)
{
    nodePtr tempPtr = headPtr;
    ofstream out;
    
    out.open(outFileName.c_str());
    
    while(tempPtr != NULL)
    {
        out << tempPtr->data << endl;
        tempPtr = tempPtr->link;
    }
    
    out.close();
}

