// https://codeforces.com/gym/102215/problem/E

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef long l;

struct sort_pair_vector {
    bool operator()(const pair<l,l> &p1, const pair<l,l> &p2) {
        if(p1.first != p2.first) return (p1.first < p2.first);
		return (p1.second < p2.second);
    }
};

int main()
{
	l n; // 1 ≤ n ≤ 200.000
	l m; // 1 ≤ m ≤ 10^9 

	cin >> n >> m;

	vector<pair<l, l>> libs;

	for (l i = 0; i < n; i++)
	{
		l min, max;
		cin >> min >> max;

		pair<l, l> lib(min, max);
		libs.push_back(lib);
	}
	
	sort(libs.begin(), libs.end(), sort_pair_vector());
	
	pair<l, l> first_lib = libs[0];
	l min = first_lib.first, max = first_lib.second;
	l last_min = min, last_max = max;

	l count = 1;
	bool last_had_intersec = false;

	for(pair<l, l> lib : libs) 
	{
		l new_min = lib.first, new_max = lib.second;

		if(new_min > max) // posterior ao maximo global
		{
			if(!last_had_intersec)
			{
				cout << "NO" << endl;
				return 0;
			}

			max = last_max;
			last_had_intersec = false;
			count++;
		}else
		{
			last_had_intersec = true;
		}

		if(min == 1 && (max == m || new_max == m))
		{
			cout << ++count << endl;
			return 0;
		}

		last_min = new_min;
		last_max = new_max;
	}

	return 0;
}