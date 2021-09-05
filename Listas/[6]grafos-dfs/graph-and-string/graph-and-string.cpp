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
		unordered_set<int> not_adj, adj;

		node(unordered_set<int> us){
			adj = {};
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
	unordered_set<int> adj = nodes[id].adj;
	char aux_letter = 0;

	if(!nodes[id].check)
	{

		if(not_adj.size() == 0) 	aux_letter = 'b';
		else if(switch_a_c) 		aux_letter = 'a';
		else						aux_letter = 'c';

		//cout << "auxletter " << aux_letter << endl;

		nodes[id].letter = aux_letter;
		s[id] = aux_letter;
		nodes[id].check = true;

		//cout << "string ate agora: " << s << endl;
	}else
	{
		//cout << "ja tinha sido checkado" << endl;
		aux_letter = nodes[id].letter;
		switch_a_c = (aux_letter == 'a'); // cuidado quando for B
	}

	bool encurralado = true;
	for(int id_not_adj : not_adj) // olha os nao adjacentes
	{
		//cout << "node " << id_not_adj << " checked: " << nodes[id_not_adj].check << endl;
		if(!nodes[id_not_adj].check)
		{
			//cout << "not checked" << endl;
			encurralado = false;
			bool possivel = tem_resp(n, id_not_adj, !switch_a_c);
			if(!possivel) return false;
		}
		else if(nodes[id_not_adj].letter == aux_letter) 
		{
			//cout << "deu pau" << endl;
			return false; 		
		}
	}

	//cout << "encurralado? " << encurralado << endl;
	if(encurralado && aux_letter != 'b')
	{
		for(int id_not_adj : not_adj) // olha os nao adjacentes
		{
			if(nodes[id_not_adj].letter == aux_letter) // se o meu e 'a', o outro tem que ser 'c' e vice-versa
			{
				//cout << nodes[id_not_adj].letter << " " << aux_letter << endl;
				//cout << "N TEM RESP" << endl;
				return false;
			}
		}

		for(int id_adj : adj) // olha os adjacentes
		{
			char letter = nodes[id_adj].letter;
			if(letter != aux_letter && letter != 'b' && letter != BLANK)
			{
				//cout << "return false " << "nodes[idajd].letter " << nodes[id_adj].letter << endl;
				return false;
			}
		}
	}
	////cout << "switch antes " << switch_a_c << endl;
	// if(aux_letter != 'b') switch_a_c = !switch_a_c;
	// //cout << "switch depois " << switch_a_c << endl;

	//cout << "id == n-1? " << (id == n-1) << endl;
	if(id == n - 1) 	return true;
	//cout << "ULTIMO RETURN" << endl;
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
		//aux.adj.erase(i);

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

		nodes[n1].adj.insert(n2);
		nodes[n2].adj.insert(n1);
	}

	if(tem_resp(n, 0, true)){
		cout << "Yes" << endl;
		cout << s << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}
