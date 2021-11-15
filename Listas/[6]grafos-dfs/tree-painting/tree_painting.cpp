// https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<int, unordered_map<int, int>> scores;

void add_score(int v1, int v2)
{
	if(scores.find(v1) == scores.end())
	{
		scores[v1] = {};
	}

	pair<int, int> aux;
	aux.first = v2;
	aux.second = -1;

	scores[v1].insert(aux);// = m_aux;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;

		add_score(v1, v2);
		add_score(v2, v1);
	}

	for(pair<int, unordered_map<int, int>> el : scores)
	{
		cout << el.first << " : {";
		for(pair<int, int> el2 : el.second)
		{
			cout << " {" << el2.first << " : " << el2.second << "}, ";
		} 

		cout << "}" << endl;
	}

	return 0;
}