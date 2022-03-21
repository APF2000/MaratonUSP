#include <bits/stdc++.h>

using namespace std;

int main()
{
	long B, L, numero = 0, multiplo;
	vector<long> D, alterado;
	cin >> B >> L;
	for(long i = 0; i < L; i++){
		long algarismo;
		cin >> algarismo;
		D.push_back(algarismo);
		numero += D[i]*pow(B, i);
	}
	if(numero % (B+1) == 0){
			cout << "0 0" << endl;
			return 0;
		}
	alterado = D;
	multiplo = numero;
	while(multiplo != 0){
		for(long i = 0; i < 5; i++){
			alterado[i] -= 1;
		}
	}

	return 0;
}
