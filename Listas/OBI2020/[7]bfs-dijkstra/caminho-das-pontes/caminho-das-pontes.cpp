// https://neps.academy/br/exercise/297

// #include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class conn{
	public:
		int peso;
		int adj;

		bool operator < (conn other) const{
			return peso < other.peso;
		}
	
};

map<int, set<conn>> graph;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s,t,b;
		cin >> s >> t >> b;
		conn n;
		n.adj = t;
		n.peso = b;
		graph[s].insert(n);
	}
	cout << "Fim" << endl;
	return 0;
}