//https://codeforces.com/contest/1307/problem/D

#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

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
		special--;
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

	vector<pair<ll, ll>> dists_diff;
	for (int i = 0; i < n; i++)
	{
		bool is_special = (specials.find(i) != specials.end());
		if(is_special)
		{
			ll diff = dists_end[i] - dists_start[i];
			dists_diff.push_back( {diff, i} );
		}
	}

	for(auto el : dists_diff)
	{
		cout << el.first << " ";
	}
	cout << endl;
	sort(dists_diff.begin(), dists_diff.end());

	for(auto el : dists_diff)
	{
		cout << el.first << " ";
	}
	cout << endl;

	ll size = dists_diff.size();
	ll id_node1 = dists_diff[0].second;
	ll id_node2 = dists_diff[1].second;

	cout << id_node1 << " " << id_node2 << endl;

	// compare dists when node1 and node2 are connected
	ll dist1 = dists_start[id_node1] + dists_end[id_node2] + 1;
	ll dist2 = dists_start[id_node2] + dists_end[id_node1] + 1;
	ll dist3 = dists_start[n - 1];

	debug_ln(dist1);
	debug_ln(dist2);
	debug_ln(dist3);

	ll min_dist = min({dist1, dist2, dist3});
	debug_ln(min_dist);

	return 0;
}
