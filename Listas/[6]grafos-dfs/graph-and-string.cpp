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

bool tem_resp(vector<node> *nodes, int n, int id, string *s, bool last_c){
	if(id == n - 1){
		
		return true;
	}
	node nd = (*nodes)[id];
	int size_not_adj = nd.not_adj.size();
	if(size_not_adj !=0){
		if(!nd.check){
			if(last_c){
				(*s)[id] = 'a';
			} else {
				(*s)[id] = 'c';
			}
		}
		for(int el : nd.not_adj){
			if(!(*nodes)[el].check){
				
			}
		}
		
	} else{
		(*s)[id] = 'b';
	}
	tem_resp(nodes, n, id+1, s, !last_c);
}

int main()
{
	int n,m;
	vector<node> nodes;
	cin >> n >> m;
	unordered_set<int> aux_s;
	for (int i = 0; i < n; i++)
	{
		aux_s.insert(i);
	}
	string s;
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
		nodes[n1].not_adj.erase(n2);
		nodes[n2].not_adj.erase(n1);
	}
	if(tem_resp(&nodes, n, 0, &s, true)){
		cout << "Yes" << endl;
		cout << s << endl;
	} else{
		cout << "No" << endl;
	}
	return 0;
}
