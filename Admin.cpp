// Team Diversity
// Course: CSC 260, Section 01
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Collaborative Project
// Description: Admin class
// Filename: Admin.cpp
// Last modified on: 11/30/12

#include "Admin.h"
#include <iostream>
#include <string>

using namespace std;

Admin::Admin():User()
{
	loggedIn = false;
	ID = 1;
}

bool Admin::signIn(std::string pass)
{
    if(pass == passcode)
        loggedIn = true;
    else
        loggedIn = false;
    
    return loggedIn;
}

void Admin::signOut()
{
	loggedIn = false;
}

std::string Admin::getPasscode()
{
    return passcode;
}

std::string Admin::getName()
{
    return name;
}

ostream& operator<<(ostream &out, Admin &adminObj)
{
    if (adminObj.loggedIn)
	    out << adminObj.name << " " << adminObj.email << " " << adminObj.cell << " Logged in" << endl;
	else
	    out << adminObj.name << " " << adminObj.email << " " << adminObj.cell << " Not logged in" << endl;
    return out;
}

istream& operator>>(istream &in, Admin &adminObj)
{
    std::string name1;
    std::string name2;
    
    in >> name1;
    in >> name2;
    
    adminObj.name = name1 + " " + name2;
    
    in >> adminObj.email;
    in >> adminObj.cell;
    in >> adminObj.passcode;
    
    return in;   
}

Meeting createMeeting (Student stu, Tutor tut)
{
	Time t;
	std::string subject;
	int timesAbsent = 0;

	cout << "What time is the meeting? ";
	cin >> t;
	cout << "What subject? ";
	cin >> subject;
	Meeting meeting = Meeting(stu, tut, t, subject, timesAbsent);
	return meeting;
}

Meeting reschedule(Meeting& meeting)
{
	cout << meeting << endl;
	cout << "Enter new time: ";
    Time temp;
	cin >> temp;
    meeting.setTime(temp);
	return meeting;
}