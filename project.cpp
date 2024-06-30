#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include<curses.h>

using namespace std;
using std::cout;

string takePasswdFromUser()
{
    string ipt = "";
    char ipt_ch;
    while (true)
    {
        ipt_ch = std::cin.get();

        // Check whether user enters
        // a special non-printable
        // character
        if (ipt_ch < 32)
        {
            cout << endl;
            return ipt;
        }
        ipt.push_back(ipt_ch);
    }
    return ipt;
}

class student
{
private:
    string name;
    int enrollment;
    float cgpa;
    int attendance;
    string branch;

public:
    student(string fname, int fenrollmentNumber, string fbranch, float fcgpa, int fattendance)
    {
        name = fname;
        enrollment = fenrollmentNumber;
        branch = fbranch;
        attendance = fattendance;
        cgpa = fcgpa;

        // File functions

        ofstream outfile;
        outfile.open("student.txt", ios::app);
        outfile << enrollment << "\t";
        outfile << name << "\t";
        outfile << cgpa << "\t";
        outfile << attendance << "\t";
        outfile << branch << endl;
        outfile.close();
    }
};

void oopMarks(string branch, int enrollment, string name, int marks);
void phyMarks(string branch, int enrollment, string name, int marks);
void matMarks(string branch, int enrollment, string name, int marks);

