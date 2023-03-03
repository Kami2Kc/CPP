using namespace std;

#include <string>
#include <iostream>
#include "Student.h"

Student::Student(const string &name, int regNo) : Person(name)
{
    this->regNo = regNo;
    this->marks.clear();
}

int Student::getRegNo() const
{
    return regNo;
}

void Student::addMark(const string &module, float mark)
{
    //to add new
    marks.insert(make_pair(module, mark));

    // to update value
    //marks[module] = mark;
}

float Student::getMark(const string &module) const
{
    cout << marks.at(module) << endl;
    return marks.at(module);
}

void Student::printMarks()
{
   // map<string, float>::const_iterator it;

    if (marks.empty()){
        cout << "Map is empty" << endl;
    }

    for (auto & mark : marks)
    {
        cout << "Module : " << mark.first << "   mark : " << mark.second << endl;
    }
}

// A function to calculate the average mark for the student
float Student::getAverageMark() const
{
    float sumOFMarks = 0;
    float numberOfModules = 0;

    map<string, float>::const_iterator it;

    for (it = marks.begin(); it != marks.end(); it++)
    {
        sumOFMarks += it->second;
        numberOfModules ++;
    }

    sumOFMarks = sumOFMarks/numberOfModules;

    return sumOFMarks;
}

// A function to calculate the minimum mark for the student
float Student::getMinMark() const
{
    float minMark = 100;

    map<string, float>::const_iterator it;

    for (it = marks.begin(); it != marks.end(); it++)
    {
        if (it->second < minMark && it->second != 0.0)
        {
            minMark = it->second;
        }
    }

    return minMark;
}

// A function to calculate the maximum mark for the student
float Student::getMaxMark() const
{
    float maxMark = 0;

    map<string, float>::const_iterator it;

    for (it = marks.begin(); it != marks.end(); it++)
    {
        if (it->second > maxMark)
        {
            maxMark = it->second;
        }
    }

    return maxMark;
}

ostream &operator<<(ostream &str, const Student &s)
{
    float minMark = s.getMinMark();
    float maxMark = s.getMaxMark();
    float avgMark = s.getAverageMark();

    if (avgMark != 0.0)
    {
        cout << s.getName() << " " << s.getRegNo() << " min mark -> " << minMark << " max mark -> " << maxMark << " avg mark -> " << avgMark << endl;
    }else{
        cout << "Student " << s.getName() << " does not have marks." << endl;
    }

    return str;
}