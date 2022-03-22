// https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

#define debug(x) cout << #x << " = " << x << ", ";

typedef long long ll;

void debug_map_map(unordered_map<ll, unordered_map<ll, ll>> mm)
{
	for(auto el : mm)
	{
		cout << el.first << " : { ";
		for(auto el2 : el.second)
		{
			cout << "(" << el2.first << ", " << el2.second << "), ";
		}
		cout << "}" << endl;
	}
}

ll n;
ll count = 0;
unordered_map<ll, unordered_map<ll, ll>> scores, qttys;
unordered_map<ll, unordered_set<ll>> graph;
unordered_map<ll, ll> partial_scores, partial_qttys;

void add_score(ll v1, ll v2)
{
	if(graph.find(v1) == graph.end())
	{
		graph[v1] = {};
	}

	graph[v1].insert(v2);

	if(scores.find(v1) == scores.end())
	{
		scores[v1] = {};
		qttys[v1] = {};
	}

	scores[v1][v2] = -1;
	qttys[v1][v2] = -1;
}

void calc_score_and_qtty(ll root, ll req_node)
{
	ll new_qtty = 1;
	ll new_score = 1;

	for(ll child : graph[req_node])
	{
		ll c_node = child;
		ll c_score = scores[req_node][c_node];
		ll c_qtty = qttys[req_node][c_node];

		if(c_node == root) continue;

		if(c_score == -1 || c_qtty == -1)
		{
			calc_score_and_qtty(req_node, c_node);
			c_score = scores[req_node][c_node];
			c_qtty = qttys[req_node][c_node];
		}	
		
		partial_qttys[req_node] += c_qtty;
		partial_scores[req_node] += (c_score + c_qtty);
		
		new_qtty += c_qtty;
		new_score += (c_score + c_qtty);
	}
	
	qttys[root][req_node] = new_qtty;
	scores[root][req_node] = new_score;
	
}

void calc_remaning_score_and_qtty(ll root)
{
	pair<ll, ll> aux_struct = {root, 0};
	queue<pair<ll, ll>> next_structs;
	unordered_set<ll> visited = {root};

	next_structs.push(aux_struct);

	while(!next_structs.empty())
	{
		pair<ll, ll> aux_struct = next_structs.front();
		next_structs.pop();

		ll node = aux_struct.first;
		ll father = aux_struct.second;

		for(ll child : graph[node])
		{
			aux_struct = { child, node };
			if(visited.find(child) == visited.end()) // not visited
			{
				next_structs.push(aux_struct);
				visited.insert(child);
			}
		}
		
		if(father == 0) continue;

		ll score_father = scores[0][father];
		ll score_node = partial_scores[node];

		ll qtty_father = qttys[0][father];
		ll qtty_node = partial_qttys[node];

		ll new_score = score_father - (score_node + qtty_node);
		ll new_qtty = qtty_father - qtty_node;

		scores[node][father] = new_score;
		qttys[node][father] = new_qtty;

		scores[0][node] = new_score + (score_node - qtty_node) + n;
		qttys[0][node] = n;
	}
}

int main()
{
	cin >> n;
	for (ll i = 0; i < n - 1; i++)
	{
		ll v1, v2;
		cin >> v1 >> v2;		

		add_score(v1, v2);
		add_score(v2, v1);
	}

	for (ll i = 1; i <= n; i++)
	{
		add_score(0, i);

		partial_scores[i] = 1;
		partial_qttys[i] = 1;
		
	}

	calc_score_and_qtty(0, 1);
	calc_remaning_score_and_qtty(1);

	ll max_score = -1;
	for(auto el : scores[0])
	{
		ll new_score = el.second;
		if(new_score > max_score) max_score = new_score;
	}
	cout << max_score << endl;

	return 0;
}