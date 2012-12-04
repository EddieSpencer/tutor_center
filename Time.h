//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Header file for time
//  Filename: Time.h
//  Last modified on: 11/30/12


#if!defined TIME_H
#define TIME_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Time
{

private:
    //instance data for time
    std::string day;
    int hour;
    int minute;


public:
    Time (std::string = "" , int = 0, int = 0); //constructor
    //accessors and mutators
    bool setTime (std::string, int, int = 0);
    void getTime (int &, int &) const;
    void getTime (std::string &, int &, int &) const;
    std::string getDay();
    int getHour();
    int getMinute();
    //functions to compare two times
    bool operator==(Time&);
    bool operator!=(Time&);
    bool operator>(Time&);
    bool operator<(Time&);
    
    //input/output functions for time
    void printTime ();
    friend ostream& operator<<(ostream&, Time&);
    friend istream& operator>>(istream&, Time&);
    friend ifstream& operator>>(ifstream&, Time&);
};

#endif

istream& getDay (istream&, std::string &);
istream& getInt (istream&, int &);

