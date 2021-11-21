// https://codeforces.com/problemset/problem/230/B
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef unsigned long long int ull;
using namespace std;

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

int main(){
	int n;
	vector<ull> nums;
	unordered_set<ull> primos_ao_quadrado;
	ull raiz_maior_el;
	cin >> n;
	// Obtendo maior valor
	ull maior_el = 0;
	for(int i = 0; i < n; i++){
		ull aux;
		cin >> aux;
		if(aux > maior_el){
			maior_el = aux;
		}
		nums.push_back(aux);
	}
	
	for(raiz_maior_el = 0; raiz_maior_el*raiz_maior_el < maior_el; raiz_maior_el++){

	}
	crivo(raiz_maior_el);
	primos_ao_quadrado.insert(4);
	ull i;
	for( i = 1; i < raiz_maior_el+2 ; i = i + 2){
		if(eh_primo[i] == 1){
			primos_ao_quadrado.insert((i)*(i));
		}
		
	}
	for(int i = 0; i < n; i++){
		ull aux;
		aux = nums[i];
		if(primos_ao_quadrado.find(aux) != primos_ao_quadrado.end()){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}