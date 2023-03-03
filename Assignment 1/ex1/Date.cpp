using namespace std;

#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>

// An array of 3 int to be used for the ++ and -- operators. I used this as you cannot return multiple values
int newDate[3] = {0,0,0};

// Sets default date values if none are provided
Date::Date()
{
    d = 1;
    m = 1;
    y = 2019;
}

// Checks each date values provided so that they are within range and makes sure day values are acceptable for each month
// and for leap year february. Sets default values if any are out of range.
Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
    int daysInFeb = 28;

    d = day;
    m = month;
    y = year;

    if (d < 1 || d > 31)
    {
        d = 1;
        cout << "Invalid date value for day." << endl;
    }

    if (m < 1 || m > 12)
    {
        m = 1;
        cout << "Invalid date value for month." << endl;
    }

    if (y < 1000 || y > 9999)
    {
        y = 2019;
        cout << "Invalid date value for year." << endl;
    }

    if (isLeapYear())
    {
        daysInFeb = 29;
    }

    if (m == 2)
    {
        if (d > daysInFeb)
        {
            d = 1;
            cout << "Invalid date value for day." << endl;
        }
    }

    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        if (d > 30)
        {
            d = 1;
            cout << "Invalid date value for day." << endl;
        }
    }
}

// Uses a int argument for year to check if the year is a leap year and returns appropriate bool value.
// I made this function to allow all other functions and operators to access it.
bool checkForLeapYear(int y)
{
    if (y % 100 == 0)
    {

        if (y % 400 == 0)
        {
            return true;
        }

        else {
            return false;
        }
    }

    else{
        if (y % 4 == 0)
        {
            return true;
        }

        else{
            return false;
        }
    }
}

// uses the function above to check if the year provided is a leap year and returns a bool value
bool Date::isLeapYear() const
{
    return checkForLeapYear(y);
}

// nextDate function takes 3 int arguments to get the next date and stores the new date in an int array
// created at the top of this file. This function can be reused by both ++ operators
// uses int maxDays to know how many days are in the current month to make sure date is valid and if the day is the last
// day of the month it will move the date to the next month and set day value to 1.
int nextDate(int d, int m, int y)
{
    int maxDays = 31;

    if (m == 2)
    {
        if (checkForLeapYear(y))
        {
            maxDays = 29;
        }

        else{
            maxDays = 28;
        }
    }

    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        maxDays = 30;
    }

    if (d == maxDays)
    {
        if (m == 12)
        {
            if (y == 9999)
            {
                y = 1000;
            }else{
                y++;
            }
            m = 1;
        }else{
            m++;
        }
        d = 1;
    } else{
        d++;
    }

    newDate[0] = d;
    newDate[1] = m;
    newDate[2] = y;

    return true;
}

// previousDate function takes 3 int arguments to get the next date and stores the new date in an int array
// created at the top of this file. This function can be reused by both -- operators
// This uses a int array to store the maximum number of days in a given month to make sure if the date provided
// is the first day of that month then the new day value is the last day of that month (also checks for leap year
// and sets february maxDays to 29)
int previousDate(int d, int m, int y)
{
    int maxDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (checkForLeapYear(y))
    {
        maxDays[1] = 29;
    }

    if (d == 1)
    {
        if (m == 1)
        {
            if (y == 1000)
            {
                y = 1000;
            }else{
                y--;
            }
            m = 12;
        }else{
            m--;
        }
        d = maxDays[m - 1];
    }else{
        d--;
    }

    newDate[0] = d;
    newDate[1] = m;
    newDate[2] = y;

    return true;
}

// Prefix version of the ++ operator, return the new date
// Uses nextDate function as it is reusable and newDate int array to get the new date
Date &Date::operator++()
{
    nextDate(d , m , y );

    d = newDate[0];
    m = newDate[1];
    y = newDate[2];

    return *this;
}

// Postfix version of the ++ operator, returns the old date
// Uses nextDate function as it is reusable and newDate int array to get the new date
Date Date::operator++(int)
{
    Date postfix = *this;

    nextDate(d , m , y );

    d = newDate[0];
    m = newDate[1];
    y = newDate[2];

    return postfix;
}

