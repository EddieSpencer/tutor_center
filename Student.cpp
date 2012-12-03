//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Student class, to represent students
//  Filename: Student.cpp
//  Last modified on: 11/30/12

#include <iostream>
#include "student.h"

Student::Student():User()
{
}

std::string Student::getName()
{
    return name;
}

ostream& operator<<(ostream &out, Student &studObj)
{
    out << studObj.name << " " << studObj.email << " " << studObj.cell << endl;
    return out;
}

istream& operator>>(istream &in, Student &studObj)
{
    std::string name1;
    std::string name2;
    
    in >> name1;
    in >> name2;
    
    studObj.name = name1 + " " + name2;
        
    in >> studObj.email;
    
    getLong(in, studObj.cell);

    return in;
}

istream& getLong (istream& in, long & value)
{
    bool try_again = true;
    
    while (try_again)
    {
        in >> value;
        if (in.fail())
        {
            cout << "*** invalid input *** Please enter a cell phone number: ";
            in.clear();
            in.ignore (1000, '\n');
        }
        else
            try_again = false;
    }
    return in;
}
