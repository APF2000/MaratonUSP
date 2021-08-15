// https://codeforces.com/gym/102215/problem/E

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long l;

class Container{
	public:
		l first, second, index;
		Container (l f, l s, l i)
		{
			first = f;
			second = s;
			index = i;
		}
		bool operator < (Container c) {
			if(first != c.first) return (first < c.first);
			return (second < c.second);
		}
		bool operator == (Container c) {
			return (first == c.first && second == c.second);
		}
};

int main()
{
	l n; // 1 ≤ n ≤ 200.000
	l m; // 1 ≤ m ≤ 10^9 

	cin >> n >> m;

	vector<Container> libs;
	long min_first = m, max_second = 0;

	for (l i = 0; i < n; i++)
	{
		l min, max;
		cin >> min >> max;

		Container lib(min, max, i);
		libs.push_back(lib);

		if(min < min_first) min_first = min;
		if(max > max_second) max_second = max;
	}
	
	sort(libs.begin(), libs.end());//, sort_container_vector());


	l index = 0;
	for(index = 0; index < n && libs[index].first == 1; index++);


	l count = 1;
	bool possible = (min_first == 1 && max_second == m);

	Container first_lib = libs[index - 1];
	vector<l> used_libs = { first_lib.index + 1 };

	l max = first_lib.second;

	for(l i = index; i < n && possible && max != m; i++) 
	{
		Container last = libs[i - 1];
		l best_index = i;
		for(; i < n && libs[i].first <= last.second; i++)
		{
			l aux_max = libs[i].second;
			if(aux_max > max)
			{
				max = aux_max;
				best_index = i;
			}
		}

		if(i == n) i = n - 1; // corrige se o FOR de cima passar do ultimo indice
		if(libs[i].first <= last.second && libs[i].second > libs[best_index].second) 
			best_index = i;
		Container next = libs[best_index];
	
	
		if(next == last) continue; // funciona para classes ? 

		if(last.second >= next.first - 1 && next.second > last.second) 
		{
			count++;
			used_libs.push_back(next.index + 1); // libs[0] => library #1
			max = next.second;
		}else{
			possible = false;
		}
	}


	//sort(used_libs.begin(), used_libs.end());


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