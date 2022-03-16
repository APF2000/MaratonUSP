#include "word.h"

Word::Word(int x_ini, int y_ini, int x_fim, int y_fim, string w)
{
    this->x_ini = x_ini;
    this->y_ini = y_ini;

    this->x_fim = x_fim;
    this->y_fim = y_fim;

    this->w = w;
}

Word::~Word()
{
    
}