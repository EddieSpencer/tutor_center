//  Name: Team Diversity
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Collaborative Project
//  Description: Text-based interface for navigation by users
//  Filename: Interface.cpp
//  Last modified on: 11/30/12

#include "Interface.h"

//text-based interface for tutoring center
void Interface::menu()
{
    //loads the interface with values needed to navigate
    //also preloads several tutors, admins, and 1 meeting
    int user = 0, student_choice = 0, tutor_choice = 0, admin_choice = 0;
    bool anotherOp = true, main_screen = true;
    string passcode = "";
    Student student;
    Tutor tutor;
    Admin admin;
    Tutor tutor_array[10];
    Admin admin_array[5];
    Meeting meet_array[5];
    int meet_count = 0;
    
    LinkedList<Feedback> feedlist;
    PointerLinkedList userlist;
    MeetingList meetlist;
    
    ifstream tutorStream;
    tutorStream.open("Tutor1.txt");
    
    Tutor inputTutor, inputTutor2, inputTutor3;
    Admin inputAdmin, inputAdmin2;
    User *userPtr, *userPtr2, *userPtr3, *userPtr4, *userPtr5;
    Meeting inputMeeting;
    
    tutorStream >> inputTutor;
    tutor_array[0] = inputTutor;
    userPtr = &inputTutor;
    userlist.addElement(userPtr);
    
    tutorStream.close();
    
    ifstream tutorStream2;
    
    tutorStream.open("Tutor2.txt");
    
    tutorStream >> inputTutor2;
    tutor_array[1] = inputTutor2;
    userPtr2 = &inputTutor2;
    userlist.addElement(userPtr2);
    
    tutorStream.close();
    
    tutorStream.open("Tutor3.txt");
    
    tutorStream >> inputTutor3;
    tutor_array[2] = inputTutor3;
    userPtr3 = &inputTutor2;
    userlist.addElement(userPtr3);

    tutorStream.close();
    
    ifstream adminStream;
    
    adminStream.open("Admin1.txt");
    
    adminStream >> inputAdmin;
    admin_array[0] = inputAdmin;
    userPtr4 = &inputAdmin;
    userlist.addElement(userPtr4);
    
    adminStream.close();
    
    adminStream.open("Admin2.txt");
    
    adminStream >> inputAdmin2;
    admin_array[1] = inputAdmin2;
    userPtr5 = &inputAdmin2;
    userlist.addElement(userPtr5);
    
    adminStream.close();
    
    ifstream meetingStream;
    meetingStream.open("Meeting.txt");
    
    meetingStream >> inputMeeting;
    meetlist.addElement(inputMeeting);
    
    meetingStream.close();
    
    //begins the interface
    while (main_screen)
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Welcome to the TCNJ Tutoring Center!" << endl << "Please specify your type of user: " << endl;
        cout << "1 - Student" << endl;
        cout << "2 - Tutor" << endl;
        cout << "3 - Administrator" << endl;
        cout << "0 - Exit" << endl;
        cout << "-------------------------------------------------------------" << endl;
        
        user = getValidChoice(MAX_TYPE_USERS);
        
        cout << endl << endl << endl << endl;
        
        switch (user)
        {
            //if user chooses Student
            case 1:
            {
                while (anotherOp)
                {
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "Please choose an operation to perform: " << endl;
                    cout << "1 - Find Tutor" << endl;
                    cout << "2 - Request Discontinue" << endl;
                    cout << "3 - Give Feedback" << endl;
                    cout << "0 - Exit" << endl;
                    cout << "-------------------------------------------------------------" << endl;

                    student_choice = getValidChoice(STUDENT_OPTIONS);
                    
                    switch (student_choice)
                    {
                        case 1: //helps the student find a tutor
                        {
                            cout << "Find Tutor" << endl << endl << endl;
                            
                            cout << "Enter your student information, name, e-mail, and cell: " << endl;
                            cin >> student;
                             
                            cout << "Please enter the subject you are looking for in the following format (ECO101): " << endl;
                            string subject;
                            cin >> subject;
                            
                            cout << "Please enter a time that you are available. Enter 0 for the hour to exit the loop."  << endl; 
                            cout << "Minutes can only be 00 or 30" << endl;
                            
                            Time time;
                            cin >> time;
                            
                            Tutor availtutor[5];
                                                        
                            int k = 0;
                            for(int i = 0; i < 3; i++)
                            {
                                Tutor tutor = tutor_array[i];
                                if(tutor.hasSubject(subject) && tutor.hasTime(time))
                                {
                                    availtutor[k] = tutor;
                                    k++;
                                }
                            }
                            
                            if (availtutor[0].getName() == "no name")
                            {
                                cout << "No tutors available at that time" << endl << endl << endl;
                                break;
                            }
                            
                            Tutor signUp;
                            cout << "The tutors available are: " << endl;
                            for (int j = 0; j < k; j++)
                            {
                                cout << availtutor[j] << endl << endl;
                                signUp = availtutor[j];
                                
                            }
                                                        
                            bool choice;
                            cout << "Would you like to sign up with " << signUp.getName() << " (y/n)" << endl;
                            choice = getValidDecision();
                            
                            if (choice)
                            {
                                Meeting meet;
                                meet.setMeeting(student, signUp, time, subject);
                                meetlist.addElement(meet);
                                cout << "Signed up" << endl;
                            }
                                                        
                            break;
                        }
                        case 2: //helps the student discontinue a meeting
                        {
                            cout << "Enter your name" <<endl;
                            string stud, stud1, stud2;
                            cin >> stud1 >> stud2;
                            stud = stud1 + " " + stud2;
                            cout << "Enter the meeting time" <<endl;
                            Time t1;
                            cin >> t1;
                            Meeting meet;
                            
                            meetlist.getElement(stud, t1).discontinueMeeting();
                            meet_array[meet_count] = meetlist.getElement(stud, t1);
                            meet_count++;
                            cout << "Marked for discontinue" << endl << endl << endl;
                            break;
                        }
                        case 3: //allows the student to enter a feedback form
                        {
                            Feedback f;
                            f.input();
                            cout << "Feedback form stored" << endl;
                            feedlist.addElement(f);
                            break;
                        }
                        case 0: //returns to the main screen
                        {
                            cout << "Returning to Main Screen" << endl << endl << endl;
                            anotherOp = false;
                        }
                    }
                }
                anotherOp = true;
                break;
            }
//----------------------------------------------------------------------------                        
            //if user chooses tutor
            case 2:
            {
                //tutor signs in with linked list
                cout << "Enter name on file: " << endl;
                string name, name1, name2;
                cin >> name1 >> name2;
                name = name1 + " " + name2;
                Tutor in_tutor;
                bool found = false;
                
                for (int i = 0; i < 3; i++)
                {
                    if (name == tutor_array[i].getName())
                    {
                        in_tutor = tutor_array[i];
                        found = true;
                    }
                }
                
                if (!found)
                {
                    cout << "Name not found." << endl;
                    break;
                }
                
                //find tutor in linked list
                cout << "Tutor name found. Enter passcode: " << endl;
                echo(false);
                cin >> passcode; //call tutor method
                if (passcode == in_tutor.getPasscode())
                    cout << "Tutor account verified" << endl;
                else
                {
                    cout << "Incorrect" << endl;
                    echo(true);
                    break;
                }
                echo(true);
                
                //begins loop if tutor login successful                
                while (anotherOp)
                {
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "Please choose an operation to perform: " << endl;
                    cout << "1 - New Progress Report" << endl;
                    cout << "2 - View Progress Reports" << endl;
                    cout << "3 - Enter Hours" << endl;
                    cout << "4 - Enter Availability" << endl;
                    cout << "5 - Mark Absent" << endl;
                    cout << "0 - Sign Out" << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    
                    tutor_choice = getValidChoice(TUTOR_OPTIONS);

                    switch (tutor_choice)
                    {
                        case 1: //tutor enters new progress report
                        {
                            ProgressReport p;
                            p.input();
                            in_tutor.newForm(p);
                            cout << "Progress Report stored" << endl << endl << endl;
                            break;
                        }
                        case 2: //tutor views all current progress reports
                        {
                            cout << "View Progress Reports" << endl;
                            in_tutor.viewForms();
                            break;
                        }
                        case 3: //tutor enters hours worked
                        {
                            cout << "Enter Hours Worked" << endl;
                            int hr;
                            cin >> hr;
                            if (hr > 20 || hr < 1)
                                cout << "Hours must be between 1-20." << endl;
                            else
                            {
                                in_tutor.enterHours(hr);
                                cout << "Hours Added" << endl;
                            }
                            cout << endl << endl << endl;
                            break;
                        }
                        case 4: //tutor enters availability
                        {
                            cout << "Enter Availability" << endl;
                            in_tutor.enterAvailability(cin);
                            cout << "Availability succeeded" << endl << endl << endl;
                            break;
                        }
                        case 5: //tutor marks a student absent
                        {
                            cout << "Enter a student name" <<endl;
                            string stud, stud1, stud2;
                            cin >> stud1 >> stud2;
                            stud = stud1 + " " + stud2;
                            cout << "Enter a meeting time" <<endl;
                            Time t1;
                            cin >> t1;
                            Meeting meet;
                            
                            meetlist.getElement(stud, t1).logAbsence();
                            cout << "Marked Absent" << endl << endl << endl;
                            break;
                        }
                        case 0: //tutor signs out
                        {
                            in_tutor.signOut();
                            cout << "Signed-Out" << endl;
                            cout << "Returning to Main Screen" << endl << endl << endl;
                            anotherOp = false;
                        }
                    }
                }
                anotherOp = true;
                break;
            }
//----------------------------------------------------------------------------                        
            //if user chooses administrator
            case 3:
            {
                //admin signs in with linked list
                cout << "Enter name on file: " << endl;
                string name, name1, name2;
                cin >> name1 >> name2;
                name = name1 + " " + name2;
                bool found = false;
                
                Admin in_admin;
                
                for (int i = 0; i < 2; i++)
                {
                    if (name == admin_array[i].getName())
                    {
                        in_admin = admin_array[i];
                        found = true;
                    }
                }
                
                if (!found)
                {
                    cout << "Name not found." << endl;
                    break;
                }
                
                //find tutor in linked list
                cout << "Admin name found. Enter passcode: " << endl;
                echo(false);
                cin >> passcode; //call tutor method
                if (passcode == in_admin.getPasscode())
                    cout << "Admin account verified" << endl;
                else
                {
                    cout << "Incorrect" << endl;
                    echo(true);
                    break;
                }
                echo(true);
                

                //begins loop if admin log in successful            
                while (anotherOp)
                {
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "Please choose an operation to perform: " << endl;
                    cout << "1 - Schedule Student" << endl;
                    cout << "2 - View Meeting List" << endl;
                    cout << "3 - Discontinue Meeting" << endl;
                    cout << "4 - View Feedback" << endl;
                    cout << "0 - Sign Out" << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    
                    admin_choice = getValidChoice(ADMIN_OPTIONS);
                    
                    switch (admin_choice)
                    {
                        case 1: //admin schedules student
                        {
                            cout << "Schedule Student" << endl;
                            cout << "Find Tutor" << endl << endl << endl;

                            cout << "Enter the student information: name, e-mail, and cell: " << endl;
                            cin >> student;
                            
                            cout << "Please enter the subject you are looking for in the following format (ECO101): " << endl;
                            string subject;
                            cin >> subject;
                            
                            cout << "Please enter a time for a meeting. Enter 0 for the hour to exit the loop."  << endl; 
                            cout << "Minutes can only be 00 or 30" << endl;
                            
                            Time time;
                            cin >> time;
                            
                            Tutor availtutor[5];
                            
                            int k = 0;
                            for(int i = 0; i < 3; i++)
                            {
                                Tutor tutor = tutor_array[i];
                                if(tutor.hasSubject(subject) && tutor.hasTime(time))
                                {
                                    availtutor[k] = tutor;
                                    k++;
                                }
                            }
                            
                            if (availtutor[0].getName() == "no name")
                            {
                                cout << "No tutors available at that time" << endl << endl << endl;
                                break;
                            }
                            
                            Tutor signUp;
                            cout << "The tutors available are: " << endl;
                            for (int j = 0; j < k; j++)
                            {
                                cout << availtutor[j] << endl << endl;
                                signUp = availtutor[j];
                                
                            }
                            
                            bool choice;
                            cout << "Would you like to sign up " << student.getName() << " with " << signUp.getName() << " (y/n)" << endl;
                            choice = getValidDecision();
                            
                            if (choice)
                            {
                                Meeting meet;
                                meet.setMeeting(student, signUp, time, subject);
                                meetlist.addElement(meet);
                                cout << "Signed up" << endl;
                            }
                            
                            break;
                        }
                        case 2: //admin views all meetings
                        {
                            cout << "View Meeting List" << endl;
                            cout << meetlist << endl;
                            cout << endl << endl << endl;
                            
                            break;
                        }
                        case 3: //admin discontinues all meetings marked for discontinue
                        {
                            cout << "Discontinue Meeting" << endl;
                            for (int i = 0; i < meet_count; i++)
                            {
                                meetlist.removeElement(meet_array[i]);
                            }
                            meet_count = 0;
                            cout << "Removal completed" << endl << endl << endl;
                            break;
                        }
                        case 4: //admin views all feedback forms submitted
                        {
                            cout << "View Feedback" << endl;
                            cout << feedlist << endl << endl << endl;
                            break;
                        }
                        case 0: //admin signs out
                        {
                            in_admin.signOut();
                            cout << "Signed-Out" << endl;
                            cout << "Returning to Main Screen" << endl << endl << endl;
                            anotherOp = false;
                        }
                    }
                }
                anotherOp = true;
                break;
            }
//----------------------------------------------------------------------------            
            //if user chooses exit
            case 0:
            {
                cout << "Enter passcode to end program: " << endl;
                
                echo(false);
                cin >> passcode;
                echo(true);
                
                //exits if correct passcode, returns to main screen if incorrect
                if (passcode == "TCNJ")
                {
                    main_screen = false;
                    cout << "Exiting program" << endl << endl << endl;
                }
                else
                {
                    cout << "Incorrect Passcode" << endl;
                    cout << "Returning to Main Screen" << endl << endl << endl;
                }
            }
        }
    }
    
    return;
}

//gets valid choice to navigate interface menu
int getValidChoice(int max)
{
    bool tryAgain = true;
    int x = 0;
    
    while (tryAgain)
    {
        cin >> x;
        
        //ensures valid number is read in
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer between 0 and "  << max << ": " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((x < 0) || (x > max))
            cout << "Invalid input - Number must be between 0 and " << max << ": " << endl;
        else
            tryAgain = false;
    }
    
    return x;
}

//gets valid day for the find tutor functions
istream& getValidDay (istream& in, std::string & day)
{
    bool try_again = true;
    
    while (try_again)
    {
        in >> day;
        if (day != "M" && day !="T" && day !="W" && day !="Th" && day != "F")
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

//disables echo output for password input
void echo (bool on = true)
{
    struct termios settings;
    tcgetattr(STDIN_FILENO, &settings);
    settings.c_lflag = on
                     ? (settings.c_lflag | ECHO)
                     : (settings.c_lflag & ~(ECHO));
    tcsetattr (STDIN_FILENO, TCSANOW, &settings);
    
    return;
}

//gets valid y/n decision
bool getValidDecision()
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
