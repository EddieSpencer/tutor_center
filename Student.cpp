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

//constructor
Student::Student():User()
{
}

//accessor for student name
std::string Student::getName()
{
    return name;
}

//sign out function for student
void Student::signOut()
{
    cout << "Student signed out" << endl;
    return;
}

//output for student object
ostream& operator<<(ostream &out, Student &studObj)
{
    out << studObj.name << " " << studObj.email << " " << studObj.cell << endl;
    return out;
}

//input for student object
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

//getLong function for cell number input
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
