#ifndef PRINTER_H
#define PRINTER_H

#include <vector>
#include "word.h"

using namespace std;

class Printer
{
    public:
        void print_vector(vector<Word*> spots);
        void print_map(vector<vector<char>> map, int m, int n);
        void showstack(stack <Word*> s);
        void print_vector_strings(vector<string> wordlist);
};

#endif