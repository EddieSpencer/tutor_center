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

const int MAX_RATING = 10; //sets max rating at ten

bool getValidSelection(); //gets valid choice of y/n
int getValidRating(); //gets valid number for rating, between 1-10

class Feedback
{
private:
    //instance data for feedback
    //holds student and tutor names, a rating, and a comments section
    string tutor_name;
    string stud_name;
    int rating;
    string feedback;
public:
    //Functions for feedback, allows for input and output from console and file
    Feedback();
    void input();
    void output();
    bool operator>(Feedback&);

friend ostream& operator<<(ostream&, Feedback&);
friend istream& operator>>(istream&, Feedback&);
};

#endif
