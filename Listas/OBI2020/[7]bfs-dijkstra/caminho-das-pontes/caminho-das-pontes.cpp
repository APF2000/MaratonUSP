// https://neps.academy/br/exercise/297

#include <iostream>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>


#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) cout << #v << " : {"; for(auto el : v) cout << el << ", "; cout << "}" << endl;

#define MAX_INT ~(1 << 31)

using namespace std;

void debug_q(queue<int> q)
{
	cout << "queue : {";
	while(q.size() != 0)
	{
		int el = q.front();
		q.pop();

		cout << el << ", ";
	}
	cout << "}" << endl;
}

class conn{
	public:
		int peso;
		int adj;

		bool operator < (conn other) const{
			return adj < other.adj;
		}
	
};

unordered_map<int, set<conn>> graph;

unordered_set<int> vis_nodes;

queue<int> next_nodes;
vector<int> pesos;

int n, m;

int calc_min_holes()
{
	next_nodes.push(0);
	vis_nodes = {0};
	
	while( vis_nodes.size() < n - 2 )
	{
		int this_node = next_nodes.front();
		next_nodes.pop();

		cout << "------------------oi" << endl;
		
		vis_nodes.insert(this_node);
		debug_v(vis_nodes);
		debug_ln(this_node);


		for(conn edge : graph[this_node])
		{
			int edge_peso = edge.peso;
			int adj_id = edge.adj;
			int best_adj_peso = pesos[adj_id];

			cout << "oi4" << endl;
			debug_ln(adj_id);
			if( vis_nodes.find(adj_id) == vis_nodes.end() ) // never seen
			{
				next_nodes.push(adj_id);
				debug_q(next_nodes);
			}

			int best_this_peso = pesos[this_node];
			if(best_this_peso == MAX_INT)
			{
				cout << "EU SOU BURRO" << endl;
			}

			int new_peso = best_this_peso + edge_peso;
			if(new_peso < best_adj_peso)
			{
				pesos[adj_id] = new_peso;
			}
			debug_v(pesos);

			cout << "oi2" << endl;
		}
	}
			cout << "oi3" << endl;

	return pesos[n - 1];
}

int main()
{
	cin >> n >> m;
	n += 2; // begin + (middle (n)) + end

	for (int i = 0; i < n; i++)
	{
		pesos.push_back( MAX_INT );		
	}
	pesos[0] = 0;
	
	
	for (int i = 0; i < m; i++)
	{
		int s,t,b;
		cin >> s >> t >> b;

		conn co;
		co.adj = t;
		co.peso = b;
		graph[s].insert(co);

		set<conn> s_aux = graph[s];

		debug(s);
		for(conn co : s_aux)
		{
			debug(co.adj);
		}
		cout << endl;
	}

	int min_holes = calc_min_holes();
	cout << min_holes << endl;

	return 0;
}