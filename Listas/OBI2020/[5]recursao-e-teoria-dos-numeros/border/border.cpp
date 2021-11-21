//https://codeforces.com/contest/1011/problem/E
//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1000000000
int our_gcd(int num1, int num2){
	
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

int main(){
	int n, k;
	vector<int> a;
	
	
	cin >> n >> k;
	
	int orig_n = n;
	for(int i = 0; i < orig_n; i++){
		int aux;
		cin >> aux;
		
		aux = aux % k;
		
		if(aux != 0) 
			a.push_back(aux);
		else
			n--;
	}
	
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