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

User::User()
{
    name = "no name";
    email = "no email";
    cell = 11111111111;
    ID = -1;
}

/*User::User(std::string n, std::string e, long c)
{
	name = n;
	email = e;
    ID = -1;
	if (c >= 1000000000)
		cell = c;
	else
		cell = 0;
}
 */

void User::setName(std::string n)
{
	name = n;
}

void User::setEmail(std::string e)
{
	email = e;
}

void User::setCell(long c)
{
	if (c >= 1000000000)
		cell = c;
	else
		cell = 0;
}

void User::displayInfo()
{
	cout << "Name: " << name << endl;
	cout << "Email: " << email << endl;
	cout << "Cell: " << cell << endl;
}

int User::getID()
{
    return ID;
}