//https://neps.academy/br/exercise/24

// #include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#include <unordered_set>
//#include <queue>
#include <vector>

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << ", ";

struct node
{
	unordered_set<int> adjs;
	int c;
};

unordered_map<int, node> graph;
unordered_set<int> visited = {};

bool can_paint(int p, int q, int c)
{
	// DEBUG(p);
	// DEBUG(q);
	// DEBUG(c);
	// cout << endl;

	visited.insert(p);

	//unordered_set<int> not_visited = graph[p].adjs, visited = {};
	if(p == q)
	{
		cout << "painting " << p << endl;
		graph[p].c = c;
		return true;
	}

	// cout << p << " : {";
	// for (int child : graph[p].adjs)
	// {
	// 	cout << child << ", " << endl;
	// }
	// cout << "}" << endl;

	for (int child : graph[p].adjs)
	{
		if(visited.find(child) != visited.end()) continue;

		if(can_paint(child, q, c))
		{
			graph[p].c = c;
			cout << "painting " << p << endl;
			return true;
		}
	}
	

	
	// graph[p].c = c;
	// graph[q].c = c;

	// while(!not_visited.empty())
	// {
	// 	long child = *( not_visited.begin() );

	// 	if(child == q) break;
	// 	if(visited.find(child) != visited.end()) continue;

	// 	not_visited.erase(child);
	// 	visited.insert(child);

	// 	graph[child].c = c;
	// }
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

		can_paint(p, q, c);
		visited = {};

		// for (int i = 0; i < n; i++)
		// {
		// 	cout << graph[i].c << " ";
		// }
		// cout << endl;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << graph[i].c << " ";
	}
	cout << endl;		

	return 0;
}

