// Team Diversity
// Course: CSC 260, Section 01
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Collaborative Project
// Description: Meeting List header file
// Filename: MeetingList.h
// Last modified on: 11/30/12

#if !defined(MEETINGLIST_H)
#define MEETINGLIST_H
#include "Meeting.h"
#include "Student.h"
#include "Time.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;



typedef Meeting ItemType;
struct MeetingNode
{
	ItemType data;
	MeetingNode* link;
};
typedef MeetingNode* nodePtr;


class MeetingList
{

private:

	nodePtr headPtr;
	nodePtr currentPos;
	nodePtr lastPtr;
    int length;

public:

    MeetingList();
	~MeetingList();
	MeetingList(const MeetingList&);
    MeetingList merge(const MeetingList&);

    void addElement(ItemType);
	void removeElement (ItemType);
	bool isEmpty();
	void clearList();
	ItemType& getElement (string, Time);


    void writeToFile(string);
    bool inputFromFile(string, MeetingList&);

    MeetingList operator=(const MeetingList&);

	friend ostream& operator <<(ostream&, MeetingList&);
    
};
#endif
