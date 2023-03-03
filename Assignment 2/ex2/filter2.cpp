using namespace std;

#include "filter2.h"
#include <string>
#include <iostream>
#include <fstream>
#include "ReadFilteredWords.h"

bool filter2::filter(string word)
{
    int numberOfLetters = 0;

    bool foundNumber = false;

    for (char c : word)
    {
        if (isalpha(c))
        {
            numberOfLetters++;
        }

        if (isdigit(c))
        {
            foundNumber = true;
        }
    }

    return foundNumber && numberOfLetters >= 2;
}