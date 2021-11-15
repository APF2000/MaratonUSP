// https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include <unordered_map>

using namespace std;

long n;
unordered_map<long, unordered_map<long, long>> scores;

void add_score(long v1, long v2)
{
	if(scores.find(v1) == scores.end())
	{
		scores[v1] = {};
	}

	scores[v1][v2] = -1;// = m_aux;
}

int main()
{
	cin >> n;
	for (long i = 0; i < n; i++)
	{
		long v1, v2;
		cin >> v1 >> v2;

		add_score(v1, v2);
		add_score(v2, v1);
	}

	for(pair<long, unordered_map<long, long>> el : scores)
	{
		cout << el.first << " : {";
		for(pair<long, long> el2 : el.second)
		{
			cout << " {" << el2.first << " : " << el2.second << "}, ";
		} 

		cout << "}" << endl;
	}

	return 0;
}