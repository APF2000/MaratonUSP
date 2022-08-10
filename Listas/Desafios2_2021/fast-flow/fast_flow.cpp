// https://www.spoj.com/problems/FASTFLOW/en/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

typedef unsigned long long ull;
#define BLANK -1

using namespace std;

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }

void dmap(unordered_map<int, unordered_set<int>> m)
{
	for(auto p : m)
	{
		cout << p.first << " : ";
		unordered_set<int> linked_to = p.second;
		dv(linked_to);
	}
}

int n, m;
vector<vector<ull>> weights;
unordered_map<int, unordered_set<int>> u_graph, d_graph; 

void build_u_graph()
{
	for (int i = 0; i < m; i++)
	{
		int a, b;
		ull c;

		cin >> a >> b >> c;
		a--; b--;

		if(a == b) continue;

		ull new_w = c, old_w = weights[a][b];
		if(old_w != BLANK) new_w += old_w;

		weights[a][b] = new_w;
		weights[b][a] = new_w;

		// add to undirected graph
		u_graph[a].insert(b);
		u_graph[b].insert(a);
	}
}

// use BFS to turn undirected graph into directed
void build_d_graph()
{
	unordered_set<int> adjs = u_graph[0];

	unordered_set<int> visited = {};

	queue<int> to_visit;
	to_visit.push(0);
	//for(int node : adjs) to_visit.push(node);

	while(!to_visit.empty())
	{
		int node = to_visit.front();
		to_visit.pop();
		visited.insert(node);

		d(node);
		dv(visited);

		for(int adj_node : u_graph[node])
		{
			if(visited.find(adj_node) != visited.end()) 
				continue; 

			to_visit.push(adj_node);

			cout << "a" << endl;
			d(node);
			dln(adj_node);

			// arrow goes from node to adj_node
			d_graph[node].insert(adj_node);
		}
	}
}

int main()
{
	cin >> n >> m;

	// itialize weights with blank
	weights = vector<vector<ull>>(n, vector<ull>(n, BLANK));

	build_u_graph();
	build_d_graph();

	dm(weights);
	dmap(u_graph);
	dmap(d_graph);

	return 0;
}
