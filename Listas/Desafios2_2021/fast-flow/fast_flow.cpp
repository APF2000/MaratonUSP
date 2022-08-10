// https://www.spoj.com/problems/FASTFLOW/en/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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

int main()
{
	cin >> n >> m;

	// itialize weights with blank
	weights = vector<vector<ull>>(n, vector<ull>(n, BLANK));

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

	dm(weights);
	dmap(u_graph);

	return 0;
}
