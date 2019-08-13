#include <iostream>
#include <vector>
#include "Geometria.h"
using namespace std;

int main(){

  int numPontos, numVetores;
  cin >> numPontos;
  cin >> numVetores;

  vector<Ponto> pontos(numPontos);

  for(int i = 0; i < numPontos; i++){

    int auxX, auxY;
    cin >> auxX;
    cin >> auxY;

    Ponto aux(auxX, auxY);
    pontos[i] = aux;

    /*cout << endl;
    cout << pontos[i].coordX() << " " << pontos[i].coordY() << endl;*/
  }

  for(int i = 0; i < numVetores; i++){


  }

  return 0;
}
