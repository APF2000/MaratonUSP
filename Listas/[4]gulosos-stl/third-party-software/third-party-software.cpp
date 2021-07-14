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
	for(pair<l, l> lib : libs) cout << lib.first << " " << lib.second << endl;

	return 0;
}