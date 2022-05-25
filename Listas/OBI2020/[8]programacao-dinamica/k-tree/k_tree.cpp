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
		*paths_without_d = 1;
		*paths_with_d = 0;
		return;
	}

	// debug_ln(n);
	// debug_ln(k);
	// debug_ln(min(k, n - k));

	// for (int i = 1; i < k; i++)
	// {

		ll aux_paths_with_d = 0, aux_paths_without_d = 0;

		// count for child subtree
		if(mem_paths_with_d[n - 1] == BLANK) // works for any of the mems
		{
			cout << "antes calcpath" << endl;
			calc_paths(n - 1, k, d, &aux_paths_with_d, &aux_paths_without_d);
			//debug_m(mem_paths_with_d);

			debug_ln(aux_paths_with_d);
			debug_ln(aux_paths_without_d);

			// mem_paths_with_d[i][n - 1] 		= aux_paths_with_d;
			// mem_paths_without_d[i][n - 1] 	= aux_paths_without_d;

			cout << "depois calcpath" << endl;

		}else
		{
			cout << "ja calculado" << endl;

		}

			//debug_ln(i);
			debug_ln(n);
			//debug_ln(k);
			debug_ln(n - 1);
			debug_ln(mem_paths_with_d[n - 1]);
			debug_ln(mem_paths_without_d[n - 1]);

		aux_paths_with_d = mem_paths_with_d[n - 1];
		aux_paths_without_d = mem_paths_without_d[n - 1];

		// sum child subtree to current subtree
		// if(i == d) 
		// {
		// 	*paths_with_d += aux_paths_with_d + aux_paths_without_d;
		// 	*paths_without_d += 0;
		// }else{
		// 	*paths_with_d += aux_paths_with_d;
		// 	*paths_without_d += aux_paths_without_d;
		// }
	//}
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
	debug_v(mem_paths_with_d);	
	debug_v(mem_paths_without_d);	

	ll paths_with_d, paths_without_d;
	calc_paths(n, k, d, &paths_with_d, &paths_without_d);

	// debug_m(mem_paths_with_d);	
	// debug_m(mem_paths_without_d);	
	debug_v(mem_paths_with_d);	
	debug_v(mem_paths_without_d);	

	return 0;
}
