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
    int ribbons = 0;

    for (int i = 0; i <= n / c && !possible; i++)
    {
        for (int j = 0; j <= n / b && !possible; j++)
        {
            for (int k = 0; k <= n / a && !possible; k++)
            {
                int sum = i * c + j * b + k * a;
                if(sum == n)
                {
                    possible = true;
                    ribbons = i + j + k;               
                }
            }
        }
    }

    cout << ribbons << endl;

	return 0;
}