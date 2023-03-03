using namespace std;

#include "filter1.h"
#include <string>
#include <iostream>
#include <fstream>
#include "ReadFilteredWords.h"

bool filter1::filter(string word)
{
    bool foundCapital = false;
    bool foundLowerCase = false;

    for (char c : word)
    {
        if (isalpha(c))
        {
            if (isupper(c))
            {
                foundCapital = true;
            }

            if (islower(c))
            {
                foundLowerCase = true;
            }
        }
    }

    if (foundCapital)
    {
        return false;
    }else{
        return foundLowerCase;
    }
}