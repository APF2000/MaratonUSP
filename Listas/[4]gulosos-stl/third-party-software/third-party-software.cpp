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
	
	//pair<l, l> first_lib = libs[0];
	//l glob_min = first_lib.first, glob_max = first_lib.second;
	//l last_min = glob_min, last_max = glob_max;

	if(glob_min != 1)
	{
		cout << "NO1" << endl;
		return 0;
	}

	l count = 1;
	//bool last_had_intersec = false;
	//l last_index = m - 1;

	for(int i = 1; i < n; i++) 
	{
		pair<l, l> last = libs[i - 1];
		//int j = i;
		for(; i < n && libs[i].first <= last.second; i++);
		pair<l, l> next = libs[i];
		//i = j;
		//if(i == j);
		if(next == last) continue; // testar linha 
		//if(next.first == last.first && next.second == last.second) continue;

		if(last.second < next.first) count++;

		//l new_max;
		/*if()
		//if(i != n - 1) new_max = libs[i - 1].second;
		//else new_max = libs[i].second;

		if(new_max <= glob_max)
		{
			cout << "NO2" << endl;
			return 0;
		}else{
			glob_max = new_max;
			count++;
		}*/
	}

	if(glob_max == m) cout << "YES" << endl;
	else cout << "NO3" << endl;

	return 0;
}