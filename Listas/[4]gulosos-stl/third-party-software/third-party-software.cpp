// https://codeforces.com/gym/102215/problem/E

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long l;

class Container{
	public:
		l fst, snd, idx;
		Container (l f, l s, l i)
		{
			fst = f;
			snd = s;
			idx = i;
		}
		bool operator < (Container c) {
			if(fst != c.fst) return (fst < c.fst);
			return (snd < c.snd);
		}
		bool operator == (Container c) {
			return (fst == c.fst && snd == c.snd);
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
	l count = 0;

	Container maior(0, 0, 0);
	for(l i = 0; i < n && maior.snd != m; i++) 
	{
		std::cout << "[INFO] teste" << endl;
		Container last = libs[i];
		Container next(0, 0, 0);

		if(i == n - 1) next = maior;
		else next = libs[i + 1];

		if(last.fst == next.fst)
		{	// ja ta ordenado, entao se ta na frente eh maior necessariamente
			maior = next; 
		}else{
			if(last.snd < next.fst - 1)
			{
				possible = false;
				break;
			}else{
				// Pensar neste exemplo:
				// 1 2
				// 1 3
				// 1 10
				// 11 15
				// 11 17
				// 11 20
				used_libs.push_back(maior.idx + 1);
				count++;

				maior = next;
			}
		}
	}

	std::cout << (possible ? "YES" : "NO") << endl;
	if(possible) 
	{
		std::cout << count << endl;
		for(long lib : used_libs)
		{
			std::cout << lib << " ";
		}
		std::cout << endl;
	}

	return 0;
}