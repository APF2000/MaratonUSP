#include <bits/stdc++.h>

using namespace std;

int main()
{
	long t, d, m;
	long last = 0;

	cin >> t >> d >> m;
		
	long next;

	for (long i = 0; i < m; i++)
	{
		cin >> next;
		if(next - last >= t)
		{
			cout << "Y" << endl;
			return 0;
		}

		last = next;
	}
	
	next = d;

	if(next - last >= t)
	{
		cout << "Y" << endl;
		return 0;
	}

	cout << "N" << endl;
	return 0;
}
