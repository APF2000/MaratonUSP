// https://codeforces.com/problemset/problem/189/A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> ordered = {a, b, c};

    sort(ordered.begin(), ordered.end());
    a = ordered[0];
    b = ordered[1];
    c = ordered[2];
    
    bool possible = false;
    int max_ribbons = 0;

    for (int i = 0; i <= n / a; i++)
    {
        int q1 = i * a;
        for (int j = 0; j <= (n - q1) / b; j++)
        {
            int q2 = j * b;
            int rest_n = n - q1 - q2;

            // sum cant fill ribbons
            if(rest_n % c != 0) continue;

            int k = (rest_n / c);
            // debug(i);
            // debug(j);
            // debug(k);

            int ribbons = i + j + k;  
            if(ribbons > max_ribbons) max_ribbons = ribbons;          
        }
    }

    cout << max_ribbons << endl;

	return 0;
}