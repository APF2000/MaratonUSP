#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int testarQualidade(int temps[], int tam);

void subVetor(int *vetor, int ini, int fim, int *aux);

int main(){

  int numDias, numParreiras;

  cin >> numDias;
  cin >> numParreiras;

  int temperaturas[numDias];

  for(int i = 0; i < numDias; i++){
    cin >> temperaturas[i];
  }

  for(int i = 0; i < numParreiras; i++){

    int ini, fim;

    cin >> ini;
    ini -= 1;

    cin >> fim;
    fim -= 1;


    int tam = fim - ini + 1;
    int sub[tam];
    subVetor(temperaturas, ini, fim, sub);

    for(int i = 0; i < tam; i++){

      cout << sub[i];
    }

    testarQualidade(sub, tam);
    //cout << testarQualidade(sub) << endl;
  }

  return 0;
}

void subVetor(int *vetor, int ini, int fim, int *aux){

  for(int i = 0; i < (fim - ini + 1); i++){

    aux[i] = vetor[i + ini];
  }
}

int testarQualidade(int *temps, int tam){

        int qualidade = 0;

        for(int i = 0; i < tam; i++){
          //cout << temps[i] << endl;
        }


        sort(temps, temps + tam);
        int lim = sqrt(tam);

        cout << "sqrt " << lim << endl;


        for(int i = 0; i < tam; i++){
          //cout << temps[i] << endl;
        }

        return qualidade;
}
