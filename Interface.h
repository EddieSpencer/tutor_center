//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Text-based interface header file
//  Filename: Interface.h
//  Last modified on: 11/30/12

#if!defined _Interface_h
#define _Interface_h

#include <fstream>
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include "ProgressReport.h"
#include "Feedback.h"
#include "Student.h"
#include "User.h"
#include "Time.h"
#include "Tutor.h"
#include "Admin.h"
#include "MeetingList.h"
#include "LinkedList.h"
#include "Meeting.h"
#include "PointerLinkedList.h"
using namespace std;

const int MAX_TYPE_USERS = 3;
const int TUTOR_OPTIONS = 5;
const int STUDENT_OPTIONS = 3;
const int ADMIN_OPTIONS = 4;

int getValidChoice(int);
//PRE: User is prompted to make a choice
//POST: Valid choice is made, based on number of choices
//PARAM: int - Number of choices
//RETURN: int - Number representing choice

bool getValidDecision();

istream& getValidDay(istream&, std::string&);

void echo(bool);
//PRE: User wants to enter passcode, input needs to be masked
//POST: User has entered pascode, further input will not be masked
//PARAM: bool - flag to disable or reinstate terminal echo
//RETURN: NONE
//disables echo output for password input

class Interface
{
public:
    //using g++ default constructor
    
    void menu();
    //PRE: User wants to enter tutoring center operations
    //POST: User has performed all desired operations
    //PARAM: NONE
    //RETURN: NONE
};

#endif
