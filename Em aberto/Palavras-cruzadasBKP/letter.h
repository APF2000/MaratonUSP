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
        char c;
        bool inter;

        Letter(int x, int y, char c, bool inter);     
};

#endif