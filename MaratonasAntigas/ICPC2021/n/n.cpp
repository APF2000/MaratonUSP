#include <bits/stdc++.h>

using namespace std;

int main()
{
	long Y, N, xi, azar = 0;
	vector<long> x;
	cin >> Y >> N;
	//cout << "ok1 " << endl;
	for(long i = 0; i < Y; i++){
		cin >> xi;
		//cout << "xi = " << xi << endl;
		x.push_back(xi);
		//cout << "ok2 " << endl;
	}
	for(long i = 0; i < N; i++){
		long a, p, f;
		cin >> a;
		cin >> p;
		cin >> f;
		//cout << "a = " << a << endl;
		//cout << "f = " << f << endl;
		//cout << "a+f= " << a+f << endl;
		for(long j = a; j < a+f; j++){
			//cout << "j = " << j << " x[j] = " << x[j] << endl;
			//cout << "x[j]-p " << x[j] - p << endl;
			if(x[j]-p >= 0) azar++;
		}
		if(x[a-1]-p >= 0){
			azar = 0;
		}
		cout << azar << endl;
		azar = 0;	
	}
	return 0;
}