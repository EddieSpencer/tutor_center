//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Header file for tutor
//  Filename: Tutor.h
//  Last modified on: 11/30/12

#if!defined TUTOR_H
#define TUTOR_H

#include "Time.h"
#include "ProgressReport.h"
#include "User.h"
#include "LinkedList.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int MAXAVAIL = 20;

class Tutor : public User
{
private:
    int hoursWorked;
    Time avail[MAXAVAIL];
    int numTimes;
    std::string subjects[MAXAVAIL];
    std::string passcode;
    int numSubjects;
    bool loggedIn;
    LinkedList<ProgressReport> progReports;
    int numForms;
    
public:
    Tutor();
    bool hasSubject(std::string);
    bool hasTime(Time);
    bool signIn(std::string);
    bool signOut();
    std::string getName();
    std::string getEmail();
    std::string getPasscode();
    long getCell();
    int getHours();
    void newForm(ProgressReport);
    void viewForms();
    int getValidInt(istream&);
    void enterHours(int);
    istream& enterAvailability(istream&);
    ifstream& enterAvailability(ifstream&);
    friend ostream& operator<<(ostream &, Tutor &);
    friend istream& operator>>(istream &, Tutor &);
    friend ifstream& operator>>(ifstream &, Tutor &); 
};

#endif // TUTOR_H
