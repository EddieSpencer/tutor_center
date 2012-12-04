//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Tutor class, to represent tutors
//  Filename: Tutor.cpp
//  Last modified on: 11/30/12

#include "Tutor.h"

//constructor
Tutor::Tutor():User()
{
    name = "no name";
    email = "no email";
    cell = 11111111111;
    hoursWorked = 0;
    subjects[0] = "none";
    loggedIn = false;
    ID = 0;
    numForms = 0;
    progReports;
}

//checks that tutor has subject
bool Tutor::hasSubject(std::string subject)
{
    bool result = false;
    for(int i = 0; i<numSubjects; i++)
    {
        if(subjects[i].compare(subject) == 0)
            result = true;
    }
    return result;
}

//checks that tutor has time
bool Tutor::hasTime(Time t)
{
    bool result = false;
    for(int i = 0; i<numTimes;i++)
    {
        if(avail[i] == t)
            result = true;

    }
    return result;
}

//signs the tutor in if passcode is correct
bool Tutor::signIn(std::string pass)
{
    if(pass == passcode)
        loggedIn = true;
    else
        loggedIn = false;
    
    return loggedIn;
    
}

//signs the tutor out
void Tutor::signOut()
{
    loggedIn = false;
}

//adds new progress report to the linked list
void Tutor::newForm(ProgressReport rep)
{
    numForms++;
    progReports.addElement(rep);
}

//views all progress reports in linked list
void Tutor::viewForms()
{
    cout << progReports;
}

//inputs the number of hours worked
void Tutor::enterHours(int hours)
{
    if (hours > 0)
        hoursWorked = hours;
}

//returns tutor name
std::string Tutor::getName()
{
    return name;
}

//returns tutor email
std::string Tutor::getEmail()
{
    return email;
}

//returns tutor cell
long Tutor::getCell()
{
    return cell;
}

//returns tutor's hours worked
int Tutor::getHours()
{
    return hoursWorked;
}

//allows tutor to enter additional availability from the terminal
istream& Tutor::enterAvailability(istream &in)
{
    cout << "How many available times do you have (greater than 0): ";
    
    numTimes = getValidInt(in);
    
    while(numTimes <= 0 || numTimes > 20)
    {
        cerr << "Enter a valid number of times (between 0 and 20): ";
        
        numTimes = getValidInt(in);
    }
    
    Time newAvailability;
    
    for(int i = 0; i < numTimes; i++)
    {
        cout << "***Prepare to enter availability #" << (i + 1) << "***" << endl;
        in >> newAvailability;
        avail[i] = newAvailability;
    }
    
    cout << "How many subjects do you tutor (between 0 and 5): ";
    numSubjects = getValidInt(in);
    
    while(numSubjects <= 0 || numSubjects > 5)
    {
        cerr << "Enter a valid number of subjects (between 0 and 5): ";
        
        numSubjects = getValidInt(in);
    }
    
    std::string newSubject;
    
    for(int i = 0; i < numSubjects; i++)
    {
        cout << "***Prepare to enter subject #" << (i + 1) << "***" << endl;
        in >> newSubject;
        subjects[i] = newSubject;
    }

    return in;
}

//inputs availability from a file
ifstream& Tutor::enterAvailability(ifstream &in)
{
    
    numTimes = getValidInt(in);
    
    while(numTimes < 0 || numTimes > 20)
    {
        numTimes = getValidInt(in);
    }
    
    Time newAvailability;
    
    for(int i = 0; i < numTimes; i++)
    {
        in >> newAvailability;
        avail[i] = newAvailability;
    }
    
    numSubjects = getValidInt(in);
    
    while(numSubjects < 0 || numSubjects > 5)
    {
        
        numSubjects = getValidInt(in);
    }
    
    std::string newSubject;
    
    for(int i = 0; i < numSubjects; i++)
    {
        in >> newSubject;
        subjects[i] = newSubject;
    }
    
    return in;
}

//outputs the tutor object in input format
ostream& operator<<(ostream& out, Tutor& tutorObj)
{
    out << tutorObj.getName() << " " << tutorObj.getEmail() << " " << tutorObj.getCell() << " " << tutorObj.getHours()<< " ";
    out << tutorObj.numTimes << " ";
    for(int i = 0; i < tutorObj.numTimes; i++)
        out << tutorObj.avail[i] << " ";
    out << tutorObj.numSubjects << " ";
    for(int j = 0; j < tutorObj.numSubjects; j++)
        out << tutorObj.subjects[j] << " ";
    out << tutorObj.ID;
    out << tutorObj.numForms << endl;
    if (tutorObj.numForms > 0)
        out << tutorObj.progReports << endl;
    
    return out;
}

//inputs tutor object from terminal
istream& operator>>(istream &in, Tutor &current)
{
    std::string name1;
    std::string name2;
    
    in >> name1;
    in >> name2;
    
    current.name = name1 + " " + name2;
    
    in >> current.email;
    in >> current.cell;
    in >> current.hoursWorked;
 
    current.enterAvailability(in);
    in >> current.ID;
    in >> current.numForms;
    for(int i = 0; i < current.numForms; i++)
    {
        ProgressReport temp;
        in >> temp;
        current.progReports.addElement(temp);
    }
    return in;
}

//inputs tutor object from a file
ifstream& operator>>(ifstream& in, Tutor &current)
{
    std::string name1;
    std::string name2;
    
    in >> name1;
    in >> name2;
    
    current.name = name1 + " " + name2;
        
    in >> current.email;
    in >> current.cell;
    in >> current.hoursWorked;
    current.enterAvailability(in);
    in >> current.ID;
    in >> current.numForms;
    in >> current.passcode;
    
    if (current.numForms == 0)
        return in;
    
    for(int i = 0; i < current.numForms; i++)
    {
        ProgressReport temp;
        in >> temp;
        current.progReports.addElement(temp);
    }
    return in;
}

//returns tutor passcode
std::string Tutor::getPasscode()
{
    return passcode;
}

//gets valid int for entry
int Tutor::getValidInt (istream& in)
{
    bool tryAgain = true;
    int value;
    
    while (tryAgain)
    {
        in >> value;
        if (in.fail())
        {
            cerr << "*** Invalid Input *** Please enter an int value: ";
            in.clear();
            in.ignore (1000, '\n');
        }
        else
            tryAgain = false;
    }
    return value;
}


