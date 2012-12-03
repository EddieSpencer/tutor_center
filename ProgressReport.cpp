//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Progress report for use by tutors
//  Filename: ProgressReport.cpp
//  Last modified on: 11/30/12

#include "ProgressReport.h"

ProgressReport::ProgressReport()
{
    stud_name = "";
    date = "";
    attitude = "";
    action = "";
    next = "";
}

void ProgressReport::input()
{
    bool tryAgain = true;
    cin.ignore(1);
    
    while (tryAgain)
    {
        cout << "Please enter the student's name: " << endl;
        getline (cin, stud_name, '\n');
    
        cout << endl << "Is " << stud_name << " correct(y/n)?" << endl;
        tryAgain = !(getValidChoice());
        cin.ignore(1); //clears the getline
        cout << endl;
    }
    tryAgain = true;
    
    while (tryAgain)
    {
        cout << "Please enter the meeting date: " << endl;
        getline (cin, date, '\n');
        
        cout << endl << "Is " << date << " correct(y/n)?" << endl;
        tryAgain = !(getValidChoice());
        cin.ignore(1); //clears the getline
        cout << endl;
    }
    tryAgain = true;
    
    while (tryAgain)
    {
        cout << "Please enter the student's attitude: " << endl;
        getline (cin, attitude, '\n');
        
        cout << endl << "Is " << attitude << " correct(y/n)?" << endl;
        tryAgain = !(getValidChoice());
        cin.ignore(1); //clears the getline
        cout << endl;
    }
    tryAgain = true;
    
    while (tryAgain)
    {
        cout << "Please enter the tasks accomplished: " << endl;
        getline (cin, action, '\n');
        
        cout << endl << "Is the following correct(y/n)?" << endl;
        cout << "\"" << action << "\"" << endl;
        tryAgain = !(getValidChoice());
        cin.ignore(1); //clears the getline
        cout << endl;
    }
    tryAgain = true;
    
    while (tryAgain)
    {
        cout << "Please enter the goals for the next session: " << endl;
        getline (cin, next, '\n');
        cout << endl << "Is the following correct(y/n)?" << endl;
        cout << "\"" << next << "\"" << endl;
        tryAgain = !(getValidChoice());
        cin.ignore(1); //clears the getline
        cout << endl;
    }
    
    cout << "Progress report complete." << endl << endl;
}

void ProgressReport::output()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "Progress Report" << endl;
    cout << "Student Name: " << stud_name << endl;
    cout << "Meeting Date: " << date << endl;
    cout << "Student Attitude: " << attitude << endl;
    cout << "Tasks Completed: " << action << endl;
    cout << "Goals for next session: " << next << endl;
    cout << "---------------------------------------------------------" << endl;
}

bool ProgressReport::operator>(ProgressReport& rep)
{
    if (stud_name > rep.stud_name)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& stream, ProgressReport& report)
{
    stream << report.stud_name << " " << report.date << " " << report.attitude << " " << report.action  << " " << report.next << endl;

    return stream;
}

istream& operator>>(istream& stream, ProgressReport& report)
{
    stream >> report.stud_name >> report.date >> report.attitude >> report.action >> report.next;
    
    return stream;
}

bool getValidChoice()
{
    bool tryAgain = true;
    bool choice = false;
    char value;
    
    while (tryAgain)
    {
        cin >> value;
        
        //ensures good value is read
        if ((cin.fail()) || !((tolower(value) == 'y') || (tolower(value) == 'n')))
        {
            cout << "Invalid input - Please enter a character value (y/n): " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
            tryAgain = false;
    }
    
    //converts y/n to boolean
    if (tolower(value) == 'y')
        choice = true;
    
    return choice;
}