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
	//ll aux_with_d = 1, aux_without_d = k - 1;

	// for (int i = 0; i < n; i++)
	// {
	// 	*paths_without_d *= (k - 1);
	// 	*paths_with_d = () - *paths_without_d;

	// 	debug_ln(*paths_with_d);
	// 	debug_ln(*paths_without_d);
	// }
	ll mult_d = 1, mult_not_d = 1;
	for (int i = 0; i < n; i++)
	{
		mult_d *= (k - 1);
		mult_not_d *= (k);

		debug_ln(mult_d);
		debug_ln(mult_not_d);
	}

	*paths_without_d = mult_d;
	*paths_with_d = mult_not_d - mult_d;
	
}

int main()
{
	int n, k, d;

	cin >> n >> k >> d;
	
	for (int i = 0; i < k; i++)
	{
		// vector<ll> aux_v;
		// for (int j = 0; j < k; j++)
		// {
		// 	aux_v.push_back(BLANK);
		// }
		// mem_paths_with_d.push_back(aux_v);
		// mem_paths_without_d.push_back(aux_v);
		mem_paths_with_d.push_back(BLANK);
		mem_paths_without_d.push_back(BLANK);
	}

	// debug_m(mem_paths_with_d);	
	// debug_m(mem_paths_without_d);	
	// debug_v(mem_paths_with_d);	
	// debug_v(mem_paths_without_d);	

	ll paths_with_d = 0, paths_without_d = 1;
	calc_paths(n, k, d, &paths_with_d, &paths_without_d);

	debug_ln(paths_with_d);
	debug_ln(paths_without_d);

	// debug_m(mem_paths_with_d);	
	// debug_m(mem_paths_without_d);	
	// debug_v(mem_paths_with_d);	
	// debug_v(mem_paths_without_d);	

	return 0;
}
