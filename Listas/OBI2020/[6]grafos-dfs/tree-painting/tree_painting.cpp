// https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdlib>

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
	//cout << "aaaaaaa" << endl;
	// continue only if branch was not visited
	// if(visited.find(root) == visited.end()) // init root visited nodes
	// {
	// 	visited[root] = {};
	// }


	// debug(root);
	// debug(req_node);
	// cout << endl;

	// unordered_set<long> aux_visited = visited[root];
	// if(aux_visited.find(req_node) != aux_visited.end()) // found
	// {
	// 	cout << "aaaaaaa2" << endl;
	// 	return;
	// }

	// visited[root].insert(req_node);


	for(long child : graph[req_node])
	{
		long c_node = child;
		long c_score = scores[req_node][c_node];
		long c_qtty = qttys[req_node][c_node];

		if(c_node == root) continue;

		// //debug(&(scores[req_node][c_node]));
		// //debug(&scores[req_node][c_node]);

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

void calc_remaning_score_and_qtty()
{
	for(auto branch : visited_branchs)
	{
		long ex_root = branch.first;
		long ex_child = branch.second;
		cout << ex_root << " " << ex_child << endl;

		long pqr = partial_qttys[ex_root];
		long pqc = partial_qttys[ex_child];

		long psr = partial_scores[ex_root];
		long psc = partial_scores[ex_child];

		long qtty_other_children = pqr - pqc;
		long score_subtree_child = psc - pqc - psr;
		long score_other_children = max_score - n - ;//psc - pqr - score_subtree_child;

debug(qtty_other_children);
// debug(score_subtree_child);
debug(score_other_children);
cout << endl;
		// long pseg = partial_scores[grandfather];
		// long pqeg = partial_qttys[grandfather];

		debug(psc);
		debug(pqc);
		debug(psr);
		debug(pqr);
		cout << endl;

		long new_qtty = qtty_other_children;
		long new_score = score_other_children;
	
		qttys[ex_child][ex_root] = new_qtty;
		scores[ex_child][ex_root] = new_score;
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

	calc_remaning_score_and_qtty();
	debug_map_map(qttys);
	cout << "==============" << endl;
	debug_map_map(scores);
	

	cout << max_score << endl;
	// //cout << count << endl;

	return 0;
}