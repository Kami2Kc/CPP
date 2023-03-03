using namespace std;

#include "filter3.h"
#include <string>
#include <iostream>
#include <fstream>
#include "ReadFilteredWords.h"

bool filter3::filter(string word)
{
    bool foundChar = false;
    bool foundPunct = false;

    for (char c : word)
    {
        if (isalpha(c))
        {
            foundChar = true;
        }

        if (ispunct(c))
        {
            foundPunct = true;
        }
    }

    return foundChar && foundPunct;
}