int main()
{
    bool x = true;
    while (x)
    {
        int choice;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t\tWelcome to the Student Management System" << endl;
        cout << "\t\t\t\t\t\t\t1. Adding Student" << endl;
        cout << "\t\t\t\t\t\t\t2. Student Login" << endl;
        cout << "\t\t\t\t\t\t\t3. Admin View" << endl;
        cout << "\t\t\t\t\t\t\t4. Faculty Login" << endl;
        cout << "\t\t\t\t\t\t\t5. Exit\t      " << endl;
        cout << "\t\t\t\t\t\t\tEnter your choice:";
        cin >> choice;
        if (choice == 1)
        {
            string mName, mBranch;
            int mEnrollmentNumber, mAttendance, numberOfStudent = 0;
            float mCgpa;

            cout << "\t\t\t\t\t\t\tEnter the number of student you want to add:";
            cin >> numberOfStudent;

            for (int i = 0; i < numberOfStudent; i++)
            {

                cout << "\t\t\t\t\t\t\tEnter the enrollment of student " << i + 1 << ":";
                cin >> mEnrollmentNumber;

                cout << "\t\t\t\t\t\t\tEnter the name (name and surname separated by underscore):";
                cin >> mName;

                cout << "\t\t\t\t\t\t\tEnter the cgpa of last sem:";
                cin >> mCgpa;

                cout << "\t\t\t\t\t\t\tEnter the attendance:";
                cin >> mAttendance;

                cout << "\t\t\t\t\t\t\tEnter the branch (shortForm):";
                cin >> mBranch;

                string conformation;
                cout << "\t\t\t\t\t\t\tAre you sure you want to add the above student in database?" << endl;
                cout << "\t\t\t\t\t\t\tEnter(y/n):";
                cin >> conformation;
                if (conformation == "y" || conformation == "Y")
                {
                    cout << "\t\t\t\t\t\t\tData Entered";
                    student s1(mName, mEnrollmentNumber, mBranch, mCgpa, mAttendance);
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tData not entered in data base:";
                }
            }
        }
        else if (choice == 2)
        {
            int studentChoice = 0;
            cout << "\t\t\t\t\t\t\t1:Basic View:" << endl;
            cout << "\t\t\t\t\t\t\t2:Marks View:";
            cin >> studentChoice;

            if (studentChoice == 1)
            {

                char loginNumber[4];
                cout << "\t\t\t\t\t\t\tEnter the last 4 digit of your enrollment number:";
                cin >> loginNumber;

                int check = 0;
                char data[30];
                // File functions
                ifstream infile;
                infile.open("student.txt", ios::in);
                while (infile >> data)
                {
                    if (strcmp(data, loginNumber) == 0)
                    {
                        cout << "\t\t\t\t\t\t\tRegistration Number:" << data << endl;
                        infile >> data;
                        cout << "\t\t\t\t\t\t\tName:" << data << endl;
                        infile >> data;
                        cout << "\t\t\t\t\t\t\tCGPA:" << data << endl;
                        infile >> data;
                        cout << "\t\t\t\t\t\t\tAttendance:" << data << endl;
                        infile >> data;
                        cout << "\t\t\t\t\t\t\tBranch:" << data << endl;

                        check = 1;
                        infile.close();
                    }
                }
                if (check == 0)
                {
                    cout << "\t\t\t\t\t\t\tNo such student found:";
                }
            }
            else if (studentChoice == 2)
            {
                // Student marks view

                // student login number

                char loginNumber[4];
                cout << "\t\t\t\t\t\t\tEnter the last 4 digit of your enrollment number:";
                cin >> loginNumber;

                // File Functions

                int check = 0;
                char data[30];
                ifstream infile;
                infile.open("oop.txt", ios::in);
                while (infile >> data)
                {

                    if (strcmp(data, loginNumber) == 0)
                    {
                        // OOP file function
                        cout << "\t\t\t\t\t\t\tEnroll \t Name \t OOP \t PHY \t Maths" << endl;
                        cout << "\t\t\t\t\t\t\t" << data << "\t ";
                        infile >> data;
                        cout << data << "\t ";
                        infile >> data;
                        cout << data << "\t ";
                        infile.close();
                        check = 1;
                    }
                }
                if (check == 1)
                {
                    infile.open("phy.txt", ios::in);
                    while (infile >> data)
                    {
                        if (strcmp(data, loginNumber) == 0)
                        {
                            infile >> data;
                            infile >> data;
                            cout << data << "\t";
                            infile.close();
                            check = 2;
                            if (check == 2)
                            {

                                infile.open("mat.txt", ios::in);
                                while (infile >> data)
                                {
                                    if (strcmp(data, loginNumber) == 0)
                                    {
                                        infile >> data;
                                        infile >> data;
                                        cout << data << "\t";
                                        infile.close();
                                        // check == 3;
                                    }
                                }
                            }
                        }
                    }
                }

                else if (check == 0)
                {
                    cout << "\t\t\t\t\t\t\tNo such enrollment number found:";
                }
            }
        }
        else if (choice == 3)
        {
            string password;
            cout << "\t\t\t\t\t\t\tEnter Admin password";
            password = takePasswdFromUser();
            if (password == "admin123")
            {
                int adminCheck = 0;
                string adminEnroll;
                char data[30];
                cout << "\t\t\t\t\t\t\tEnroll \t Name \t CGPA \t Atten \t Branch  OOP \t PHY \t MATHS" << endl;
                // File Function

                ifstream infile;
                ifstream oopFile;
                ifstream phyFile;
                ifstream matFile;
                infile.open("student.txt", ios::in);
                while (infile >> data)
                {
                    adminEnroll = data;
                    cout << "\t\t\t\t\t\t\t" << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    adminCheck = 1;

                    // Marks presentation views
                    // OOP marks

                    if (adminCheck == 1)
                    {
                        oopFile.open("oop.txt", ios::in);
                        while (oopFile >> data)
                        {
                            if (data == adminEnroll)
                            {
                                oopFile >> data;
                                oopFile >> data;
                                cout << data << "\t";
                                oopFile.close();
                                adminCheck = 2;

                                // Physics marks

                                if (adminCheck == 2)
                                {
                                    phyFile.open("phy.txt", ios::in);
                                    while (phyFile >> data)
                                    {
                                        if (data == adminEnroll)
                                        {
                                            phyFile >> data;
                                            phyFile >> data;
                                            cout << data << "\t";
                                            phyFile.close();
                                            adminCheck = 3;
                                            // Maths marks
                                            if (adminCheck == 3)
                                            {
                                                matFile.open("mat.txt", ios::in);
                                                while (matFile >> data)
                                                {
                                                    if (data == adminEnroll)
                                                    {
                                                        matFile >> data;
                                                        matFile >> data;
                                                        cout << data << endl;
                                                        matFile.close();
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (choice == 4)
        {
            int subjectCode = 0;
            cout << "\t\t\t\t\t\t\tEnter your subject code:" << endl;
            cout << "\t\t\t\t\t\t\t1. OOP" << endl;
            cout << "\t\t\t\t\t\t\t2. Physics" << endl;
            cout << "\t\t\t\t\t\t\t3. Maths:" << endl;
            cout << "\t\t\t\t\t\t\t4. CGPA list:";
            cin >> subjectCode;
            if (subjectCode == 1)
            {

                string password;
                cout << "\t\t\t\t\t\t\tEnter faculty password:";
                password = takePasswdFromUser();
                if (password == "oop123" || password == "admin123")
                {

                    // OOP faculty functions

                    int oopChoice = 0;
    
                    cout << "\t\t\t\t\t\t\tFaculty option:" << endl;
                    cout << "\t\t\t\t\t\t\t1. Enter marks" << endl;
                    cout << "\t\t\t\t\t\t\t2. View marks";
                    cin >> oopChoice;
                    if (oopChoice == 1 && password == "admin123")
                    {
                        cout << "\t\t\t\t\t\t\tAdmin can't enter marks:";
                    }
                    else if (oopChoice == 1 && password == "oop123")
                    {
                        int oopNumberOfStudent;
                        cout << "\t\t\t\t\t\t\tEnter the number of student:";
                        cin >> oopNumberOfStudent;
                        for (int i = 0; i < oopNumberOfStudent; i++)
                        {
                            string oName, oBranch;
                            int oEnrollment, oMarks;

                            cout << "\t\t\t\t\t\t\tEnter " << i + 1 << " student's Branch:";
                            cin >> oBranch;
                            cout << "\t\t\t\t\t\t\tEnter student's Enrollment number:";
                            cin >> oEnrollment;
                            cout << "\t\t\t\t\t\t\tEnter student's Name:";
                            cin >> oName;
                            cout << "\t\t\t\t\t\t\tEnter student's Marks:";
                            cin >> oMarks;
                            oopMarks(oBranch, oEnrollment, oName, oMarks);
                        }
                    }
                    else if (oopChoice == 2)
                    {
                        string oopStudentBranch;
                        int check = 0;
                        char data[30];
                        int count = 0;

                        ifstream f("oop.txt");
                        string line;

                        for (int i = 0; std::getline(f, line); i++)
                        {
                            count++;
                        }

                        cout << "\t\t\t\t\t\t\tEnter the branch:";
                        cin >> oopStudentBranch;

                        ifstream infile;
                        infile.open("oop.txt", ios::in);
                        cout << "\t\t\t\t\t\t\tName \t Marks" << endl;
                        while (infile >> data)
                        {
                            if (data == oopStudentBranch)
                            {
                                infile >> data;
                                infile >> data;
                                cout << "\t\t\t\t\t\t\t" << data << "\t";
                                infile >> data;
                                cout << data << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "\t\t\t\t\t\t\tNo such option available:";
                    }
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tPassword incorrect:";
                }
            }
            else if (subjectCode == 2)
            {

                // Physics faculty Functions


                string password;
                cout << "\t\t\t\t\t\t\tEnter faculty password:";
                password = takePasswdFromUser();
                if (password == "phy123" || password == "admin123")
                {
                    int phyChoice = 0;
    
                    cout << "\t\t\t\t\t\t\tFaculty option:" << endl;
                    cout << "\t\t\t\t\t\t\t1. Enter marks" << endl;
                    cout << "\t\t\t\t\t\t\t2. View marks";
                    cin >> phyChoice;
                    if (phyChoice == 1 && password == "admin123")
                    {
                        cout << "\t\t\t\t\t\t\tAdmin can't enter marks:";
                    }
                    else if (phyChoice == 1 && password == "phy123")
                    {
                        int phyNumberOfStudent;
                        cout << "\t\t\t\t\t\t\tEnter the number of student:";
                        cin >> phyNumberOfStudent;
                        for (int i = 0; i < phyNumberOfStudent; i++)
                        {
                            string oName, oBranch;
                            int oEnrollment, oMarks;

                            cout << "\t\t\t\t\t\t\tEnter " << i + 1 << " student's Branch:";
                            cin >> oBranch;
                            cout << "\t\t\t\t\t\t\tEnter student's Enrollment number:";
                            cin >> oEnrollment;
                            cout << "\t\t\t\t\t\t\tEnter student's Name:";
                            cin >> oName;
                            cout << "\t\t\t\t\t\t\tEnter student's Marks:";
                            cin >> oMarks;
                            phyMarks(oBranch, oEnrollment, oName, oMarks);
                        }
                    }
                    else if (phyChoice == 2)
                    {
                        string phyStudentBranch;
                        int check = 0;
                        char data[30];
                        int count = 0;

                        ifstream f("phy.txt");
                        string line;

                        for (int i = 0; std::getline(f, line); i++)
                        {
                            count++;
                        }

                        cout << "\t\t\t\t\t\t\tEnter the branch:";
                        cin >> phyStudentBranch;

                        ifstream infile;
                        infile.open("phy.txt", ios::in);
                        cout << "\t\t\t\t\t\t\tName \t Marks" << endl;
                        while (infile >> data)
                        {
                            if (data == phyStudentBranch)
                            {
                                infile >> data;
                                infile >> data;
                                cout << "\t\t\t\t\t\t\t" << data << "\t";
                                infile >> data;
                                cout << data << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "\t\t\t\t\t\t\tNo such option available:";
                    }
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tPassword incorrect:";
                }
            }
            else if (subjectCode == 3)
            {

                // Maths faculty Functions


                string password;
                cout << "\t\t\t\t\t\t\tEnter faculty password:";
                password = takePasswdFromUser();
                if (password == "mat123" || password == "admin123")
                {
                    int matChoice = 0;
    
                    cout << "\t\t\t\t\t\t\tFaculty option:" << endl;
                    cout << "\t\t\t\t\t\t\t1. Enter marks" << endl;
                    cout << "\t\t\t\t\t\t\t2. View marks";
                    cin >> matChoice;
                    if (matChoice == 1 && password == "admin123")
                    {
                        cout << "\t\t\t\t\t\t\tAdmin can't enter marks:";
                    }
                    else if (matChoice == 1 && password == "mat123")
                    {
                        int matNumberOfStudent;
                        cout << "\t\t\t\t\t\t\tEnter the number of student:";
                        cin >> matNumberOfStudent;
                        for (int i = 0; i < matNumberOfStudent; i++)
                        {
                            string oName, oBranch;
                            int oEnrollment, oMarks;

                            cout << "\t\t\t\t\t\t\tEnter " << i + 1 << " student's Branch:";
                            cin >> oBranch;
                            cout << "\t\t\t\t\t\t\tEnter student's Enrollment number:";
                            cin >> oEnrollment;
                            cout << "\t\t\t\t\t\t\tEnter student's Name:";
                            cin >> oName;
                            cout << "\t\t\t\t\t\t\tEnter student's Marks:";
                            cin >> oMarks;
                            matMarks(oBranch, oEnrollment, oName, oMarks);
                        }
                    }
                    else if (matChoice == 2)
                    {
                        string matStudentBranch;
                        int check = 0;
                        char data[30];
                        int count = 0;

                        ifstream f("mat.txt");
                        string line;

                        for (int i = 0; std::getline(f, line); i++)
                        {
                            count++;
                        }

                        cout << "\t\t\t\t\t\t\tEnter the branch:";
                        cin >> matStudentBranch;

                        ifstream infile;
                        infile.open("mat.txt", ios::in);
                        cout << "\t\t\t\t\t\t\tName \t Marks" << endl;
                        while (infile >> data)
                        {
                            if (data == matStudentBranch)
                            {
                                infile >> data;
                                infile >> data;
                                cout << "\t\t\t\t\t\t\t" << data << "\t";
                                infile >> data;
                                cout << data << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "\t\t\t\t\t\t\tNo such option available:";
                    }
                }
                else
                {
                    cout << "\t\t\t\t\t\t\tPassword incorrect:";
                }
            }
            else if (subjectCode == 4)
            {
                // CGPA List logic


                int count = 0;
                ifstream f("student.txt");
                string line;

                for (int i = 0; std::getline(f, line); i++)
                {
                    count++;
                }
                ifstream infile;
                infile.open("student.txt", ios::in);
                char data[20];
                cout << "\t\t\t\t\t\t\tName \t CGPA" << endl;
                for (int i = 0; i < count; i++)
                {
                    infile >> data;
                    infile >> data;
                    cout << "\t\t\t\t\t\t\t" << data << "\t";
                    infile >> data;
                    cout << data << endl;
                    infile >> data;
                    infile >> data;
                }
                infile.close();
            }
            else
            {
                cout << "\t\t\t\t\t\t\tNo such option available:";
            }
        }
        else if (choice == 5)
        {
            x = false;
        }
        else
        {
            cout << "\t\t\t\t\t\t\tNo such option available:";
        }
    }
    return 0;
}

void oopMarks(string branch, int enrollment, string name, int marks)
{
    ofstream outfile;
    outfile.open("oop.txt", ios::app);
    outfile << branch << "\t";
    outfile << enrollment << "\t";
    outfile << name << "\t";
    outfile << marks << endl;
    outfile.close();
}

void phyMarks(string branch, int enrollment, string name, int marks)
{
    ofstream outfile;
    outfile.open("phy.txt", ios::app);
    outfile << branch << "\t";
    outfile << enrollment << "\t";
    outfile << name << "\t";
    outfile << marks << endl;
    outfile.close();
}

void matMarks(string branch, int enrollment, string name, int marks)
{
    ofstream outfile;
    outfile.open("mat.txt", ios::app);
    outfile << branch << "\t";
    outfile << enrollment << "\t";
    outfile << name << "\t";
    outfile << marks << endl;
    outfile.close();
}