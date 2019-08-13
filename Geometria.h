#ifndef GEOMETRIA_H
#define GEOMETRIA_H
#include <iostream>

using namespace std;

class Ponto{

  private:
    int x, y;

  public:

    Ponto();

    Ponto(int x, int y);

    int coordX();

    int coordY();
};

class SegmentoRetaVetor{

  private:
    Ponto ini, fim;
    double m;

  public:
    SegmentoRetaVetor();

    SegmentoRetaVetor(Ponto ini, Ponto fim);

    Ponto inicial();

    Ponto final();

    int* intercepta(SegmentoRetaVetor seg1, SegmentoRetaVetor seg2);
};


#endif
