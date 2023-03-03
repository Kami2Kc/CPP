#ifndef _FILTER1_H
#define _FILTER1_H

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "ReadFilteredWords.h"

class filter1: public ReadFilteredWords
{   public:

        virtual bool filter(string word);
};

#endif