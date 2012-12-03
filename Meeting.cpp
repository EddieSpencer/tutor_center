//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Meeting class, holding student, tutor, and time
//  Filename: Meeting.cpp
//  Last modified on: 11/30/12

#include "Meeting.h"


Meeting::Meeting(Student newStudent, Tutor newTutor, Time newTime, std::string newSubject, int newAbsence)
{
    student = newStudent;
    tutor = newTutor;
    time = newTime;
    timesAbsent = newAbsence;
    subject = newSubject;
    discontinue = false;
}

Meeting::Meeting()
{
    subject = "";
    timesAbsent = 0;
    discontinue = false;
}

void Meeting::setMeeting(Student newStudent, Tutor newTutor, Time newTime, std::string newSubject)
{
    student = newStudent;
    tutor = newTutor;
    time = newTime;
    subject = newSubject;
    discontinue = false;
}

void Meeting::changeMeeting(Time newTime)
{
    time = newTime;
}

Time Meeting::getTime()
{
    return time;
}

void Meeting::setTime(Time newTime)
{
    time = newTime;
}

Student Meeting::getStudent()
{
    return student;
}


Tutor Meeting::getTutor()
{
    return tutor;
}

void Meeting::logAbsence()
{
    timesAbsent++;
    if(timesAbsent >= 2)
    {
        discontinue = true;
    }
}

void Meeting::discontinueMeeting()
{
    discontinue = true;
}

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

bool Meeting::operator==(Meeting& meet)
{
    if (tutor.getName() == meet.tutor.getName() && time == meet.time)
        return true;
    else
        return false;
}

bool Meeting::operator!=(Meeting& meet)
{
    if (tutor.getName() == meet.tutor.getName() && time == meet.time)
        return false;
    else
        return true;
}

void Meeting::output()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "Meeting" << endl;
    cout << "Student: " << student.getName() << endl;
    cout << "Tutor: " << tutor.getName() << endl;
    cout << "Time: " << time.getDay() << " " << time.getHour() << ":" << time.getMinute() << endl;
    cout << "Subject: " << subject << endl;
    cout << "---------------------------------------------------------" << endl;
}

ostream& operator<<(ostream &out, Meeting &current)
{
    out << current.student << " " << current.tutor << " " << current.time << " " << current.subject << " " << current.timesAbsent << endl;
    
    return out;
}

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