//https://codeforces.com/contest/1307/problem/D

#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) for(auto el : v) cout << el << ", "; cout << endl;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

void debug_q(queue<int> q)
{
	while(q.size() != 0)
	{
		int el = q.front();
		q.pop();

		cout << el << ", ";
	}
	cout << endl;
}

unordered_map<ll, unordered_set<ll>> graph;
unordered_set<ll> specials;
ll m, n, k;

vector<ll> djikstra()
{
	vector<ll> v;

	return v;
}

int main()
{
	// [opcional] calcula djikstra inicial sem conexoes especiais
	// junta todos os nos especiais e chama de conexoes especiais
	// enquanto tiverem conexoes especiais:
	// 		calcula djikstra
	//		remove conexoes espceiais no meio do caminho
	//		[opcional] se tiver uma conexao especial e nao-especial ao mesmo tempo:
	//					retorna o valor do djikstra inicial
	// 		[opcional] se o novo menor caminho ja eh igual ao menor caminho sem conexoes especiais:
	//					retorna o valor do djikstra inicial (tambem)

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		ll special;
		cin >> special;
		specials.insert(special);
	}

	for (int i = 0; i < n; i++)
	{
		ll v1, v2;
		cin >> v1 >> v2;

		graph[v1].insert(v2);
		graph[v2].insert(v1);
	}

	for (int i = 1; i <= m; i++)
	{
		cout << i << " : ";
		for(ll el : graph[i])
		{
			cout << el << " ";
		}
		cout << endl;
	}

	return 0;
}
