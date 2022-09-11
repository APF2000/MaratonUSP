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

void debug_q(queue<ll> q)
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
	vector<ll> dists(n);
	for (int i = 0; i < n; i++) dists[i] = INF; // all nodes are infinitly far away
	dists[start] = 0;

	queue<ll> nodes_to_visit;
	nodes_to_visit.push(start);

	vector<bool> visited(n);
	for (int i = 0; i < n; i++) visited[i] = false; 

	while (nodes_to_visit.size() > 0)
	{
		ll id_node = nodes_to_visit.front();
		nodes_to_visit.pop();
		visited[id_node] = true;

		for(ll adj_node : graph[id_node])
		{
			bool was_visited = visited[adj_node];
			if(!was_visited)
			{
				nodes_to_visit.push(adj_node);
			}						

			ll old_weight = dists[adj_node];
			ll new_weight = dists[id_node] + 1;

			if(new_weight < old_weight) dists[adj_node] = new_weight;
		}
	}

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

	vector<ll> dists_start 	= djikstra(0);
	vector<ll> dists_end 	= djikstra(n - 1);

	vector<pair<ll, ll>> dists_diff;
	for (int i = 0; i < n; i++)
	{
		bool is_special = (specials.find(i) != specials.end());
		if(is_special)
		{
			ll diff = dists_start[i] - dists_end[i];
			dists_diff.push_back( {diff, i} );
		}
	}

	sort(dists_diff.begin(), dists_diff.end());

	ll best = 0;
	ll max_dist = -INF;
	for(auto it : dists_diff)
	{
		ll id_node = it.second;
		best = max(best, max_dist + dists_end[id_node]);
		max_dist = max(max_dist, dists_start[id_node]);
	}

	ll dist3 = dists_start[n - 1];
	ll min_dist = min({best + 1, dist3});
	cout << min_dist << endl;

	return 0;
}
