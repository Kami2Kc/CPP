using namespace std;

#include "ReadWordsBar.h"
#include <iostream>

// Outputs the results into the terminal and creates a new .txt file with the same result
// Uses 2 arrays to store the words that are being searched for as well as the number of
// occurrences for each word
void ReadWordsBar::DrawBar(const string& outputFile)
{   

    for (int i = 0; i < 12; i++)
    {
        if (!(wordsToSearchFor[i].empty()))
        {
            cout << wordsToSearchFor[i];
            int spaces = 10;
            spaces -= wordsToSearchFor[i].size();

            for (int i = 0; i < spaces; i++)
            {
                cout << " ";
            }

            for (int j = 0; j < numOfOccurrences[i]; j++)
            {
                cout << "*";
            }
    
            cout << "  " << numOfOccurrences[i] << endl;
        }
    }

    ofstream outfile (outputFile);

    for (int i = 0; i < 12; i++)
    {
        if (!(wordsToSearchFor[i].empty()))
        {
            outfile << wordsToSearchFor[i];
            int spaces = 10;
            spaces -=  wordsToSearchFor[i].size();

            for (int i = 0; i < spaces; i++)
            {
                outfile << " ";
            }

            for (int j = 0; j < numOfOccurrences[i]; j++)
            {
                outfile << "*";
            }
    
            outfile << "  " << numOfOccurrences[i] << endl;
        }
    }

    outfile.close();
}

// Opens the word file and stores the words (Maximum of 12 as specified in the assignment)
// that are having their occurrences counted in an array
// If the file fails to open display a message and end the program
int ReadWordsBar::GetWordsForBar(const string& wordlist)
{   

    wordFile.open(wordlist);
    if (!wordFile)
    {
        cout << "Failed to open " << wordlist << endl;
        exit(1);
    }

    for (auto & i : wordsToSearchFor)
    {
        wordFile >> i;
    }

    wordFile.close();
}

// Compares the current word from the text file with the words in the
// words file which are now stored in an array and add 1 to the occurrences when they match
// occurrences are stored in a separate array
void ReadWordsBar::CountWords(const string& word)
{
    for (int i = 0; i < 12; i++)
    {
        if (word == wordsToSearchFor[i])
        {
            numOfOccurrences[i] += 1;
        }
    }
}