//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Header file for meeting
//  Filename: Meeting.h
//  Last modified on: 11/30/12

#if!defined MEETING_H
#define MEETING_H

#include "Student.h"
#include "Tutor.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Meeting
{
    
private:
    //instance data for meeting object
    //holds tutor, student, time, subject, and several flags
    Time time;
    std::string subject;
    Tutor tutor;
    Student student;
    bool discontinue;
    int timesAbsent;
    
public:
    //constructors
    Meeting(Student, Tutor, Time, std::string, int);
    Meeting();
    
    //functions to access instance data, compare instance data, and
    //input/output instance data
    void logAbsence();
    
    Student getStudent();
    Tutor getTutor();
    
    Time getTime();
    void setTime(Time);
    
    void changeMeeting(Time);
    
    void discontinueMeeting();
    
    void setMeeting(Student, Tutor, Time, std::string);
    bool operator>(Meeting&);
    bool operator<(Meeting&);
    bool operator==(Meeting&);
    bool operator!=(Meeting&);

    void output();
    
    friend ostream& operator<<(ostream&, Meeting&);//FOR PRINTING MEETINGS TO A FILE(FILE OPENED IN LINKED LIST)
    friend istream& operator>>(istream&, Meeting&);//FOR READING MEETINGS FROM FILE(FILE OPENED IN LINKED LIST)
    friend ifstream& operator>>(ifstream&, Meeting&);
    
};
#endif 
