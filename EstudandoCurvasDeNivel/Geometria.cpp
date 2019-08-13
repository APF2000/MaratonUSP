#include <iostream>
using namespace std;

#include "Geometria.h"

Ponto::Ponto(){

}

Ponto::Ponto(int x, int y){

    this->x = x;
    this->y = y;
}

int Ponto::coordX(){

    return x;
}

int Ponto::coordY(){

    return y;
}

////////////////////////////////////

SegmentoRetaVetor::SegmentoRetaVetor(){

}

SegmentoRetaVetor::SegmentoRetaVetor(Ponto ini, Ponto fim){

  this->ini = ini;
  this->fim = fim;
}

Ponto SegmentoRetaVetor::inicial(){

  return ini;
}

Ponto SegmentoRetaVetor::final(){

  return fim;
}

int* SegmentoRetaVetor::intercepta(SegmentoRetaVetor seg1, SegmentoRetaVetor seg2){

  Ponto aIni, aFim, bIni, bFim;
  int aDeltaX, aDeltaY, bDeltaX, bDeltaY;

  aIni = seg1.inicial();
  aFim = seg1.final();
  bIni = seg2.inicial();
  bFim = seg2.final();

  aDeltaX = aFim.coordX() - aIni.coordX();
  aDeltaY = aFim.coordY() - aIni.coordY();
  bDeltaX = bFim.coordX() - bIni.coordX();
  bDeltaY = bFim.coordY() - bIni.coordY();

  int m1, m2;

  if(aDeltaX){

  }

  m1 = (aDeltaY) / (aDeltaX);
  m2 = (bDeltaY) / (bDeltaX);

  // Paralelas
  if(m1 == m2)
    return NULL;

  return NULL;
}
