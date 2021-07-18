// https://codeforces.com/gym/102215/problem/E

#include <iostream>
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
	long min_first = m, max_second = 0;

	for (l i = 0; i < n; i++)
	{
		l min, max;
		cin >> min >> max;

		tuple<l, l, l> lib(min, max, i);
		libs.push_back(lib);

		if(min < min_first) min_first = min;
		if(max > max_second) max_second = max;
	}
	
	sort(libs.begin(), libs.end(), sort_tuple_vector());


	l index = 0;
	for(index = 0; index < n && get<0>(libs[index]) == 1; index++);


	l count = 1;
	bool possible = (min_first == 1 && max_second == m);

	tuple<l, l, l> first_lib = libs[index - 1];
	vector<l> used_libs = { get<2>(first_lib) + 1 };

	l max = get<1>(first_lib);

	for(l i = index; i < n && possible && max != m; i++) 
	{
		tuple<l, l, l> last = libs[i - 1];
		l best_index = i;
		for(; i < n && get<0>(libs[i]) <= get<1>(last); i++)
		{
			l aux_max = get<1>(libs[i]);
			if(aux_max > max)
			{
				max = aux_max;
				best_index = i;
			}
		}
		if(i == n) i = n - 1;
		if(get<1>(libs[i]) > get<1>(libs[best_index])) best_index = i;
		tuple<l, l, l> next = libs[best_index];
	
	
		if(next == last) continue; // funciona para tuplas ? 

		if(get<1>(last) >= get<0>(next) - 1 && get<1>(next) > get<1>(last)) 
		{
			count++;
			used_libs.push_back(get<2>(next) + 1); // libs[0] => library #1
			max = get<1>(next);
		}else{
			possible = false;
		}
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