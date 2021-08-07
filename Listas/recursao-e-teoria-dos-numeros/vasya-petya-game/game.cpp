//https://codeforces.com/contest/576/problem/A

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findPrimes(int n, vector<int> &primes){
	int primo = 2;
	int teste = 3;
	primes.push_back(primo);
	while(teste <= n){
		bool achou_primo = true;
		//cout << "teste " << teste << endl;
		for(int count_prim = 0; count_prim < primes.size(); count_prim++){
				if(teste % primes[count_prim] == 0){
					achou_primo = false;
					break;
				}
			}
		if(achou_primo){
			primo = teste;
			primes.push_back(primo);
		//cout << "primo " << primo << endl;
		}
		teste++;
	}
}

void fitDoublePrime(int n, vector<int>&lista){
	int potencia;
	for (int i = 0; i < lista.size(); i++)
	{
		potencia = lista[i]*lista[i];
		while(potencia <= n){
			if(find(lista.begin(), lista.end(), potencia) != lista.end()) {
				potencia *= lista[i];
			}
			else{
				lista.push_back(potencia);
				potencia *= lista[i];
			}
		}
	//	cout << lista[i] << endl;
	}
}
/*
void isDivisible(int n, vector <int> &lista){
	for (int i = 0; i < lista.size(); i++){
	int passo = 1;
	for(int j = i+1; j < lista.size(); passo){
	int div = lista[i];
	int aux = j;
	bool add = true;
		while(aux < lista.size() && div < n){
				div = div*lista[aux];
				if(n % div == 0){
					add = false;
			}
		aux++;
		}

		}
	}
}
*/
int main(){
	int n;
	vector<int> lista;
	cin >> n;
	findPrimes(n, lista);
	fitDoublePrime(n, lista);
	sort(lista.begin(), lista.end());
	if(n < 2){
		cout << "0" << endl;
		cout << endl;
	}
	else{
	cout << lista.size() << endl;
	for (int i = 0; i < lista.size(); i++)
	{
		cout << lista[i] << " ";
	}
	cout << endl;
	}
	return 0;
}