// Prefix version of the -- operator, return the new date
// Uses previousDate function as it is reusable and newDate int array to get the new date
Date &Date::operator--()
{
    previousDate(d , m , y );

    d = newDate[0];
    m = newDate[1];
    y = newDate[2];

    return *this;
}

// Prefix version of the -- operator, return the old date
// Uses previousDate function as it is reusable and newDate int array to get the new date
Date Date::operator--(int)
{
    Date postfix = *this;

    previousDate(d , m , y );

    d = newDate[0];
    m = newDate[1];
    y = newDate[2];

    return postfix;
}

// First compares the year and month values to check if they are the same which will leave the result of this
// function up to what the day values are. If the year values are the same but month values are not then return
// appropriate bool (doesnt even bother comparing day values)
// If year values are not the same then month and day values dont need to be compared and returns result based on year values alone
bool Date::operator<(const Date& other) const
{
    if (y == other.y)
    {
        if (m == other.m)
        {
            if (d < other.d)
            {
                return true;
            }else{
                    return false;
            }
        }

        if (m < other.m)
        {
            return true;
        }else{
            return false;
        }
    }else {
        if (y < other.y)
        {
            return true;
        }else{
            return false;
        }
    }
}

// Checks if each value is the same starting from the back as there is no point checking the rest
// If the year pr month values aren't the same.
// Return appropriate bool value.
bool Date::operator==(const Date& other) const
{
    if (y == other.y)
    {
        if (m == other.m)
        {
            if (d == other.d)
            {
                return true;
            }
        }
    }

    return false;
}

// Uses a string array to store the name of each month
// Uses a string array to store the letter that follow the day value
// Compares day values and sets appropriate following letters
// uses to_string to save the day and year values as a string
// Stores all in one string which is then returned
Date::operator string() const
{
    string months[12] = {"January", "February", "March", "April", "May", "June", "July",
     "August", "September", "October", "November", "December"};

    string ending[4] = {"st", "nd", "rd", "th"};

    int i = 3;

    string day = to_string(d);
    string year = to_string(y);

    if (d == 1 || d == 21 || d == 31)
    {
        i = 0;
    }

    if (d == 2 || d == 22)
    {
        i = 1;
    }

    if (d == 3 || d == 23)
    {
        i = 2;
    }

    string result = day + ending[i]+ " " + months[m-1] + " " + year;

    return result;
}

// Uses 2 strings which are initially empty to add the leading 0 when day and month values are less than 10
// These strings are set to store "0" if the day or month values are less than 10
ostream &operator<<(ostream& o, const Date& dmy)
{
    string day0;
    string month0;

    if (dmy.d < 10)
    {
        day0 = "0";
    }

    else if (dmy.m < 10)
    {
        month0 = "0";
    }

    cout << day0 << dmy.d << "/" << month0 << dmy.m << "/" << dmy.y << endl;

    return o;
}

// Checks if the 2 dates are equal and returns true, if not then it checks if d1 is before d2 and
// returns true if d1 is before, false otherwise
bool operator <=(const Date& d1, const Date& d2)
{
    if (d1 == d2)
    {
        return true;
    }

    if (d1 < d2)
    {
        return true;
    }

    return false;
}

// Checks if the 2 dates are equal and returns true, if not then it checks if d1 is after d2 and
// returns true if d1 is after, false otherwise
bool operator >=(const Date& d1, const Date& d2)
{
    if (d1 == d2)
    {
        return true;
    }

    if (d1 > d2)
    {
        return true;
    }

    return false;
}

// Checks if the 2 dates are equal or if d1 is before d2 and return false when they are true, true otherwise
// As this leave only the possibility of d1 being after d2
bool operator >(const Date& d1, const Date& d2)
{
    if (d1 == d2)
    {
        return false;
    }

    if (d1 < d2)
    {
        return false;
    }

    return true;
}

// Checks if dates are equal to each other, return false if they are and true otherwise
bool operator !=(const Date& d1, const Date& d2)
{
    if (d1 == d2)
    {
        return false;
    }

    return true;
}