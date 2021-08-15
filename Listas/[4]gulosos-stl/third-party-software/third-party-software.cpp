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

	for (l i = 0; i < n; i++)
	{
		l min, max;
		cin >> min >> max;

		Container lib(min, max, i);
		libs.push_back(lib);
	}
	
	sort(libs.begin(), libs.end());
	
	vector<l> used_libs;
	bool possible = true;
	l count = 1;

	for(l i = 0; i < n; i++) 
	{
	
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