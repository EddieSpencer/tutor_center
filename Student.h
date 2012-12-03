//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Header file for student
//  Filename: Student.h
//  Last modified on: 11/30/12

#if!defined STUDENT_H
#define STUDENT_H

#include "User.h"

#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

istream& getLong (istream&, long&);

class Student : public User
{
    private:


    public:
            Student();
            //Student(std::string, std::string, long);
            std::string getName();
            //Meeting signUp(Tutor, std::string,int, std::string);
            
            friend ostream& operator<<(ostream&, Student&);
            friend istream& operator>>(istream&, Student&);
};




#endif // STUDENT_H
