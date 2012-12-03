// Team Diversity
// Course: CSC 260, Section 01
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Collaborative Project
// Description: Header file for User class, which is the base class for types of users of the system
// Filename: User.h
// Last modified on: 11/30/12

#if!defined USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
	protected:
        std::string name;
		std::string email;
		long cell;
        int ID;
	public:
		User();
		//User(std::string, std::string, long);
		void setName(std::string);
		void setEmail(std::string);
		void setCell(long);
		void displayInfo();
        int getID();
};

#endif