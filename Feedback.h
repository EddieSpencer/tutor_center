//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Header file for feedback forms
//  Filename: Feedback.h
//  Last modified on: 11/30/12

#if!defined _Feedback_h
#define _Feedback_h

#include <iostream>
#include <string>
using namespace std;

const int MAX_RATING = 10;

bool getValidSelection();
int getValidRating();

class Feedback
{
private:
    string tutor_name;
    string stud_name;
    int rating;
    string feedback;
public:
    Feedback();
    void input();
    void output();
    bool operator>(Feedback&);

friend ostream& operator<<(ostream&, Feedback&);
friend istream& operator>>(istream&, Feedback&);
};

#endif
