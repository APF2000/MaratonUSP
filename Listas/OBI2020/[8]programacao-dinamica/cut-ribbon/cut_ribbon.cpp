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
        for (int j = 0; j <= n / b; j++)
        {
            for (int k = 0; k <= n / c; k++)
            {
                int sum = i * a + j * b + k * c;
                if(sum == n)
                {
                    int ribbons = i + j + k;  
                    if(ribbons > max_ribbons) max_ribbons = ribbons;             
                }
            }
        }
    }

    cout << max_ribbons << endl;

	return 0;
}