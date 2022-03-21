#include <bits/stdc++.h>

using namespace std;

struct bloco{
	long cor;
	long num;
};

bool ordem(bloco b1, bloco b2)
{
	return (b1.num < b2.num);
}

int main()
{
	long n, k;
	cin >> n >> k;

	vector<bloco> original, sortado;
	//cout << "n : " << n << endl;

	for (long i = 0; i < n; i++)
	{
		long ni, ci;
		cin >> ni >> ci;

		bloco b;
		b.cor = ci;
		b.num = ni;

		//cout << b.num << ", " << b.cor << endl;

		original.push_back(b);
	}

	sortado = original;
	sort(sortado.begin(), sortado.end(), ordem);
	//cout << "n : " << n << endl;

	for (long i = 0; i < n; i++)
	{	
		// cout << sortado[i].num << ", " << sortado[i].cor << endl;	
		// cout << original[i].num << ", " << original[i].cor << endl;	
		if(sortado[i].cor != original[i].cor)
		{
			cout << "N" << endl;
			return 0;
		}
	}

	cout << "Y" << endl;

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
	return 0;
}
