// https://codeforces.com/problemset/problem/908/C

#include <iostream>
#include <vector>
using namespace std;

#define CHANGE 'C'
#define PROD 'P'

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }

int main()
{
    int n, r;
    cin >> n >> r;

    vector<int> xs(n);
    vector<double> ys(n);

    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
    }

    dv(xs);
    

	return 0;
}