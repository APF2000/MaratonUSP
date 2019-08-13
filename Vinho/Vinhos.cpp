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

    cout << testarQualidade(sub, tam) << endl;
  }

  return 0;
}

void subVetor(int *vetor, int ini, int fim, int *aux){

  for(int i = 0; i < (fim - ini + 1); i++){

    aux[i] = vetor[i + ini];
  }
}

int testarQualidade(int *temps, int tam){

        cout << "testandoqualidade" << endl;

        sort(temps, temps + tam);

        int lim = sqrt(tam);
        int qualidade = lim;


        for(int i = lim; i > 1; i--, qualidade--){

          int nUplasDiferentes = 0, numIguais = 1;
          int ultimoNum = temps[0];
          for(int j = 0; j < tam; j++){

            if(temps[j + 1] == ultimoNum)
              numIguais++;

            else{
              if(numIguais == qualidade)
                nUplasDiferentes++;

              numIguais = 1;
            }
          }

          if(nUplasDiferentes <= qualidade)
            return qualidade;
        }

        return qualidade;
}
