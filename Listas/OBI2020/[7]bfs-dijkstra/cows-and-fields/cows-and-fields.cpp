//https://codeforces.com/contest/1307/problem/D

#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) for(auto el : v) cout << el << ", "; cout << endl;

#include <iostream>
#include <queue>

using namespace std;

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

	return 0;
}
