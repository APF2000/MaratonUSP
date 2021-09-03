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

bool tem_resp(int n, int id, bool last_c){
	
}

int main()
{
	int n,m;
	vector<node> nodes;
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
	}

	if(tem_resp(n, 0, true)){
		cout << "Yes" << endl;
		cout << s << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}
