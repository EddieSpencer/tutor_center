//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Meeting class, holding student, tutor, and time
//  Filename: Meeting.cpp
//  Last modified on: 11/30/12

#include "Meeting.h"

//constructor for Meeting
Meeting::Meeting(Student newStudent, Tutor newTutor, Time newTime, std::string newSubject, int newAbsence)
{
    student = newStudent;
    tutor = newTutor;
    time = newTime;
    timesAbsent = newAbsence;
    subject = newSubject;
    discontinue = false;
}

//additional constructor
Meeting::Meeting()
{
    subject = "";
    timesAbsent = 0;
    discontinue = false;
}

//sets a meeting with parameterized data
void Meeting::setMeeting(Student newStudent, Tutor newTutor, Time newTime, std::string newSubject)
{
    student = newStudent;
    tutor = newTutor;
    time = newTime;
    subject = newSubject;
    discontinue = false;
}

//changes the meeting time
void Meeting::changeMeeting(Time newTime)
{
    time = newTime;
}

//returns the meeting time
Time Meeting::getTime()
{
    return time;
}

//sets the meeting time
void Meeting::setTime(Time newTime)
{
    time = newTime;
}

//returns the student object
Student Meeting::getStudent()
{
    return student;
}

//returns the tutor object
Tutor Meeting::getTutor()
{
    return tutor;
}

//increments the number of absences by 1
void Meeting::logAbsence()
{
    timesAbsent++;
    if(timesAbsent >= 2)
    {
        discontinue = true;
    }
}

//sets discontinue flag to true
void Meeting::discontinueMeeting()
{
    discontinue = true;
}

//overloaded operator for linked list
bool Meeting::operator>(Meeting& meet)
{
    if (tutor.getName() > meet.tutor.getName())
        return true;
    else if (tutor.getName() == meet.tutor.getName())
    {
        if (time > meet.time)
            return true;
        else
            return false;
    }
    else
        return false;
}

//overloaded operator for linked list
bool Meeting::operator<(Meeting& meet)
{
    if (tutor.getName() < meet.tutor.getName())
        return true;
    else if (tutor.getName() == meet.tutor.getName())
    {
        if (time < meet.time)
            return true;
        else
            return false;
    }
    else
        return false;
}

//equality operator overload for linked list
bool Meeting::operator==(Meeting& meet)
{
    if (tutor.getName() == meet.tutor.getName() && time == meet.time)
        return true;
    else
        return false;
}

//inequality operator overload for linked list
bool Meeting::operator!=(Meeting& meet)
{
    if (tutor.getName() == meet.tutor.getName() && time == meet.time)
        return false;
    else
        return true;
}

//output function to output meeting data to terminal
void Meeting::output()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "Meeting" << endl;
    cout << "Student: " << student.getName() << endl;
    cout << "Tutor: " << tutor.getName() << endl;
    cout << "Time: " << time.getDay() << " " << time.getHour() << ":" << time.getMinute() << endl;
    cout << "Subject: " << subject << endl;
    cout << "Discontinue: " << discontinue << endl;
    cout << "Times Absent: " << timesAbsent << endl;
    cout << "---------------------------------------------------------" << endl;
}

//output function to output meeting data to file
ostream& operator<<(ostream &out, Meeting &current)
{
    out << current.student << " " << current.tutor << " " << current.time << " " << current.subject << " " << current.timesAbsent << endl;
    
    return out;
}

//inputs meeting data from terminal
istream& operator>>(istream& in, Meeting &current)
{
    Student newStudent;
    Tutor newTutor;
    Time newTime;
    std::string newSubject;
    
    in >> newStudent;
    in >> newTutor;
    in >> newTime;
    in >> newSubject;
    
    current.setMeeting(newStudent, newTutor, newTime, newSubject);
    
    return in;
}

//inputs meeting data from a file
ifstream& operator>>(ifstream& in, Meeting &current)
{
    Student newStudent;
    Tutor newTutor;
    Time newTime;
    string newSubject;
    
    in >> newStudent;
    in >> newTutor;
    in >> newTime;
    in >> newSubject;
    current.setMeeting(newStudent, newTutor, newTime, newSubject);
    return in;
}