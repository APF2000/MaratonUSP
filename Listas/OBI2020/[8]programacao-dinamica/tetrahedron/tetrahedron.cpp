// https://codeforces.com/problemset/problem/166/E

// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;

typedef unsigned long ul;

ul calc_moves(ul n)
{
	vector<ul> paths_from_d, paths_from_not_d;

	for (long i = 0; i < n; i++)
	{
		paths_from_d.push_back(0);
		paths_from_not_d.push_back(0);
	}

	paths_from_d[0] = 0;
	paths_from_not_d[0] = 1;

	for (ul i = 1; i < n; i++)
	{
		ul qtty_not_d = paths_from_not_d[i - 1];
		ul qtty_d = paths_from_d[i - 1];

		paths_from_d[i] 	= (3 * qtty_not_d) % MOD;
		paths_from_not_d[i] = (qtty_d + 2 * qtty_not_d) % MOD;
	}

	return paths_from_d[n - 1];
}

int main()
{
	ul n;
	cin >> n;

	ul result = calc_moves(n);
	cout << result << endl;

	return 0;
}
