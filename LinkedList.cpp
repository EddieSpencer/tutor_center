//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: LinkedList methods to be executed
//  Filename: LinkedList.cpp
//  Last modified on: 11/30/12

#include "LinkedList.h"
using namespace std;

//constructor for the linked list
template <class T>
LinkedList<T>::LinkedList()
{
	// ensure pointer is initialized to a valid value
	headPtr = NULL;
	currentPos = headPtr;
	length = 0;
	lastPtr = NULL;

}

//sorted version
//adds an element to the linked list
template <class T>
void LinkedList<T>::addElement(T item)
{
	Node<T>* currPtr;
    Node<T>* prevPtr;
    Node<T>* tempPtr;
	tempPtr = new Node<T>;
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

//destructor for the LinkedList
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* tempPtr;
    Node<T>* currPtr = headPtr;
    while(currPtr!=NULL)
    {
        tempPtr = currPtr;
        currPtr = currPtr->link;
        delete tempPtr;
    }
}

//overwrites the copy instructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
    Node<T>* fromPtr;
    Node<T>* toPtr;
    if (list.headPtr == NULL)
    {
        headPtr = NULL;
        return;
    }
    fromPtr = list.headPtr;
    headPtr = new Node<T>;
    headPtr->data = fromPtr->data;
    toPtr = headPtr;
    fromPtr = fromPtr->link;
    while(fromPtr != NULL)
    {
        toPtr->link = new Node<T>;
        toPtr = toPtr->link;
        toPtr->data = fromPtr->data;
        fromPtr = fromPtr->link;
    }
    toPtr->link = NULL;
    lastPtr = toPtr;
}

//removes an element from the linked list
template <class T>
void LinkedList<T>::removeElement(T item)
{

   Node<T>* prevPtr = NULL;
   Node<T>* currPtr = headPtr;
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

//returns boolean true if list is empty
template <class T>
bool LinkedList<T>::isEmpty()
{
    if(headPtr==NULL)
        return true;
    else
        return false;
}

//deletes each member of the list
template <class T>
void LinkedList<T>::clearList()
{
    Node<T>* tempPtr;
    Node<T>* currPtr = headPtr;
    while(currPtr!=NULL)
    {
        tempPtr = currPtr;
        currPtr = currPtr->link;
        delete tempPtr;
    }
}

//merges two linked lists
template <class T>
LinkedList<T> LinkedList<T>::merge(const LinkedList<T> &rhs)
{
    LinkedList<T> list;
    
    Node<T>* tempPtr1 = headPtr;
    Node<T>* tempPtr2 = rhs.headPtr;
    
    while(tempPtr1 != NULL)
    {
        list.addElement(tempPtr1 -> data);
        tempPtr1 = tempPtr1->link;
    }
    
    while(tempPtr2 != NULL)
    {
        list.addElement(tempPtr2 -> data);
        tempPtr2 = tempPtr2 -> link;
    }
    
    return list;
}

//overwrites the assignment operator for the linked list
template <class T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList<T>& list)
{
    Node<T>* fromPtr;
    Node<T>* toPtr;
    if (list.headPtr == NULL)
    {
        headPtr = NULL;
    }
    else
    {
        fromPtr = list.headPtr;
        headPtr = new Node<T>;
        headPtr->data = fromPtr->data;
        toPtr = headPtr;
        fromPtr = fromPtr->link;
        while(fromPtr != NULL)
        {
            toPtr->link = new Node<T>;
            toPtr = toPtr->link;
            toPtr->data = fromPtr->data;
            fromPtr = fromPtr->link;
        }
        toPtr->link = NULL;
        lastPtr = toPtr;
    }
    return *this;
}

//inputs the linked list from a file
template <class T>
bool LinkedList<T>::inputFromFile (string inFileName)
{
	bool worked = true;
	ifstream inStr;
	T element;
    
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
		addElement(element);
	}
    
	inStr.close();
	return worked;
}

//outputs all the items in the linked list to a file
template <class T>
void LinkedList<T>::writeToFile(string outFileName)
{
    Node<T>* tmpPtr = headPtr;
    ofstream out;
    
    out.open(outFileName.c_str());
    
    while(tmpPtr != NULL)
    {
        out << tmpPtr->data << endl;
        tmpPtr = tmpPtr->link;
    }
    
    out.close();
}

//outputs the linked list to the terminal
template <class S>
ostream& operator <<(ostream& outStr, LinkedList<S>& rhs)
{
	Node<S>* tmpPtr = rhs.headPtr;
	outStr << endl;
	if (rhs.isEmpty())
		outStr << "Sorry, the list is empty. Add some forms and try again." << endl;
	else
		while (tmpPtr != NULL)
		{
			tmpPtr->data.output();
			tmpPtr = tmpPtr->link;
		}
	return outStr;
}






