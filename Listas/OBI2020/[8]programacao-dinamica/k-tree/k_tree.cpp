// https://codeforces.com/problemset/problem/431/C

// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

#define MODULO 1000000007
#define BLANK -1

using namespace std;

typedef long long ll;

#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define debug_m(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) { cout << el << ", "; } cout << endl; } cout << endl;

vector<vector<ll>> mem_paths_with_d, mem_paths_without_d;

void calc_paths(int n, int k, int d, ll *paths_with_d, ll *paths_without_d)
{
	if(n == 0) return;
	for (int i = 1; i < min(k, n - k); i++)
	{
		ll (*aux_paths_with_d) = 0, (*aux_paths_without_d) = 0;

		// count for child subtree
		if(mem_paths_with_d[i][n - i] == BLANK) // works for any of the mems
		{
			calc_paths(n - i, k, d, aux_paths_with_d, aux_paths_without_d);
			mem_paths_with_d[i][n - i] 		= *aux_paths_with_d;
			mem_paths_without_d[i][n - i] 	= *aux_paths_without_d;
		}

		// sum child subtree to current subtree
		if(i == d) 
		{
			*paths_with_d += *aux_paths_with_d + *aux_paths_without_d;
			*paths_without_d += 0;
		}
	}
}

int main()
{
	int n, k, d;

	cin >> n >> k >> d;
	
	for (int i = 0; i < n; i++)
	{
		vector<ll> aux_v;
		for (int j = 0; j < n; j++)
		{
			aux_v.push_back(BLANK);
		}
		mem_paths_with_d.push_back(aux_v);
		mem_paths_without_d.push_back(aux_v);
	}

	debug_m(mem_paths_with_d);	
	debug_m(mem_paths_without_d);	

	return 0;
}
