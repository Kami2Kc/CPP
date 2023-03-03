using namespace std;

#include "Date.h"
#include <iostream>

int main()
{
    Date date = Date(9 , 1 , 2000);

    Date date2 = Date(17 , 2 ,2000);

    cout << string(date) << endl;

    cout << string(date2) << endl;

    cout << date << endl;

    cout << date2 << endl;

    //cout << ++date << endl;

    //cout << --date2 << endl;

    cout << (date<=date2) << endl;
}
