#ifndef _FILTER2_H
#define _FILTER2_H

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "ReadFilteredWords.h"

class filter2: public ReadFilteredWords
{   public:

        virtual bool filter(string word);
};

#endif