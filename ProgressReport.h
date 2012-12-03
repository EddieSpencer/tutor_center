//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Header file for progress report
//  Filename: ProgressReport.h
//  Last modified on: 11/30/12

#if!defined _ProgressReport_h
#define _ProgressReport_h

#include <iostream>
#include <string>
using namespace std;

bool getValidChoice();

class ProgressReport
{
private:
    string stud_name;
    string date;
    string attitude;
    string action;
    string next;
public:
    ProgressReport();
    void input();
    void output();
    bool operator>(ProgressReport&);

friend ostream& operator<<(ostream&, ProgressReport&);
friend istream& operator>>(istream&, ProgressReport&);
};

#endif
