//hhttps://codeforces.com/contest/1295/problem/D
//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
#define MAX 1000000000

const ull maxn = 1000000;

int eh_primo[maxn]; // -1 => indefinido, 0 => composto e 1 => primo.
                    // Lembre-se de inicializar "eh_primo" com -1, ou na main ou
                    // na própria função crivo, no seu começo.

void crivo(ull n){
    // Inicializando "eh_primo" com -1, pois não sabemos nada sobre nenhum número, inicialmente.
    for(ull i=1; i<=n; i++){
        eh_primo[i] = -1;
    }
    
    // Para cada número de 2 até n
    for(ull i = 2; i <= n; i++){
            
        // checo se o número atual é indefinido.
        if(eh_primo[i] == -1){
            
            // Se ele for, indico que ele é primo
            eh_primo[i] = 1;
    
            // e que os múltiplos dele são compostos.
            for(ull j = i + i; j <= n; j += i){
                eh_primo[j] = 0;
            }
        }
    }
}

ull our_gcd(ull num1, ull num2){
	
	if(num1%num2 == 0)
        return num2;
    else
        return our_gcd(num2, num1%num2);
}
int mdc(vector<int> numeros){
	int size = numeros.size();
	if(size == 0)
		return 1;
	int mmdc = numeros[0]; //gv >:(

	for(int i = 1; i < size; i++){
		mmdc = our_gcd(numeros[i], mmdc);
	}
	return mmdc;
}

vector<ull> decompor(vector<ull> primos, ull num){
	vector<ull> fatores_primos;
	int i = 0;
	while(primos[i] <= num){
		if(num%primos[i] == 0){
			fatores_primos.push_back(primos[i]);
		}
	}
	return fatores_primos;
}
ull solve(ull a, ull m, vector<ull> primos){
	ull resp = 1;
	ull gcd_ac = our_gcd(a,m);
	ull m_div_gcd = m/gcd_ac;
	vector<ull> prims_mgcd;
	return resp;
}

int main(){
	int t;
	vector<ull> as;
	vector<ull> ms;
	vector<ull> primos;
	ull maior_m = 0;
	ull a, m, res;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> a;
		cin >> m;
		as.push_back(a);
		ms.push_back(m);
		if(maior_m < m){
			maior_m = m;
		}
	}

	crivo(maior_m);
	for(int i = 2; i < maior_m + 2; i++){
		if(eh_primo[i] == 1){
			primos.push_back(i);
		}
	}

	for(int i = 0; i < t; i++){
		a = as[i];
		m = ms[i];
		res = solve(a,m,primos);
		cout << res << endl;
	}
	return 0;

	int mmdc = mdc(a);
	
	for (int i = 0; i < n; i++)
	{
		a[i] /= mmdc;
	}
	mmdc = our_gcd(k, mmdc);
	sort(a.begin(), a.end());

	int maior_elemento = 1; 
	maior_elemento = k / mmdc;
	if( n==0 ) maior_elemento = 1;

	cout << maior_elemento << endl;
	for (int i = 0; i < maior_elemento; i++)
	{
		cout << mmdc * i << " ";
	}
	cout << endl;
	return 0;
}