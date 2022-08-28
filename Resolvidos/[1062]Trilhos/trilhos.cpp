#include <iostream>
#include<vector>

using namespace std;

int permutacao_ok(int first, int n)
{
	vector<int> permutacao;
	permutacao.push_back(first);

	for(int i = 1; i < n; i++)
	{
		cin >> first;
		permutacao.push_back(first);
	}
	
	for(int i = 0; i < n; i++)
	{
		int pivot = permutacao.at(i);
		int menor = pivot;
		for(int j = i + 1; j < n; j++)
		{	
			int sequence = permutacao.at(j);
			if(sequence < pivot)
			{
				if(sequence < menor) menor = sequence;
				else return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int n;
	cin >> n;
	while(n!= 0)
	{
		if(!n) break;

		int first;
		cin >> first;
		while(first != 0)
		{
			if(!first)
			{
				cout << "\n";
				break;
			}
			cout << (permutacao_ok(first, n) ? "Yes" : "No") << "\n";
			cin >> first;
		}
		
		cin >> n;
	}

	return 0;
}
