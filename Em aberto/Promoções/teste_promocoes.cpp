#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Nos {

	public:
  		int qtde;
  		int valor;
  		vector<int> calculados;
  
  		Nos(int qtde, int valor)
        {
        	this->qtde = qtde;
          	this->valor = valor;
        }
};

bool sort_by_qtde(Nos* no1, Nos* no2)
{
	if(no1->qtde != no2->qtde) return (no1->qtde > no2->qtde);
  	return (no1->valor / no1->qtde > no2->valor / no2->qtde);
}

void print_vector(vector<Nos*> promos){

	for(vector<Nos*>::const_iterator i = promos.begin(); i != promos.end(); i++)
    {
		cout << (*i)->qtde << "   " << (*i)->valor << "\n";
	}
	cout << '\n';

}

int max_lucro(vector<Nos*>* promos, int index, int lat_falt, int lucro)
{
	Nos* promo = promos->at(index);
	int	qtde = promo->qtde;
	int valor = promo->valor;

	if(lat_falt == 0) return lucro;
	
	// Algo para calcular o lucro

	if(index == promos->size() - 1) return -2;

	return 0;
}

int main()
{
	int n_promos, m_latas;

	while(cin >> n_promos >> m_latas){

		vector<Nos*> promos(n_promos);
      	int qtde, valor;

		for(int i = 0; i < n_promos; i++)
        {
          	cin >> qtde >> valor;
			promos.at(i) = new Nos(qtde, valor);

			for(int j = 0; j < m_latas; j++)
			{
				promos.at(i)->calculados.push_back(-1);
			}

			for(int j = 0; j < m_latas; j++)
			{
				cout << "(" << j << ","; 
				cout << promos.at(i)->calculados.at(j) << ");";
			}
			cout << "\n";
		}
      
		
		sort(promos.begin(), promos.end(), sort_by_qtde);
		print_vector(promos);

		int lucro = max_lucro(&promos, 7, m_latas, 0);
		cout << "lucro: " << lucro << "\n";
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