// Team Diversity
// Course: CSC 260, Section 01
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Collaborative Project
// Description: User class, which is the base class for types of users of the system
// Filename: User.cpp
// Last modified on: 11/30/12

#include "User.h"
#include <iostream>
#include <string>

using namespace std;

//constructor
User::User()
{
    name = "no name";
    email = "no email";
    cell = 11111111111;
    ID = -1;
}

//virtual function to return name
std::string User::getName()
{
    ;
}

//virtual function to sign out
void User::signOut()
{
    ;
}

//sets user's name
void User::setName(std::string n)
{
	name = n;
}

//sets user's email
void User::setEmail(std::string e)
{
	email = e;
}

//sets user's cell
void User::setCell(long c)
{
	if (c >= 1000000000)
		cell = c;
	else
		cell = 0;
}

//returns the ID, used to differentiate between tutors and admins
int User::getID()
{
    return ID;
}