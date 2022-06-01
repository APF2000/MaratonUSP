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
	if(n <= 0) 
	{
		cout << "n: " << n << " <= 0" << endl;

		*paths_with_d = 0;
		*paths_without_d = 0;
		return;
	}

	// debug_ln(n);
	// debug_ln(k);
	// debug_ln(min(k, n - k));

	for (int i = 1; i <= min(n, k); i++)
	{
		cout << "=================" << endl;
		debug_ln(i);
		debug_ln(n);
		debug_ln(n - i);

		ll (*aux_paths_with_d), (*aux_paths_without_d) ;
		(*aux_paths_with_d) = 0;
		(*aux_paths_without_d) = 1;

		// count for child subtree
		if(mem_paths_with_d[n - i][i] == BLANK) // works for any of the mems
		{
			cout << "-----antes calc" << endl;
			debug_ln(*aux_paths_with_d);
			debug_ln(*aux_paths_without_d);
			calc_paths(n - i, k, d, aux_paths_with_d, aux_paths_without_d);
			//debug_m(mem_paths_with_d);
			cout << "-----depois calc----" << endl;
			debug_ln(*aux_paths_with_d);
			debug_ln(*aux_paths_without_d);
		debug_ln(i);
		debug_ln(n);
		debug_ln(n - i);

			mem_paths_with_d[n - i][i] 		= *aux_paths_with_d;
			mem_paths_without_d[n - i][i]  	= *aux_paths_without_d;
		}

		// sum child subtree to current subtree
		if(i == d) 
		{
			cout << "i == d" << endl;
			debug_ln(aux_paths_with_d);
			debug_ln(aux_paths_without_d);
			debug_ln(*aux_paths_with_d + *aux_paths_without_d);
			debug_ln((*paths_with_d));

			(*paths_with_d) += *aux_paths_with_d + *aux_paths_without_d;
			//*paths_without_d += 0;
		}

			debug_ln((*paths_with_d));
			debug_ln((*paths_without_d));

	debug_m(mem_paths_with_d);	
	debug_m(mem_paths_without_d);	
		//debug_ln(i);
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

	ll paths_with_d, paths_without_d;
	calc_paths(n, k, d, &paths_with_d, &paths_without_d);

	debug_m(mem_paths_with_d);	
	debug_m(mem_paths_without_d);	

	return 0;
}