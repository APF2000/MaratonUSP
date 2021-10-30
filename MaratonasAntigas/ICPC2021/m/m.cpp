#include <bits/stdc++.h>

using namespace std;

struct node
{
	long id;
	bool dead;
	vector<long> children;
};

map<long, node*> sucessao;
node current_king;

long next_king()
{
	
}

int main()
{
	// enquanto tem input
	// se alguem nasceu, adiciona no map e no vector do pai
	// else (se alguem morreu), muda o status do dead do map
	// 			se o que morreu era o rei, descobre qual o proximo com a recursao

	return 0;
}