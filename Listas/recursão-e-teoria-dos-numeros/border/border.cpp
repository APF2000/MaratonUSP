#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000000
int our_gcd(int num1, int num2){
	/*if(num2 == 0){
		return -1;
	}*/
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
	//cout << "Prim mdc " << mmdc << endl;
	//mmdc = mmdc == 0 ? 1 : mmdc;
	for(int i = 1; i < size; i++){
		/*if(mmdc == 0) 
			mmdc= 1;*/
		////cout << "MMDC: " << mmdc << endl;
		mmdc = __gcd(numeros[i], mmdc);
		//cout << "Novo mdc " << mmdc << ", por causa do " << numeros[i] << endl;

		//if(aux != -1)
		//	mmdc = aux;
		//else
		//	cout << "pinto " << endl;
	}
	return mmdc;
}

int main(){
	int n, k;
	vector<int> a;
	//map<int, vector<int>> fatorado;
	//int mem[MAX] = {2};
	cin >> n >> k;
	//cout << "n " << n << endl;
	int orig_n = n;
	for(int i = 0; i < orig_n; i++){
		int aux;
		cin >> aux;
		//cout << "aux: " << aux << endl;
		aux = aux % k;
		//cout << "aux: " << aux << endl;

		if(aux != 0) 
			a.push_back(aux);
		else
			n--;
	}
	//cout << "alo" << endl;
	int mmdc = mdc(a);
	//cout <<  "mdc " << mmdc << endl;
	for (int i = 0; i < n; i++)
	{
		//cout << "printando i: " << i << " n: " << n << " a[i] " << a[i] << endl;

		a[i] /= mmdc;
	}
	//cout << "l 29 " << mmdc << endl;
	sort(a.begin(), a.end());

	int maior_elemento = 1; 

	bool primos_entre_si = false;
	for (int i = n-1; i > 0 && !primos_entre_si; i--)
	{
		for (int j = i-1; j >= 0; j += -1)
		{
			if(__gcd(a[j], a[i]) == 1){
		
				primos_entre_si = true;
				maior_elemento = a[i];
				//cout << "l 39 " << maior_elemento << endl;

				break;
			}
		}
	}

	if(n != 0 && maior_elemento * mmdc < k) maior_elemento = k / mmdc;
	//else maior_elemento++;

	cout << maior_elemento << endl;
	for (int i = 0; i < maior_elemento; i++)
	{
		cout << mmdc * i << " ";

	}
	cout << endl;
	return 0;
}