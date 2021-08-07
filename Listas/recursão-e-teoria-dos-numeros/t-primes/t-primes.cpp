// https://codeforces.com/problemset/problem/230/B
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
unsigned long long int prox_primo(unsigned long long int maior_primo, vector<unsigned long long int> primos){
	maior_primo = maior_primo + 2;
	bool isPrime = false;
	while(!isPrime){
		//cout << maior_primo << endl;
		unsigned long long int i;
		for( i = 0; primos[i]*primos[i] <= maior_primo; i++){
			if(maior_primo%primos[i] == 0){
				break;
			}
		}
		if(primos[i]*primos[i] > maior_primo){
			isPrime = true;
		} else {
			maior_primo = maior_primo + 2;
		}
	}
	return maior_primo;
}

vector<unsigned long long int> prims_ate_n( unsigned long long int maior_el){
	unsigned long long int maior_primo = 7;
	vector<unsigned long long int> primos;
	primos.push_back(2);
	primos.push_back(3);
	primos.push_back(5);
	primos.push_back(7);
	while(maior_el >= maior_primo*maior_primo){
			//cout << "Buscando proximo primo" << endl;
			maior_primo = prox_primo(maior_primo, primos);
			//cout << maior_primo << endl;
			primos.push_back(maior_primo);
	}
	return primos;
}

int main(){
	int n;
	vector<unsigned long long int> primos;
	vector<unsigned long long int> nums;
	unordered_set<unsigned long long int> primos_ao_quadrado;
	
	cin >> n;
	// Obtendo maior valor
	unsigned long long int maior_el = 0;
	for(int i = 0; i < n; i++){
		unsigned long long int aux;
		cin >> aux;
		if(aux > maior_el){
			maior_el = aux;
		}
		nums.push_back(aux);
	}
	//criando lista de primos
	primos = prims_ate_n(maior_el);
	
	//criando set de quadrados
	for(int i = 0; i < primos.size(); i++){
		primos_ao_quadrado.insert(primos[i]*primos[i]);
	}

	for(int i = 0; i < n; i++){
		unsigned long long int aux;
		aux = nums[i];
		if(primos_ao_quadrado.find(aux) != primos_ao_quadrado.end()){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}