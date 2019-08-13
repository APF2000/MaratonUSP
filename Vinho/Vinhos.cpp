#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int testarQualidade(int temps[]);

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

  }

  return 0;
}


    int testarQualidade(int *temps){

      int tam = sizeof(*temps) / sizeof(temps[0]);
      int qualidade = 0;


      sort(temps, temps + tam);
      int lim = sqrt(tam);


      for(int i = 0; i < tam; i++){
        cout << temps[i] << endl;
      }

      return qualidade;
    }
