// https://codeforces.com/gym/102215/problem/E

#include <iostream>
//#include <utility>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef long l;

struct sort_tuple_vector {
    bool operator()(const tuple<l,l,l> &t1, const tuple<l,l,l> &t2) {
		l t1f = get<0>(t1), t1s = get<1>(t1);
		l t2f = get<0>(t2), t2s = get<1>(t2);
        if(t1f != t2f) return (t1f < t2f);
		return (t1s < t2s);
    }
};

int main()
{
	l n; // 1 ≤ n ≤ 200.000
	l m; // 1 ≤ m ≤ 10^9 

	cin >> n >> m;

	vector<tuple<l, l, l>> libs;

	for (l i = 0; i < n; i++)
	{
		l min, max;
		cin >> min >> max;

		tuple<l, l, l> lib(min, max, i);
		libs.push_back(lib);
	}
	
	sort(libs.begin(), libs.end(), sort_tuple_vector());
	
	//tuple<l, l> first_lib = libs[0];
	//l glob_min = first_lib.first, glob_max = first_lib.second;
	//l last_min = glob_min, last_max = glob_max;

	/*if(glob_min != 1)
	{
		cout << "NO1" << endl;
		return 0;
	}*/

	l count = 1;
	//bool last_had_intersec = false;
	//l last_index = m - 1;
	l first_el = get<0>(libs[0]), last_el = get<1>(libs[n - 1]);
	bool possible = (first_el == 1 && last_el == m);

	l index = 0;
	for(index = 0; index < n && get<0>(libs[index]) == 1; index++);

	tuple<l, l, l> first_lib = libs[index - 1];

	vector<l> used_libs = { get<2>(first_lib) + 1 };

	l min = get<0>(first_lib), max = get<1>(first_lib);

	for(l i = index; i < n && possible && max != m; i++) 
	{
		tuple<l, l, l> last = libs[i - 1];
		//int j = i;
		for(; i < n && get<0>(libs[i]) <= get<1>(last); i++);
		if(i == n) i = n - 1;
		tuple<l, l, l> next = libs[i];
		//i = j;
		//if(i == j);
		if(next == last) continue; // testar linha 
		//if(next.first == last.first && next.second == last.second) continue;

		if(get<1>(last) <= get<0>(next)) 
		{
			count++;
			used_libs.push_back(get<2>(next) + 1); // libs[0] => library #1
			max = get<1>(next);
		}else{
			possible = false;
			//break;
		}

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

	cout << (possible ? "YES" : "NO") << endl;
	if(possible) 
	{
		cout << count << endl;
		for(long lib : used_libs)
		{
			cout << lib << " ";
		}
		cout << endl;
	}

	return 0;
}