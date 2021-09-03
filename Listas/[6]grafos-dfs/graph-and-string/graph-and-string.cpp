// https://codeforces.com/problemset/problem/623/A

// #include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
#include <string>

#include <iostream>
#define BLANK '0'

using namespace std;
class node{
	public:
		bool check;
		char letter;
		unordered_set<int> not_adj;

		node(unordered_set<int> us){
			not_adj = us;
			check = false;
			letter = BLANK;
		}
};

string s;
vector<node> nodes;

bool tem_resp(int n, int id, bool switch_a_c){
	// se ficar encurralado, verifica os nos adjacentes e ve se e possivel
	//cout << "id: " << id << endl;
	
	unordered_set<int> not_adj = nodes[id].not_adj;
	char aux_letter = 0;

	if(not_adj.size() == 0) 	aux_letter = 'b';
	else if(switch_a_c) 		aux_letter = 'a';
	else						aux_letter = 'c';

	nodes[id].letter = aux_letter;
	s[id] = aux_letter;
	nodes[id].check = true;

	bool encurralado = true;
	for(int id_not_adj : not_adj) // olha os nao adjacentes
	{
		if(!nodes[id_not_adj].check) encurralado = false;
	}

	if(encurralado && aux_letter != 'b')
	{
		for(int id_not_adj : not_adj) // olha os nao adjacentes
		{
			if(nodes[id_not_adj].letter == aux_letter) // se o meu e 'a', o outro tem que ser 'c' e vice-versa
			{
				return false;
			}
		}
	}
	if(aux_letter != 'b') switch_a_c = !switch_a_c;

	if(id == n - 1) 	return true;
	return tem_resp(n, id + 1, switch_a_c);
}

int main()
{
	int n, m;
	//vector<node> nodes;
	unordered_set<int> aux_s;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		aux_s.insert(i);
	}
	
	for (int i = 0; i < n; i++)
	{
		node aux(aux_s);
		aux.not_adj.erase(i);
		nodes.push_back(aux);
		s.push_back(BLANK);
	}
	
	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		n1--;
		n2--;
		//cout << "n1: " << n1 << ", n2: " << n2 << endl;
		nodes[n1].not_adj.erase(n2); // tira os que tem conexao
		nodes[n2].not_adj.erase(n1);
	}

	if(tem_resp(n, 0, true)){
		cout << "Yes" << endl;
		cout << s << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}
