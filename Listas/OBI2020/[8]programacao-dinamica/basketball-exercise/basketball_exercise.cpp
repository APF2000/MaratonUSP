// https://codeforces.com/contest/1195/problem/C

// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;

int main()
{
	ll n;
	cin >> n;

	vector<ll> row1, row2;
	for (ll i = 0; i < n; i++)
	{
		ll h;
		cin >> h;
		row1.push_back(h);
	}

	for (ll i = 0; i < n; i++)
	{
		ll h;
		cin >> h;
		row2.push_back(h);
	}

	ll max_glob_row1 = 0, max_glob_row2 = 0;
	ll max_prev_row1 = 0, max_prev_row2 = 0;
	//ll max_prev_prev_row1 = 0, max_prev_prev_row2 = 0;

	for (ll i = n - 1; i >= 0; i--)
	{
		ll h1 = row1[i], h2 = row2[i];

		vector<ll> v1 = {max_glob_row2, max_prev_row2, max_prev_row1};
		vector<ll> v2 = {max_glob_row1, max_prev_row2, max_prev_row1};

		ll new_max_row1 = h1 + *max_element(v1.begin(), v1.end());
		ll new_max_row2 = h2 + *max_element(v2.begin(), v2.end());

		max_prev_row1 = max_glob_row1;
		max_prev_row2 = max_glob_row2;

		max_glob_row1 = new_max_row1;
		max_glob_row2 = new_max_row2;
	}

	cout << max(max_glob_row1, max_glob_row2) << endl;

	return 0;
}
