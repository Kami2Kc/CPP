#ifndef _FILTER3_H
#define _FILTER3_H

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "ReadFilteredWords.h"

class filter3: public ReadFilteredWords
{   public:

        virtual bool filter(string word);
};

#endif