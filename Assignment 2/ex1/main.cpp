using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <map>
#include "Student.h"
#include "Person.h"

vector<Student> studentList;

// A function that takes a line from the students file as an argument and separates it into each word and assigns
// it to the correct variables like name and regNo. It then creates a new student and returns it.
Student newStudent(const string& line)
{
    string word;
    string studentName;

    int studentRegNo = 0;
    int counter = 0;

    istringstream iss(line);

    while (iss >> word)
    {
        if (counter == 0)
        {
            istringstream(word) >> studentRegNo;
        }else{
            studentName += word;
        }

        if (counter == 1)
        {
            studentName += " ";
        }

        counter ++;
    }
    Student student = Student(studentName, studentRegNo);
    return student;
}

// A function that takes a line from the marks file as an argument and seperates it into the correct variables like
// regNo, module and mark. It then compares each of the students regNo to the one from the marks file and adds it
// to the student map else it prints that it was unable to find the student with a matching regNo
void addMark(const string& line)
{
    string word;
    string module;

    int regNo = 0;

    float mark = 0;

    bool foundStudent = false;

    istringstream iss(line);

    int counter = 0;

    while (iss >> word)
    {
        if (counter == 0)
        {
            module = word;
        }

        if (counter == 1)
        {
            istringstream(word) >> regNo;
        }

        if (counter == 2)
        {
            istringstream(word) >> mark;
        }

        counter ++;
    }

    for (Student s : studentList)
    {

        if (s.getRegNo() == regNo)
        {
            s.addMark(module, mark);
            foundStudent = true;
        }
    }

    if (!foundStudent)
    {
        cout << "No student with registration number '"<< regNo << "' could have been found." << endl;
    }
}

// A function to display all the students from the vector alongside with their marks for each
// of their modules
void displayStudents()
{
    for (Student s : studentList)
    {
        cout << s.getName() << " "<<s.getRegNo() << endl;
        s.printMarks();
        cout << endl;
    }
}

// The first function as specified in the specification
void firstFunction(const vector<Student>& Students, float mark)
{
    for (Student s : Students)
    {
        float maxMark = s.getMaxMark();

        if (maxMark >= mark)
        {
            cout << s << endl;
        }
    }
}

// Second function that prints students names and mark for a module (specified by user) where they got less
// than the specified mark.
void secondFunction(const vector<Student>& Students, const string& module, float mark)
{
    bool foundStudents = false;

    for (const Student& s : Students)
    {
        float moduleMark = s.getMark(module);

        if (0 < moduleMark && moduleMark >= mark)
        {
            cout << s.getName() << " " << moduleMark << endl;
            foundStudents = true;
        }
    }

    if (!foundStudents)
    {
        cout << "Could not find any students with marks for module '" << module << "'." << endl;
    }
}

// A short function to display which file was unable to be opened
void end(string filename)
{
    cout << "Failed to open " << filename << endl;
    exit(EXIT_FAILURE);
}

// The main part of the code
int main ()
{
    string studentFileName;
    string marksFileName;
    string option;
    string module;
    string line;
    string word;

    ifstream studentFile;
    ifstream marksFile;

    bool filesOpen = false;

    float mark;

    cout << "\nPlease enter the name of the file which contains the students data (with .txt extension at the end)" << endl;
    cin >> studentFileName;
    cout << "\nPlease enter the name of the file which contains the students marks (with .txt extension at the end)" << endl;
    cin >> marksFileName;

    studentFile.open(studentFileName);
    marksFile.open(marksFileName);

    // Check if the files are open
    // run end if either of them is not open
    if (studentFile)
    {
        if (marksFile)
        {
            filesOpen = true;
        }else{
            end(marksFileName);
        }
    }else{
        end(studentFileName);
    }

    if (filesOpen)
    {
        // Get data from the student file
        while (studentFile.good())
        {
            getline(studentFile, line);
            if (!line.empty())
            {
                Student tempStudent = newStudent(line);
                if (tempStudent.getRegNo() != 0)
                {
                    studentList.push_back(tempStudent);
                }
            }
        }

        // Get data from the marks file
        while (marksFile.good())
        {
            getline(marksFile, line);
            if (!line.empty())
            {
                addMark(line);
            }
        }

        // Display the names of all the students in the vector and their marks for each module.
        displayStudents();

        // A while loop to keep looping and asking the user to pick one of the 3 choices until they choose to quit
        while (option != "3")
        {
            cout << "\nPlease pick one of the 3 options (enter 1,2, or 3)\n\n1. First function\n2. Second function\n3. Quit" << endl;
            cin >> option;

            while (option != "1" && option != "2" && option != "3")
            {
                cout << "\nInvalid input !\n\nPlease pick one of the 3 options (enter 1,2, or 3)\n\n1. First function\n2. Second function\n3. Quit" << endl;
                cin >> option;
            }

            if (option == "1")
            {
                cout << "\nPlease enter a mark to be used as the second argument for the first function (type float)" << endl;
                cin >> mark;

                while (0.0 > mark || 100.0 < mark)
                {
                    cout << "\nInvalid input !\n\nPlease make sure the mark is within the range of 0.0 - 100.0\n\nPlease enter the mark again" << endl;
                    cin >> mark;
                }

                firstFunction(studentList, mark);
            }

            if (option == "2")
            {
                cout << "\nPlease enter the module number to be used as the second argument for the second function (type string)" << endl;
                cin >> module;
                cout << "\nPlease enter the mark to be used as the third argument for the second function (type float)" << endl;
                cin >> mark;

                while (0.0 > mark || 100.0 < mark)
                {
                    cout << "\nInvalid input !\n\nPlease make sure the mark is within the range of 0.0 - 100.0\n\nPlease enter the mark again" << endl;
                    cin >> mark;
                }

                secondFunction(studentList, module, mark);
            }
        }
    }
}