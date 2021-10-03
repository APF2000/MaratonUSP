// https://codeforces.com/problemset/problem/623/A

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

	//cout << "size nadj: " << nodes[id].not_adj.size() << endl;
	//cout << "size adj: " << nodes[id].adj.size() << endl;
	char aux_letter = 0;

	return aux_letter;
}

bool tem_resp(int n, int id, bool is_a)
{
	if(id >= n) return true; // passou do ultimo

		if(nodes[id].not_adj.size() == 0) 	aux_letter = 'b';
		else if(switch_a_c) 		aux_letter = 'a';
		else						aux_letter = 'c';
		
		nodes[id].letter = aux_letter;
		s[id] = aux_letter;
		nodes[id].check = true;

		if(aux_letter == 'b')
		{
			for(node nd : nodes)
			{
				nd.adj.erase(id);
			}
		}

	}else
	{
		aux_letter = nodes[id].letter;
		switch_a_c = (aux_letter == 'a'); // cuidado quando for B
	}

//cout << "antes encurralado" << endl;
	bool encurralado = true;
	unordered_set<int> aux_not_adj = nodes[id].not_adj;
	for(int id_not_adj : aux_not_adj) // olha os nao adjacentes
	{
//cout << "antes if 1 idnotadj: " << id_not_adj << endl;
//cout << "size notasj " <<  nodes[id].not_adj.size() << endl;
		if(nodes[id_not_adj].letter == aux_letter) 
		{
			return false; 		
		}
		
//cout << "antes if 2" << endl;
		if(nodes[id_not_adj].check) // tira da lista um do outro
		{ 
			nodes[id_not_adj].not_adj.erase(id);
			nodes[id].not_adj.erase(id_not_adj);
		}
		else{
			encurralado = false;
			bool possivel = tem_resp(n, id_not_adj, !switch_a_c);
			if(!possivel) return false;
		}
	}

	if(encurralado && aux_letter != 'b')
	{
	//cout << "batata" << endl;
		for(int id_adj : nodes[id].adj) // olha os adjacentes
		{
			char letter = nodes[id_adj].letter;
			if(letter != aux_letter && letter != 'b' && letter != BLANK)
			{
				return false;
			}
		}
	}

	//cout << "size nadj: " << nodes[id].not_adj.size() << endl;
	//cout << "size adj: " << nodes[id].adj.size() << endl;
		
	if(id == n - 1) 	return true;
	
	return tem_resp(n, id + 1, switch_a_c);
}

int main()
{
	int n, m;
	
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
		
		nodes[n1].not_adj.erase(n2); // tira os que tem conexao
		nodes[n2].not_adj.erase(n1);

		nodes[n1].adj.insert(n2);
		nodes[n2].adj.insert(n1);
	}

	if(tem_resp_valida(n, 0, true)){
		cout << "Yes" << endl;
		cout << s << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}
