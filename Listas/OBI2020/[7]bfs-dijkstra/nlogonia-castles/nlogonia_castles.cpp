//https://neps.academy/br/exercise/24

#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
	visited.insert(p);
	
	if(p == q)
	{
		graph[p].c = c;
		return true;
	}

	for (int child : graph[p].adjs)
	{
		if(visited.find(child) != visited.end()) continue;

		if(can_paint(child, q, c))
		{
			graph[p].c = c;
			return true;
		}
	}

	return false;
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
	}

	for (int i = 1; i <= n; i++)
	{
		cout << graph[i].c << " ";
	}
	cout << endl;		

	return 0;
}

