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

char add_letter(bool is_a, int id)
{
	char aux_letter = (is_a ? 'a' : 'c');

	s[id] = aux_letter;
	nodes[id].letter = aux_letter;

	//cout << "s: " << s << endl;

	return aux_letter;
}

bool tem_resp(int n, int id, bool is_a)
{
	if(id >= n) return true; // passou do ultimo

	nodes[id].check = true; // elemento foi checado

	char previous_letter = s[id];
	char aux_letter = add_letter(is_a, id);

	// entrou em contradicao
	if(previous_letter != BLANK && previous_letter != aux_letter) return false;

	unordered_set<int> not_adj = nodes[id].not_adj;
	if(not_adj.size() == 0) // primeira(s) letra(s) e(sao) b
	{
		s[id] = 'b';
		return tem_resp(n, id + 1, is_a);
	}

	for(int id_not_adj : not_adj)
	{
		node *aux_node = &nodes[id_not_adj];
		if(aux_node->check)
		{
			if(aux_node->letter == aux_letter) return false;
		}else
		{
			if(!tem_resp(n, id_not_adj, !is_a)) return false;
		}
	}

	return true;
}

bool check_contradiction()
{
	for(unsigned long i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		for(int id_adj : nodes[i].adj)
		{
			// cout << "ch : " << ch << endl;
			// cout << "sidajd : " << s[id_adj] << endl;
			if(ch != s[id_adj] && ch != 'b' && s[id_adj] != 'b') return false;
		}
	}
	return true;
}

bool tem_resp_valida(int n, int id, bool is_a)
{
	bool tem = tem_resp(n, 0, true);
	if(!tem) return false;

	// cout << "TEM RESP" << endl;

	for(unsigned long i = 0; i < s.size(); i++)
	{
		if(s[i] == BLANK) s[i] = 'b'; // quem nao tinha sido setado ainda
	}

	//cout << "S: " << s << endl;

	return check_contradiction();
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
