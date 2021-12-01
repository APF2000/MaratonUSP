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
	// << endl;
	
	if(p == q) 
	{
			// << "1" << endl;
		return foo(p, c);
	}

	unordered_map<int, int> child_routes = graph[p].routes;
	if( child_routes.find(q) != child_routes.end() )
	{
		int child = child_routes[q];
		path.push(child);
		// << "\n2" << endl;
		can_paint(child, q, c);
		return foo(p, c);
	}
	
	for (int child : graph[p].adjs)
	{
		if(visited.find(child) != visited.end()) continue;
		
		//DEBUG(child);

		

		if(can_paint(child, q, c))
		{
			path.push(child);

			stack<int> aux_path = path;
			while(!aux_path.empty())
			{
				int next_in_stack = aux_path.top();

				graph[p].routes[child] = next_in_stack;
				aux_path.pop();
			}
			

			// DEBUG(p);
			// DEBUG(child);
			// cout << ": {";
			// for(int el : graph[p].routes[child])
			// {
			// 	cout << el << " ";
			// }
			// cout << "}" << endl;

			//cout << "3" << endl;
			//cin >> child;
			return foo(p, c);
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
		path = {};
	}

	for (int i = 1; i <= n; i++)
	{
		cout << graph[i].c << " ";
	}
	cout << endl;		

	return 0;
}

