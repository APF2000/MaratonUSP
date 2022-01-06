// link

// #include <bits/stdc++.h>

#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) for(auto el : v) cout << el << ", "; cout << endl;

#include <iostream>

void debug_q(queue<int> q)
{
	while(q.size() != 0)
	{
		int el = q.front();
		q.pop();

		cout << el << ", ";
	}
	cout << endl;
}

using namespace std;

int main()
{
	return 0;
}
