// https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include <unordered_map>

using namespace std;

long n;
unordered_map<long, unordered_map<long, long>> scores;
unordered_map<long, unordered_map<long, long>> qttys;

void add_score(long v1, long v2)
{
	if(scores.find(v1) == scores.end())
	{
		scores[v1] = {};
		qttys[v1] = {};
	}

	scores[v1][v2] = -1;
	qttys[v1][v2] = -1;
}

void calc_score(long root, long req_node, long *score, long *qtty)
{
	long new_score = 1;
	long new_qtty = 1;

	for(pair<long, long> child : scores[req_node])
	{
		long c_node = child.first;
		long c_score = child.second;
		long c_qtty = qttys[req_node][c_node];

		if(c_node == root) continue;

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
	for (long i = 0; i < n - 1; i++)
	{
		long v1, v2;
		cin >> v1 >> v2;

		add_score(v1, v2);
		add_score(v2, v1);
	}

	long max_score = -1;
	for (long i = 0; i < n; i++)
	{
		long new_score, new_qtty;
		calc_score(i + 1, i + 1, &new_score, &new_qtty);
		if(new_score > max_score) max_score = new_score;
	}

	cout << max_score << endl;

	return 0;
}