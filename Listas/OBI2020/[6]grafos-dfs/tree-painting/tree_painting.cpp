// https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define debug(x) //cout << #x << " = " << x << ", ";

void debug_map_map(unordered_map<long, unordered_map<long, long>> mm)
{
	for(auto el : mm)
	{
		//cout << el.first << " : { ";
		for(auto el2 : el.second)
		{
			//cout << "(" << el2.first << ", " << el2.second << "), ";
		}
		//cout << "}" << endl;
	}
}

long n;
long count = 0;
unordered_map<long, unordered_map<long, long>> scores, qttys;
unordered_map<long, unordered_set<long>> graph; //not_visited
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

	// long a;
	// cin >> a;


	for(long child : graph[req_node])
	{
		long c_node = child;
		long c_score = scores[req_node][c_node];
		long c_qtty = qttys[req_node][c_node];

		if(c_node == root) continue;

		// //debug(&(scores[req_node][c_node]));
		// //debug(&scores[req_node][c_node]);

		//debug(c_node);
		//debug(req_node);
		//debug(new_qtty);
		//debug(new_score);
		////cout << endl;

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

		new_qtty += c_qtty;
		new_score += (c_score + c_qtty);
	}


	//debug(root);
	//debug(req_node);
	//debug(new_qtty);
	//debug(new_score);
	//cout << endl;
	
	qttys[root][req_node] = new_qtty;
	scores[root][req_node] = new_score;
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
		//cout << "aaaaaaa" << endl;
		add_score(0, i);
		// add_score(i, 0);

		//debug_map_map(qttys);

		calc_score_and_qtty(0, i);
	}

	long max_score = -1;
	for (int i = 1; i <= n; i++)
	{
		long new_score = scores[0][i];
		if(new_score > max_score) max_score = new_score;
	}


	cout << max_score << endl;
	// //cout << count << endl;

	return 0;
}