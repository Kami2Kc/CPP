using namespace std;

#include "ReadFilteredWords.h"
#include <iostream>
#include <string>

bool ReadFilteredWords::filter(string word)
{

}

string ReadFilteredWords::getNextFilteredWord()
{
    string nextWord = getNextWord();

    if (filter(nextWord))
    {
        return nextWord;
    }else{
        return "";
    }
}

