// https://www.spoj.com/problems/FASTFLOW/en/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

typedef unsigned long long ull;
#define BLANK 50
#define INF 10e9

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

void dq(queue<int> q)
{
	while(q.size() != 0)
	{
		int el = q.front();
		q.pop();

		cout << el << ", ";
	}
	cout << endl;
}

int n, m;
vector<vector<ull>> capacities;
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

		ull new_w = c, old_w = capacities[a][b];
		if(old_w != BLANK) new_w += old_w;

		capacities[a][b] = new_w;
		capacities[b][a] = new_w;

		// add to undirected graph
		u_graph[a].insert(b);
		u_graph[b].insert(a);
	}
}

// use BFS to turn undirected graph into directed
void build_d_graph()
{
	unordered_set<int> adjs = u_graph[0];

	unordered_set<int> visited, nodes_added_to_queue;

	queue<int> to_visit;
	to_visit.push(0);

	// BFS
	while(!to_visit.empty())
	{
		int node = to_visit.front();
		to_visit.pop();
		visited.insert(node);

		for(int adj_node : u_graph[node])
		{
			if(visited.find(adj_node) != visited.end()) 
				continue; 

			if(nodes_added_to_queue.find(adj_node) != nodes_added_to_queue.end()) 
				continue; 

			to_visit.push(adj_node);

			// arrow goes from node to adj_node
			d_graph[node].insert(adj_node);
			nodes_added_to_queue.insert(adj_node);
		}
	}
}

ull edmonds_karp()
{
	// prepare residual graph
	vector<vector<ull>> flows = capacities;

	for(pair<int, unordered_set<int>> kv : d_graph)
	{
		unordered_set<int> adj_ids = kv.second;
		int node_id = kv.first;

		for(int adj_id : adj_ids)
		{
			flows[adj_id][node_id] = 0;
		}
	}


	while (true)
	{
		// find shortest s-t-path
		unordered_set<int> adjs = d_graph[0];
		unordered_set<int> visited = {};

		queue<int> nodes_to_visit, level_nodes_to_visit;
		nodes_to_visit.push(0);
		level_nodes_to_visit.push(0);

		int last_level = 0;
		vector<int> s_t_path = {0};

		// BFS
		while(!nodes_to_visit.empty())
		{

			int node = nodes_to_visit.front();
			nodes_to_visit.pop();
			visited.insert(node);

			int this_level = level_nodes_to_visit.front();
			level_nodes_to_visit.pop();

			if(last_level + 1 == this_level)
			{
				s_t_path.push_back(node);
				last_level++;
				if(node == n - 1) break;
			}

			for(int adj_node : u_graph[node])
			{
				if(visited.find(adj_node) != visited.end()) 
					continue; 

				if(flows[node][adj_node] == 0) continue;

				nodes_to_visit.push(adj_node);
				level_nodes_to_visit.push(this_level + 1);
			}
		}

		if(s_t_path.back() != n - 1)
		{
			ull max_flow = 0;

			for(int adj_node : d_graph[0])
			{
				max_flow += flows[adj_node][0];
			}

			return max_flow;
		}

		// find out bottleneck capacity
		ull bottleneck = INF;
		for(int i = 1; i < s_t_path.size(); i++)
		{
			int node1 = s_t_path[i - 1];
			int node2 = s_t_path[i];

			ull new_flow = flows[node1][node2];
			if(new_flow < bottleneck)
			{
				bottleneck = new_flow;
			}
		}

		// change residual flows
		for(int i = 1; i < s_t_path.size(); i++)
		{
			int node1 = s_t_path[i - 1];
			int node2 = s_t_path[i];

			unordered_set<int> edge_normal = d_graph[node1];

			// possible pointer exception
			bool edge_is_normal = ( edge_normal.find(node2) != edge_normal.end() );
			
			// change flow direction symmetrically
			if(edge_is_normal)
			{
				flows[node1][node2] -= bottleneck;
				flows[node2][node1] += bottleneck;
			}
			else
			{
				flows[node1][node2] += bottleneck;
				flows[node2][node1] -= bottleneck;
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	// initialize capacities with blank
	capacities = vector<vector<ull>>(n, vector<ull>(n, BLANK));

	build_u_graph();
	build_d_graph();

	ull max_flow = edmonds_karp();
	cout << max_flow << endl;

	return 0;
}
