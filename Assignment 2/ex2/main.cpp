using namespace std;

#include <iostream>
#include <string>
#include "ReadWords.h"
#include "ReadFilteredWords.h"

int main()
{
    string wordsFileName;
    string option;

    cout << "\nPlease enter the name of the file containing words to be anaylzed (with .txt extension at the end)\n";
    cin >> wordsFileName;
    cout << "\nPlease select which derived class should be used (enter 1,2, or 3 as your answer)\n1. Class 1\n2. Class 2\n3. Class 3\n";
    cin >> option;

    while (option != "1" && option != "2" && option != "3")
    {
        cout << "\nInvalid input !\n\nPlease select which derived class should be used (enter 1,2, or 3 as your answer)\n1. Class 1\n2. Class 2\n3. Class 3\n";
        cin >> option;
    }





}