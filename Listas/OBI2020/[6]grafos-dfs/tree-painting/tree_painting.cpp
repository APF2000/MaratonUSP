// https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include <queue>

using namespace std;

long n;
//long count = 0;
unordered_map<long, unordered_map<long, long>> scores, qttys;
unordered_map<long, unordered_set<long>> graph;
//unordered_map<long, unordered_set<long>> visited, not_visited;

void add_score(long v1, long v2)
{
	// if(scores.find(v1) == scores.end())
	// {
	// 	scores[v1] = {};
	// 	qttys[v1] = {};
	// }
	//cout << "v1: " << v1 << ", v2: " << v2 << endl;

	// if(graph.find(v1) == graph.end())
	// {
	// 	graph[v1] = {};
	// }

	graph[v1].insert(v2);

	scores[v1][v2] = -1;
	qttys[v1][v2] = -1;
}

long calc_score(long root)
{
	// for(pair<long, long> child : scores[root])
	// {
	// 	long c_node = child.first;
	// 	long c_score = child.second;
	// 	long c_qtty = qttys[root][c_node];


	// }
	unordered_set<long> nodes_to_visit = graph[root];
	long total_score = 0;

	while(!nodes_to_visit.empty())
	{
		long node = *( nodes_to_visit.begin() );
		nodes_to_visit.erase(node);

		cout << "node: " << node << endl;

		long score = scores[root][node];
		if(score == -1)
		{
			score = calc_score(node);
		}
		total_score += score;
	}
}

int main()
{
	cin >> n;
	for (long i = 1; i <= n - 1; i++)
	{
		long v1, v2;
		cin >> v1 >> v2;

		add_score(v1 - 1, v2 - 1);
		add_score(v2 - 1, v1 - 1);

		graph[0].insert(i);
	}

	long max_score = -1;
	calc_score(0);
	// for (long i = 0; i < n; i++)
	// {
	// 	long new_score, new_qtty;
	// 	//cout << "==================" << endl;
	// 	new_score = calc_score(i + 1);
	// 	if(new_score > max_score) max_score = new_score;
	// }

	for (long i = 1; i <= n - 1; i++)
	{
		long new_score = scores[0][i];
		if(new_score > max_score) max_score = new_score;
	}

	cout << max_score << endl;
	//cout << count << endl;


	// //cout << "-------------------------------" << endl;

	// for(pair<long, unordered_map<long, long>> el : qttys)
	// {
	// 	//cout << el.first << " : {";
	// 	for(pair<long, long> el2 : el.second)
	// 	{
	// 		//cout << " {" << el2.first << " : " << el2.second << "}, ";
	// 	} 

	// 	//cout << "}" << endl;
	// }

	return 0;
}