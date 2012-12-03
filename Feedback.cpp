//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Progress report for use by tutors
//  Filename: ProgressReport.cpp
//  Last modified on: 11/30/12

#include "Feedback.h"

Feedback::Feedback()
{
    tutor_name = "";
    stud_name = "";
    rating = 0;
    feedback = "";
}

void Feedback::input()
{
    bool tryAgain = true;
    cin.ignore(1);
    
    while (tryAgain)
    {
        cout << "Please enter the tutor's name: " << endl;
        getline (cin, tutor_name, '\n');
    
        cout << endl << "Is " << tutor_name << " correct(y/n)?" << endl;
        tryAgain = !(getValidSelection());
        cin.ignore(1); //clears the getline
        cout << endl;
    }
    tryAgain = true;
    
    while (tryAgain)
    {
        cout << "Please enter your name: " << endl;
        getline (cin, stud_name, '\n');
        
        cout << endl << "Is " << stud_name << " correct(y/n)?" << endl;
        tryAgain = !(getValidSelection());
        cin.ignore(1); //clears the getline
        cout << endl;
    }
    tryAgain = true;
    
    while (tryAgain)
    {
        cout << "Please rank the tutor on a scale of 1-"  << MAX_RATING << " (" << MAX_RATING << " being the best): " << endl;
        rating = getValidRating();
        
        cout << endl << "Is " << rating << " correct(y/n)?" << endl;
        tryAgain = !(getValidSelection());
        cin.ignore(1); //clears the getline
        cout << endl;
    }
    tryAgain = true;
    
    while (tryAgain)
    {
        cout << "Please enter any tutor feedback you may have: " << endl;
        getline (cin, feedback, '\n');
        
        cout << endl << "Is the following correct(y/n)" << endl;
        cout << "\"" << feedback << "\"" << endl;
        tryAgain = !(getValidSelection());
        cin.ignore(1); //clears the getline
        cout << endl;
    }
    
    cout << "Feedback form complete." << endl << endl;
}

void Feedback::output()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "Feedback Form" << endl;
    cout << "Tutor Name: " << tutor_name << endl;
    cout << "Student Name: " << stud_name << endl;
    cout << "Rating (1-10): " << rating << endl;
    cout << "Additional Feedback: " << feedback << endl;
    cout << "---------------------------------------------------------" << endl;
}

bool Feedback::operator>(Feedback& rep)
{
    if (tutor_name > rep.tutor_name)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& stream, Feedback& feed)
{
    stream << feed.tutor_name << " " << feed.stud_name << " " << feed.rating << " " << feed.feedback << endl;

    return stream;
}

istream& operator>>(istream& stream, Feedback& feed)
{
    stream >> feed.tutor_name >> feed.stud_name >> feed.rating >> feed.feedback;
    
    return stream;
}

bool getValidSelection()
{
    bool tryAgain = true;
    bool selection = false;
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
        selection = true;
    
    return selection;
}

int getValidRating()
{
    bool tryAgain = true;
    int x = 0;
    
    while (tryAgain)
    {
        cin >> x;
        
        //ensures valid number is read in
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer between 0 and "  << MAX_RATING << ": " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((x < 1) || (x > MAX_RATING))
            cout << "Invalid input - Number must be between 0 and " << MAX_RATING << ": " << endl;
        else
            tryAgain = false;
    }
    
    return x;
}