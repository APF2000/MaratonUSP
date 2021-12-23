// https://neps.academy/br/exercise/297

// #include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

#define MAX_INT ~(1 << 31)

using namespace std;

class conn{
	public:
		int peso;
		int adj;

		bool operator < (conn other) const{
			return peso < other.peso;
		}
	
};

unordered_map<int, set<conn>> graph;

//unordered_map<int, unordered_map<int, bool>> vis_edges;
unordered_set<int> vis_nodes;

queue<int> next_nodes;
vector<int> pesos;

int n, m;

int calc_min_holes()
{
	next_nodes.push(0);
	vis_nodes = {0};
	
	while( vis_nodes.size() < n )
	{
		int this_node = next_nodes.front();
		next_nodes.pop();
		
		vis_nodes.insert(this_node);

		for(conn edge : graph[this_node])
		{
			int edge_peso = edge.peso;
			int adj_id = edge.adj;
			int best_adj_peso = pesos[adj_id];

			if( vis_nodes.find(adj_id) == vis_nodes.end() ) // never seen
			{
				next_nodes.push(adj_id);
			}

			int best_this_peso = pesos[this_node];
			if(best_this_peso == MAX_INT)
			{
				cout << "EU SOU BURRO" << endl;
			}

			int new_peso = best_this_peso + edge_peso;
			if(new_peso < best_adj_peso)
			{
				pesos[adj_id] = new_peso;
			}
		}
	}

	return pesos[n - 1];
}

int main()
{
	cin >> n >> m;
	n += 2; // begin + (middle (n)) + end

	for (int i = 0; i < n; i++)
	{
		pesos.push_back( MAX_INT );
		// for (int j = 0; j < m; j++)
		// {
		// 	vis_edges[i][j] = false;
		// 	vis_edges[j][i] = false;
		// }
		
	}
	pesos[0] = 0;
	
	
	for (int i = 0; i < m; i++)
	{
		int s,t,b;
		cin >> s >> t >> b;

		conn co;
		co.adj = t;
		co.peso = b;
		graph[s].insert(co);
	}

	int min_holes = calc_min_holes();
	cout << min_holes << endl;

	cout << "Fim" << endl;
	for(auto el : pesos) cout << el << " ,";
	cout << endl;
	return 0;
}