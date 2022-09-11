//https://neps.academy/br/exercise/24

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << ", ";

struct node
{
	unordered_set<int> adjs;
	//unordered_map<int, unordered_set<int>> routes;
	unordered_map<int, int> routes; 
	int c;
};

unordered_map<int, node> graph;
unordered_set<int> visited = {};
stack<int> path = {};

bool foo(int p, int c)
{
	// << "foo\n";

	graph[p].c = c;
	return true;
}

bool can_paint(int p, int q, int c)
{
	visited.insert(p);
	//DEBUG(p);
	//DEBUG(q);
	//DEBUG(c);
	//cout << endl;
	
	if(p == q) 
	{
		//cout << "1" << endl;
		return foo(p, c);
	}

	unordered_map<int, int> child_routes = graph[p].routes;
	if( child_routes.find(q) != child_routes.end() )
	{
		int child = child_routes[q];
		
		while(child != q)
		{
			graph[child].c = c;
			path.push(child);
			child = graph[child].routes[q];
		}

		graph[p].c = c;
		graph[q].c = c;

		return true;
	}
	
	for (int child : graph[p].adjs)
	{
		if(visited.find(child) != visited.end()) continue;
		
		////DEBUG(child);

		

		if(can_paint(child, q, c))
		{
			path.push(child);

			stack<int> aux_path = path;
			while(!aux_path.empty())
			{
				int next_in_stack = aux_path.top();

				graph[p].routes[next_in_stack] = child;
				aux_path.pop();
			}
			

			//DEBUG(p);
			//DEBUG(child);
			//cout << endl;
			//cout << p << " -> " << q << "? : " << graph[p].routes[child] << endl;

			//cout << "3" << endl;
			//cin >> child;
			return foo(p, c);
		}
	}

	//cout << "IMPOSSIBLE" << endl;
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
		//cout << "-------------------" << endl;
		int p, q, c;
		cin >> p >> q >> c;

		can_paint(p, q, c);

		visited = {};
		path = {};


		for (int j = 1; j <= n; j++)
		{
			//cout << graph[j].c << " ";
		}
		//cout << endl;	
	}

	for (int i = 1; i <= n; i++)
	{
		cout << graph[i].c << " ";
	}
	cout << endl;		

	return 0;
}

