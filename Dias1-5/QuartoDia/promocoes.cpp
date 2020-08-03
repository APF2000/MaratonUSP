#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct{

	int qtde;
	int valor;

}promo; 

void print_vector(vector<promo> promos){

	for(vector<promo>::const_iterator i = promos.begin(); i != promos.end(); i++){

		cout << (*i).qtde << "   " << (*i).valor << "\n";
	
	}
	cout << '\n';

}

void print_vector2(vector<int> vec){

        for(vector<int>::const_iterator i = vec.begin(); i != vec.end(); i++){

                cout << (*i) << " ";

        }
        cout << '\n';

}


bool sort_by_qtde(promo p1, promo p2){

	if(p1.qtde != p2.qtde) return (p1.qtde > p2.qtde);
	return (p1.valor > p2.valor);

	// return (p1.valor / p1.qtde > p2.valor / p2.qtde);

}


void permuta_sum(vector<int> qtdes, int m_latas, int n_promos){

	vector<vector<int>> permutacoes = {{0}};
	int relative_pos = 0;

	for(vector<int>::const_iterator qtde_promo = qtdes.begin(); qtde_promo != qtdes.end(); qtde_promo++){
		
		vector<vector<int>> aux_permutacoes;

                cout << (*qtde_promo) << ":  ";
		
		for(int qtde_vend = 0; qtde_vend <= m_latas / (*qtde_promo); qtde_vend++){
			cout << qtde_vend << "{";

			vector<vector<int>> aux_permutacoes;
                	for(vector<vector<int>>::const_iterator permutacao = permutacoes.begin(); permutacao < permutacoes.end(); permutacao++){
				
				cout << "\n[bcicsicus";
				print_vector2((*permutacao));
				cout << "\n";

				int sum = m_latas;
				sum -= (*qtde_promo) * qtde_vend;
			
				for(int j = 1; j <= relative_pos; j++){
				
					//sum -= qtdes.at(j) * (*permutacao).at(j);
					cout << sum << ", ";			

				}
				cout << " sum= " << sum;

				if(sum < 0){
					break;
				}

				vector<int> aux = (*permutacao);
				aux.push_back(qtde_vend);
				aux_permutacoes.push_back((*permutacao));

				cout << "], ";

                	}
			cout << "} ";

		}

		cout << '\n';

		relative_pos++;
        }
        cout << '\n';

}


int main(){

	int n_promos, m_latas;
	//promo aux;
	//vector<promo> promos;
	//vector<int> qtdes;

	while(cin >> n_promos >> m_latas){

	        promo aux;
        	vector<promo> promos;
        	vector<int> qtdes;


		for(int i = 0; i < n_promos; i++){
			
			cin >> aux.qtde >> aux.valor;
			
			qtdes.push_back(aux.qtde);
			promos.push_back(aux);	
		}

		//sort(qtdes.begin(), promos.end(), std::greater<int>);
		/*vector<vector<int>> permutacoes =*/ 
		
		//permuta_sum(qtdes, m_latas, n_promos);
		
		sort(promos.begin(), promos.end(), sort_by_qtde);
		print_vector(promos);

	}

	return 0;
}

/* Caso de teste

8 70
4 9
5 1
5 18
2 3
3 11
3 9
3 3
3 6

3 67
4 9
3 10
3 8


9 69
3 8
2 10
3 18
2 4
1 11
4 9
2 2
3 3
1 17

4 9
1 2
3 4
5 6
7 8

10 34
5 11
3 6
3 11
1 10
2 14
4 19
3 8
5 2
5 16
4 5
*/
