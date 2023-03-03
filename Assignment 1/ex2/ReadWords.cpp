using namespace std;

#include "ReadWords.h"
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>

// Removes any punctuation at the start and end of the word and
// returns the new string without the punctuation (punctuation inside the word is left)
string removePunct(string word)
{ 

    int length = word.size();

    while (ispunct(word[0]))
    {
        word.erase(0);
        length = word.size();
    }

    while (ispunct(word[length - 1]))
    {
        word.erase(length - 1);
        length = word.size();
    }

    return word;
}

// Opens the text file and gets the first word from it
// If it fails to open the file then it outputs a error message to the terminal and terminates
ReadWords::ReadWords(const char *fname)
{   
    wordfile.open(fname);

    if (!wordfile)
    {   cout << "Failed to open " << fname << endl;
        exit(1);
    }

    wordfile >> nextword;
    eoffound = false;

}

// Gets the next word from the file, turns it into all lower case and returns
// If no new words are available sets eoffbound to true which will let the program know it reached
// the end of the file. If a word is found then run removePunct
// next it will check if the word contains any letters if not then it will return an
// empty string instead
string ReadWords::getNextWord()
{
    string word = nextword;
    wordfile >> nextword;

    if (wordfile.eof())
    {
        eoffound = true;
    }

    word = removePunct(word);
    int counter = 0;

    for (char i : word)
    {
        if (isalpha(i) != 0)
        {
            counter ++;
        }
    }

    if (counter == 0)
    {
        word = "";
    }

    transform(word.begin(),word.end(),word.begin(), ::tolower );

    return word;
}

// lets the program know if any more words are available from the text file
bool ReadWords::isNextWord()
{
    return !eoffound;
}

// Closes the text file
void ReadWords::close()
{ 
    wordfile.close();
}
