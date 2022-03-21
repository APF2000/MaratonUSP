#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Word
{
    public:
        int x_ini, y_ini, x_fim, y_fim;
        string w;

        Word(int x_ini, int y_ini, int x_fim, int y_fim, string w); 
        ~Word();       
};

#endif