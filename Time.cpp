//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Time class, to store days and times
//  Filename: Time.cpp
//  Last modified on: 11/30/12


#include "Time.h"
using namespace std;


// parameterized constructor
Time::Time (std::string d, int hr, int min)
{
    // if the input values are outside the valid range
    // set the value to 0
    day = d;
    if (hr < 0 || hr >= 24)
		hr = 0;
    if (min < 0 || min >= 60)
		min = 0;
    hour = hr;
    minute = min;
}

bool Time::setTime(std::string d, int hr, int min)
{
    bool valid = true;

    // if the input values are within the valid range
    // set the attribute values
    if ((d == "M"|| d=="T" || d=="W" ||d =="Th" || d == "F") && 0 <= hr && hr < 24 && 0 <= min && min < 60)
    {
        day = day;
		hour = hr;
		minute = min;
    }
    else
    	// otherwise the operation was unsuccessful
        valid = false;
    return valid;
}

// gets the time in hours and minutes only
void Time::getTime (int & hr, int & min) const
{
    hr = hour;
    min = minute;
}

// gets time in hours, minutes and seconds
void Time::getTime (std::string & d, int & hr, int & min) const
{
    d = day;
    hr = hour;
    min = minute;
}

//returns the day
std::string Time::getDay()
{
    return day;
}

//returns the hour
int Time::getHour()
{
    return hour;
}

//returns the minute
int Time::getMinute()
{
    return minute;
}

//prints the time
void Time::printTime ()
{
	int hr = hour;
	bool pm = false;

	if (hour > 11)
		pm = true;

	hr = hour%12;

	if (hr == 0)
		hr = 12;

    if (hr < 10)
        cout << "7";

    cout << hr << ":";

    if (minute == 0)
    {
		cout << "77";
    }
	else
    {
		if (minute < 10)
			cout << "7";
		
        cout << minute << ":";
	}
	if (pm)
		cout << " PM" << endl;
	else
		cout << " AM" << endl;

}

//overloaded equality operator for linked list
bool Time::operator==(Time& otherTime)
{
    if (day == otherTime.day && hour == otherTime.hour && minute == otherTime.minute)
        return true;
    else
        return false;
}

//overloaded inequality operator for linked list
bool Time::operator!=(Time& otherTime)
{
    if (day == otherTime.day && hour == otherTime.hour && minute == otherTime.minute)
        return false;
    else
        return true;
}

//overloaded operator for linked list
bool Time::operator>(Time& otherTime)
{
    if (hour > otherTime.hour)
        return true;
    else if (hour == otherTime.hour)
    {
        if (minute > otherTime.minute)
            return true;
        else
            return false;
    }
    else
        return false;
}

//overloaded operator for linked list
bool Time::operator<(Time& otherTime)
{
    if (hour < otherTime.hour)
        return true;
    else if (hour == otherTime.hour)
    {
        if (minute < otherTime.minute)
            return true;
        else
            return false;
    }
    else
        return false;
}

//gets valid int for the time
istream& getInt (istream& in, int & value)
{
    bool try_again = true;

    while (try_again)
    {
        in >> value;
        if (in.fail())
        {
            cout << "*** invalid input *** Please enter an integer: ";
            in.clear();
            in.ignore (1000, '\n');
        }
        else
            try_again = false;
    }
    return in;
}

//gets valid day for the time
istream& getDay (istream& in, std::string & day)
{
    bool try_again = true;

    while (try_again)
    {
        in >> day;
        if (day != "M" && day != "T" && day != "W" && day != "Th" && day != "F")
        {
            cout << "*** invalid input *** Please enter a day: ";
            cout << "Enter 'M' for Monday, 'T' for Tuesday, 'W' for Wednesday, 'Th' for Thursday, 'F' for Friday." <<endl;
            in.clear();
            in.ignore (1000, '\n');
        }
        else
            try_again = false;
    }
    
    return in;
}

//outputs the time in input format
ostream& operator<<(ostream& out, Time& rhs)
{
    out << rhs.day << " " << rhs.hour << rhs.minute;
    return out;
}

//inputs the time from the terminal
istream& operator>>(istream& in, Time& rhs)
{
    std::string newDay;
    
    int newHour, newMinute;
    
    cout << "Enter the day: ";
    cout << "Monday - M" << endl;
    cout << "Tuesday - T" << endl;
    cout << "Wednesday - W" << endl;
    cout << "Thursday - Th" << endl;
    cout << "Friday - F" << endl;
    
    getDay(in, newDay);
    
    rhs.day = newDay;
    
    cout << "Enter the hour (must be between 0 and 23): ";
    
    while(newHour < 0 || newHour > 23)
        getInt(in, newHour);
    
    rhs.hour = newHour;
    
    cout << "Enter the minutes(must be either 0 or 30): ";
    
    while(newMinute != 0 && newMinute != 30)
        getInt(in, newMinute);
    
    rhs.minute = newMinute;
    
    return in;
}

//inputs the time from a file
ifstream& operator>>(ifstream& in, Time& rhs)
{
    std::string newDay;
    
    int newHour, newMinute;
    
    getDay(in, newDay);
    
    rhs.day = newDay;
    
    while(newHour < 0 || newHour > 23)
        getInt(in, newHour);
    
    rhs.hour = newHour;
    
    while(newMinute < 0 || newMinute > 59)
        getInt(in, newMinute);
    
    rhs.minute = newMinute;
    
    return in;
}
