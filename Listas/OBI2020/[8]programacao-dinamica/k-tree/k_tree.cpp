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

vector<ll> mem_paths_with_d, mem_paths_without_d;

void calc_paths(int n, int k, int d, ll *paths_with_d, ll *paths_without_d)
{
	if(n == 0) 
	{
		(*paths_without_d) += 1;
		return;
	}

	for (int i = 1; i <= min(n, k); i++)
	{
		ll aux_paths_with_d = 0;
		ll aux_paths_without_d = 0;

		// count for child subtree
		if(mem_paths_with_d[n - i] == BLANK) // works for any of the mems
		{
			calc_paths(n - i, k, d, &aux_paths_with_d, &aux_paths_without_d);

			mem_paths_with_d[n - i] 		= aux_paths_with_d;
			mem_paths_without_d[n - i]  	= aux_paths_without_d;
		}else
		{
			aux_paths_with_d = mem_paths_with_d[n - i];
			aux_paths_without_d = mem_paths_without_d[n - i];
		}

		// sum child subtree to current subtree
		if(i >= d) 
		{
			(*paths_with_d) += aux_paths_with_d + aux_paths_without_d;
		}else
		{
			(*paths_with_d) += aux_paths_with_d;
			(*paths_without_d) += aux_paths_without_d;
		}
	}

	(*paths_with_d) %= MODULO;
	(*paths_without_d) %= MODULO;
}

int main()
{
	int n, k, d;

	cin >> n >> k >> d;
	
	for (int i = 0; i < n; i++)
	{
		mem_paths_with_d.push_back(BLANK);
		mem_paths_without_d.push_back(BLANK);
	}

	ll paths_with_d = 0, paths_without_d = 0;
	calc_paths(n, k, d, &paths_with_d, &paths_without_d);

	cout << (paths_with_d) << endl;

	return 0;
}