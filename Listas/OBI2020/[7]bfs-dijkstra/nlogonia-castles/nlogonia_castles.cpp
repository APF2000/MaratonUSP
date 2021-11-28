//https://neps.academy/br/exercise/24

// #include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct node
{
	unordered_set<int> adjs;
	int c;
};

unordered_map<int, node> graph;

void paint(int p, int q, int c)
{
	unordered_set<int> not_visited = graph[p].adjs, visited = {};
	
	graph[p].c = c;
	graph[q].c = c;

	while(!not_visited.empty())
	{
		long child = *( not_visited.begin() );

		if(child == q) break;
		if(visited.find(child) != visited.end()) continue;

		not_visited.erase(child);
		visited.insert(child);

		graph[child].c = c;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].adjs.insert(v);
		graph[v].adjs.insert(u);

		graph[i].c = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int p, q, c;
		cin >> p >> q >> c;

		paint(p, q, c);
	}

	for (int i = 0; i < n; i++)
	{
		cout << graph[i].c << " ";
	}
	cout << endl;		

	return 0;
}

