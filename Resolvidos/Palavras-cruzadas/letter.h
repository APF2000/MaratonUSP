#ifndef LETTER_H
#define LETTER_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Letter
{
    public:
        int x, y;
        char ch;
        bool inter;

        Letter(int x, int y, char ch, bool inter);     
};

#endif