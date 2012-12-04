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
        //instance data for a user
        std::string name;
		std::string email;
		long cell;
        int ID;
	public:
		User(); //constructor
        //accessors and mutators
		void setName(std::string);
		void setEmail(std::string);
		void setCell(long);
        int getID();
        virtual std::string getName();
        //function to sign user out
        virtual void signOut();
};

#endif