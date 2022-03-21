// https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

#define debug(x) cout << #x << " = " << x << ", ";

void debug_map_map(unordered_map<long, unordered_map<long, long>> mm)
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

long n;
long count = 0;
long max_score;
unordered_map<long, unordered_map<long, long>> scores, qttys;
unordered_map<long, unordered_set<long>> graph;//, visited;
vector<pair<long, long>> visited_branchs;
unordered_map<long, long> partial_scores, partial_qttys;
//unordered_map<long , long> fathers;

void add_score(long v1, long v2)
{
	if(graph.find(v1) == graph.end())
	{
		graph[v1] = {};
		//visited[v1] = {};
	}

	//debug(v1);
	//debug(v2);
	////cout << endl;

	graph[v1].insert(v2);


	if(scores.find(v1) == scores.end())
	{
		scores[v1] = {};
		qttys[v1] = {};
	}


	scores[v1][v2] = -1;
	qttys[v1][v2] = -1;
}

void calc_score_and_qtty(long root, long req_node)//, long *score, long *qtty)
{
	long new_qtty = 1;
	long new_score = 1;

	visited_branchs.push_back( {root, req_node} );

	// long a;
	// cin >> a;

	// debug(root);
	// debug(req_node);
	// cout << endl;


	for(long child : graph[req_node])
	{
		long c_node = child;
		long c_score = scores[req_node][c_node];
		long c_qtty = qttys[req_node][c_node];

		if(c_node == root) continue;

		// debug(req_node);
		// debug(c_node);
		// debug(new_qtty);
		// debug(new_score);
		// cout << endl;

		//debug(c_score);
		//debug(c_qtty);
		//cout << endl;

		if(c_score == -1 || c_qtty == -1)
		{
			calc_score_and_qtty(req_node, c_node);
			c_score = scores[req_node][c_node];
			c_qtty = qttys[req_node][c_node];
		}	

		//debug(c_score);
		//debug(c_qtty);
		//cout << endl;
		partial_qttys[req_node] += c_qtty;
		partial_scores[req_node] += (c_score + c_qtty);

		// if(c_node != root)
		// {
		new_qtty += c_qtty;
		new_score += (c_score + c_qtty);
		//}
	}


	//debug(root);
	//debug(req_node);
	//debug(new_qtty);
	//debug(new_score);
	//cout << endl;
	qttys[root][req_node] = new_qtty;
	scores[root][req_node] = new_score;
	
}

void calc_remaning_score_and_qtty(long root)
{
	pair<long, long> aux_struct = {root, 0};
	queue<pair<long, long>> next_structs;
	unordered_set<long> visited;

	next_structs.push(aux_struct);

	while(!next_structs.empty())
	{
		pair<long, long> aux_struct = next_structs.front();
		next_structs.pop();

		cout << next_structs.size() << endl;

		long node = aux_struct.first;
		long father = aux_struct.second;

		debug(node);
		debug(father);
		cout << endl;

		for(long child : graph[node])
		{
			aux_struct = { child, node };
			if(visited.find(child) == visited.end()) // not visited
			{
				next_structs.push(aux_struct);
				visited.insert(child);
			}
		}

		long score_father = scores[0][father];
		long score_node = partial_scores[node];

		long qtty_father = qttys[0][father];
		long qtty_node = partial_qttys[node];

		scores[node][father] = score_father - (score_node + qtty_node);
		qttys[node][father] = qtty_father - qtty_node;

		scores[0][node] = score_father - (score_node + qtty_node) + (score_node - qtty_node) + n;
		qttys[0][node] = n;
	}
}

int main()
{
	cin >> n;
	for (long i = 0; i < n - 1; i++)
	{
		long v1, v2;
		cin >> v1 >> v2;
		

		add_score(v1, v2);
		add_score(v2, v1);
	}

	for (long i = 1; i <= n; i++)
	{
		add_score(0, i);
		// add_score(i, 0);

		//debug_map_map(qttys);


		partial_scores[i] = 1;
		partial_qttys[i] = 1;
		
	}

	// long max_score = -1;
	calc_score_and_qtty(0, 1);
	max_score = scores[0][1];
	debug_map_map(qttys);
	debug_map_map(scores);

	for(auto branch : visited_branchs)
	{
		cout << branch.first << " " << branch.second << endl;
	}
	cout << "==============" << endl;

	for(auto qtty : partial_qttys)
	{
		cout << qtty.first << " " << qtty.second << endl;
	}
	cout << "==============" << endl;

	for(auto score : partial_scores)
	{
		cout << score.first << " " << score.second << endl;
	}
	cout << "==============" << endl;

	calc_remaning_score_and_qtty(1);
	debug_map_map(qttys);
	cout << "==============" << endl;
	debug_map_map(scores);
	

	cout << max_score << endl;
	// //cout << count << endl;

	return 0;
}