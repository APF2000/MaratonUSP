//https://codeforces.com/contest/1307/problem/D

#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define INF 1000 * 1000 * 1000 // greater than 2 * 10^5

using namespace std;

typedef long long ll;

void debug_q(queue<int> q)
{
	while(q.size() != 0)
	{
		int el = q.front();
		q.pop();

		cout << el << ", ";
	}
	cout << endl;
}

unordered_map<ll, unordered_set<ll>> graph;
unordered_set<ll> specials;
ll n, m, k;

vector<ll> djikstra(ll start)
{
	debug(start);
	
	vector<ll> dists(n);
	for (int i = 0; i < n; i++) dists[i] = INF; // all nodes are infinitly far away
	dists[start] = 0;

	unordered_set<ll> nodes_to_visit = {start};
	vector<bool> visited(n);
	for (int i = 0; i < n; i++) visited[i] = false; 

	while (nodes_to_visit.size() > 0)
	{
		debug_v(nodes_to_visit);
		debug_v(visited);

		ll id_node = *(nodes_to_visit.begin());
		nodes_to_visit.erase(id_node);
		visited[id_node] = true;

		for(ll adj_node : graph[id_node])
		{
			bool was_visited = visited[adj_node];
			if(!was_visited)
			{
				cout << "to be visited: " << adj_node << endl;
				nodes_to_visit.insert(adj_node);
			}
			

			ll old_weight = dists[adj_node];
			ll new_weight = dists[id_node] + 1;

			debug_ln(adj_node);
			debug_ln(old_weight);
			debug_ln(new_weight);

			if(new_weight < old_weight) dists[adj_node] = new_weight;
			debug_v(dists);
			cout << "--------------" << endl;
		}
	}
	cout << "==============" << endl;

	return dists;	
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		ll special;
		cin >> special;
		specials.insert(special);
	}

	for (int i = 0; i < m; i++)
	{
		ll v1, v2;
		cin >> v1 >> v2;

		// decrement to be 0-indexed
		v1--;
		v2--;

		graph[v1].insert(v2);
		graph[v2].insert(v1);
	}

	for (int i = 0; i < n; i++)
	{
		cout << i << " : ";
		for(ll el : graph[i])
		{
			cout << el << " ";
		}
		cout << endl;
	}

	vector<ll> dists_start 	= djikstra(0);
	vector<ll> dists_end 	= djikstra(n - 1);

	debug_v(dists_start);
	debug_v(dists_end);

	vector<ll> dists_diff;
	for (int i = 0; i < n; i++)
	{
		dists_diff.push_back( dists_end[i] - dists_start[i] );
	}

	debug_v(dists_diff);

	return 0;
}
