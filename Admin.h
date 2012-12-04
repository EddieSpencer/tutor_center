// Team Diversity
// Course: CSC 260, Section 01
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Collaborative Project
// Description: Header file for Admin class
// Filename: Admin.h
// Last modified on: 11/30/12

#if!defined(ADMIN_H)
#define ADMIN_H

#include "User.h"
#include "Meeting.h"
#include "Time.h"
#include "Student.h"
#include "Tutor.h"
#include <iostream>
#include <string>

using namespace std;

class Admin : public User
{
	private:
        //instance data for an admin object
		bool loggedIn;
        std::string passcode;
	public:
        //functions for admin that allow for signing in and out,
        //accessors, and input/output
		Admin();
        bool signIn(std::string);
		void signOut();
        std::string getPasscode();
        std::string getName();
		friend ostream& operator<<(ostream &out, Admin &adminObj);
		friend istream& operator>>(istream &in, Admin &adminObj);
};

#endif