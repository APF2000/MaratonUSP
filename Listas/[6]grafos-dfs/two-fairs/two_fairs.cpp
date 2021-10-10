// https://codeforces.com/problemset/problem/1276/B

#include <iostream>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

struct node
{
	unordered_set<long> adjs;
	//bool dirty;
};

node construct_node(unordered_set<long> adjs)
{
	node n;
	n.adjs = adjs;

	//n.dirty = false;

	return n;
}

unordered_set<long> find_direct_paths_adj_to_b(map< long, node > graph, long a, long b)
{
	unordered_set<long> direct_paths = {};

	node n_a = graph[a];
	queue<long> nodes_to_visit;
	nodes_to_visit.push(a);

	unordered_set<long> visited_nodes = {a};

	while(!nodes_to_visit.empty())
	{
		cout << "finddirectpaths" << endl;

		long key_node = nodes_to_visit.front();

		// not visited into queue
		for(long adj : graph[key_node].adjs)
		{
			if(adj == b) direct_paths.insert(key_node);

			if(visited_nodes.find(adj) == visited_nodes.end())
			{ 
				nodes_to_visit.push(adj);
			}
		}

		nodes_to_visit.pop();
	}

	return direct_paths;
}

void remove_dirty_nodes(map< long, node > *graph, long a, long b, unordered_set<long> direct_nodes)
{
	while(!direct_nodes.empty())
	{
		cout << "removedirty" << endl;

		long node_key = *(direct_nodes.begin());
		direct_nodes.erase(node_key);
		node n = (*graph)[node_key];

		for(long adj : n.adjs)
		{
			if(adj != a && adj != b)
			{
				direct_nodes.insert(adj);
			}

			(*graph)[adj].adjs.erase(node_key);
		}

		graph->erase(node_key);
	}
}

int count_clean_nodes(map< long, node > graph, long key)
{
	node n = graph[key];
	unordered_set<long> clean_nodes = {key};
	int count = 0;

	while(!clean_nodes.empty())
	{

		cout << "clean nodes" << endl;

		long node_key = *(clean_nodes.begin());
		clean_nodes.erase(node_key);
		count++;

		node n = graph[node_key];

		for(long adj : n.adjs)
		{
			if(adj != key)
			{
				clean_nodes.insert(adj);
			}

			graph[adj].adjs.erase(node_key);
		}

		graph.erase(node_key);
	}

	return count - 1;
}

long solve(map< long, node > graph, long a, long b)
{
	unordered_set<long> direct_nodes = find_direct_paths_adj_to_b(graph, a, b);
	remove_dirty_nodes(&graph, a, b, direct_nodes);
	int clean_a = count_clean_nodes(graph, a);
	int clean_b = count_clean_nodes(graph, b);

	return clean_a * clean_b;

	return 0;
}

void add_edge(map< long, node > *graph, long v1, long v2)
{
	if(graph->find(v1) == graph->end())
	{
		node n = construct_node({});
		(*graph)[v1] = n;
	}

	(*graph)[v1].adjs.insert(v2);
}

int main()
{
	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long n, m, a, b;
		cin >> n >> m >> a >> b;

		map< long, node > graph;

		for (int j = 0; j < m; j++)
		{
			long v1, v2;
			cin >> v1 >> v2;

			add_edge(&graph, v1, v2);
			add_edge(&graph, v2, v1);
		}
		
		long ans = solve(graph, a, b);
		cout << ans << endl;
	}
	

	return 0;
}