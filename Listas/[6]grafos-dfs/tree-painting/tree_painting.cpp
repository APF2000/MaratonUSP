// https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long n;
long count = 0;
unordered_map<long, unordered_map<long, long>> scores, qttys;
unordered_map<long, unordered_set<long>> visited, not_visited;
void add_score(long v1, long v2)
{
	// if(scores.find(v1) == scores.end())
	// {
	// 	scores[v1] = {};
	// 	qttys[v1] = {};
	// }
	//cout << "v1: " << v1 << ", v2: " << v2 << endl;

	if(not_visited.find(v1) == not_visited.end())
	{
		not_visited[v1] = {};
		visited[v1] = {};
	}

	not_visited[v1].insert(v2);

	scores[v1][v2] = -1;
	qttys[v1][v2] = -1;
}

void calc_score(long root, long req_node, long *score, long *qtty)
{
	long new_score = 1;
	long new_qtty = 1;
	count++;

	//cout << "#################\nroot: " << root << endl; 
	//cout << "req_node: " << req_node << endl;


	// for (long i = 1; i < n + 1; i++)
	// {
	// 	//cout << i << " : {";
	// 	for (long node : not_visited[i])
	// 	{
	// 		//cout << node << ", ";
	// 	}
	// 	//cout << "}" << endl;
	// }

	unordered_set<long> aux = visited[req_node];

	for(long child : aux)
	{
		long c_node = child;
		long c_score = scores[req_node][c_node];
		long c_qtty = qttys[req_node][c_node];

		if(c_node == root) continue;
		
		//cout << "-------------------" << endl;
		
		//cout << "c_node: " << c_node << ", visited" << endl;

		//cout << "visited: c_qqty: " << c_qtty << ", c_score: " << c_score << endl;

		//count++;

		new_qtty += c_qtty;
		new_score += (c_score + c_qtty);
	}

	aux = not_visited[req_node];

	//for(pair<long, long> child : scores[req_node])
	for(long child : aux)
	{
		long c_node = child;
		long c_score = scores[req_node][c_node];
		long c_qtty = qttys[req_node][c_node];

		if(c_node == root) continue;

		////cout << "--------------\nchild: " << c_node << endl;
		//cout << "-------------------" << endl;

		// for(pair<long, unordered_map<long, long>> el : qttys)
		// {
		// 	//cout << el.first << " : {";
		// 	for(pair<long, long> el2 : el.second)
		// 	{
		// 		//cout << " {" << el2.first << " : " << el2.second << "}, ";
		// 	} 

		// 	//cout << "}" << endl;
		// }
		// //cout << req_node << " : {"; 
		// for(long aux : not_visited[req_node])
		// {
		// 	//cout << aux << ", ";
		// }
		// //cout << "}" << endl;

		not_visited[req_node].erase(c_node);
		visited[req_node].insert(c_node);

		////cout << "aqui vai dar pau" << endl;

		//cout << "c_node: " << c_node << ", not_visited" << endl;
		//cout << "c_qqty: " << c_qtty << ", c_score: " << c_score << endl;

		//count++;

		if(c_score == -1 || c_qtty == -1)
		{
			calc_score(req_node, c_node, &c_score, &c_qtty);

			scores[req_node][c_node] = c_score;
			qttys[req_node][c_node] = c_qtty;
		}	

		new_qtty += c_qtty;
		new_score += (c_score + c_qtty);
	}

	*score = new_score;
	*qtty = new_qtty;
}

int main()
{
	cin >> n;
	for (long i = 0; i < n; i++)
	{
		scores.push_back({});
		qttys.push_back({});
	}

	for (long i = 0; i < n - 1; i++)
	{
		long v1, v2;
		cin >> v1 >> v2;

		add_score(v1 - 1, v2 - 1);
		add_score(v2 - 1, v1 - 1);
	}

	for (long i = 1; i < n + 1; i++)
	{
		//cout << i << " : {";
		for (long node : not_visited[i])
		{
			//cout << node << ", ";
		}
		//cout << "}" << endl;
	}

	long max_score = -1;
	for (long i = 0; i < n; i++)
	{
		long new_score, new_qtty;
		//cout << "==================" << endl;
		calc_score(i + 1, i + 1, &new_score, &new_qtty);
		if(new_score > max_score) max_score = new_score;
	}

	cout << max_score << endl;
	cout << count << endl;


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