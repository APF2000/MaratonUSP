// https://codeforces.com/gym/103485/problem/K

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>
typedef unsigned long long ull;
#define DEBUG(x) cout << #x << " = " << x << ", " << endl;

using namespace std;

int main()
{
	ull n, k;
	cin >> n >> k;
	vector<ull> plant;
	vector<bool> dias;

	for(ull i = 0; i < n; i++)
	{
		ull num;
		cin >> num;
		plant.push_back(num);
		dias.push_back(false);
	}
	for(ull i = 0; i < n; i++){
		ull num;
		cin >> num;
		ull tempo = (plant[i] + num)%k;
		if (dias[tempo] == true){
			cout << "N" << endl;
			return 0;
		}
		dias[tempo] = true;
	}	
	cout << "S" << endl;
	return 0;
}