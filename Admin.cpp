// Team Diversity
// Course: CSC 260, Section 01
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Collaborative Project
// Description: Admin class
// Filename: Admin.cpp
// Last modified on: 11/30/12

#include "Admin.h"
#include <iostream>
#include <string>

using namespace std;

//constructor for user
Admin::Admin():User()
{
	loggedIn = false;
	ID = 1;
}

//checks that passcode matches what is on file
bool Admin::signIn(std::string pass)
{
    if(pass == passcode)
        loggedIn = true;
    else
        loggedIn = false;
    
    return loggedIn;
}

//signs out the admin
void Admin::signOut()
{
	loggedIn = false;
}

//gets the passcode
std::string Admin::getPasscode()
{
    return passcode;
}

//returns the admin's name
std::string Admin::getName()
{
    return name;
}

//Outputs the admin object
ostream& operator<<(ostream &out, Admin &adminObj)
{
    if (adminObj.loggedIn)
	    out << adminObj.name << " " << adminObj.email << " " << adminObj.cell << " Logged in" << endl;
	else
	    out << adminObj.name << " " << adminObj.email << " " << adminObj.cell << " Not logged in" << endl;
    return out;
}

//inputs the admin object from a file
istream& operator>>(istream &in, Admin &adminObj)
{
    std::string name1;
    std::string name2;
    
    in >> name1;
    in >> name2;
    
    adminObj.name = name1 + " " + name2;
    
    in >> adminObj.email;
    in >> adminObj.cell;
    in >> adminObj.passcode;
    
    return in;   
}