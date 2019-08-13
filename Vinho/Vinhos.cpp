#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int testarQualidade(int temps[]);

int* subVetor(int *vetor, int ini, int fim);

int main(){

  int numDias, numParreiras;

  cin >> numDias;
  cin >> numParreiras;

  int temperaturas[numDias];

  for(int i = 0; i < numDias; i++){
    cin >> temperaturas[i];
    cout << temperaturas[i] << endl;
  }

  for(int i = 0; i < numParreiras; i++){

    int ini, fim;

    cin >> ini;
    ini -= 1;

    cin >> fim;
    fim -= 1;

    cout << ini << " " << fim << endl;

    int *sub = subVetor(temperaturas, ini, fim);
    for(int i = 0; i < (fim - ini + 1); i++){

      cout << sub[i];
    }

    cout << testarQualidade(sub) << endl;
  }

  return 0;
}

int* subVetor(int *vetor, int ini, int fim){

  int aux[fim - ini + 1];

  for(int i = 0; i < (fim - ini + 1); i++){

    aux[i] = vetor[i + ini];
    cout << aux[i] << endl;
  }


  return aux;
}

int testarQualidade(int *temps){

        int tam = sizeof(*temps) / sizeof(temps[0]);
        int qualidade = 0;

        for(int i = 0; i < tam; i++){
          cout << temps[i] << endl;
        }


        sort(temps, temps + tam);
        int lim = sqrt(tam);


        for(int i = 0; i < tam; i++){
          cout << temps[i] << endl;
        }

        return qualidade;
}
