using namespace std;

#include "ReadWords.h"
#include "ReadWordsBar.h"
#include <iostream>

int main() 
{
    // strings to store the names of all the files including the output file
    string textFile;
    string wordFile;
    string outputFile;

    ReadWordsBar bar;

    // Asks the user to enter values for the files
    cout << "\nPlease enter the name of the file that will be analyzed (with the .txt at the end)\n";
    cin >> textFile;
    cout << "\nNow please enter the name of the file that contains the words that are to be searched for (with the .txt at the end)\n";
    cin >> wordFile;
    cout << "\nFinally please enter the name of the output file to be created after the program is done (with the .txt at the end)\n";
    cin >> outputFile;

    // Get the words that are to be searched for
    bar.GetWordsForBar(wordFile);

    // Changes the string that contains the text file name into appropriate type so the method
    // can understand it
    const char *c = textFile.c_str();
    ReadWords ReadWords(c);

    // Check if there is a word in the file
    bool wordLookAhead = ReadWords.isNextWord();


    // While there are words still in the file keep looping and compare the word to the list of words
    // that are being searched for
    while (wordLookAhead)
    {
        string currentWord;
        wordLookAhead = ReadWords.isNextWord();
        currentWord = ReadWords.getNextWord();
        bar.CountWords(currentWord);
    }

    // outputs the results and creates the output file
    bar.DrawBar(outputFile);

    // closes the text file
    ReadWords.close();
}

