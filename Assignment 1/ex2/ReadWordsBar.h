#ifndef READWORDSBAR_H
#define READWORDSBAR_H

using namespace std;

#include <string>
#include <fstream>

class ReadWordsBar
{
  public:
    // Store the words from the words file in an array
    int GetWordsForBar(const string& wordlist);

    // Output bar graph to terminal and to file
    void DrawBar(const string& outputFile);

    // Compare the current word with the ones stored in the array and increase occurrence by 1
    // for every matching word
    void CountWords(const string& word);

    // name of word file and the 2 arrays that store the words and their occurrences
  private:
    ifstream wordFile;
    string wordsToSearchFor[12];
    int numOfOccurrences[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
};

 #endif
