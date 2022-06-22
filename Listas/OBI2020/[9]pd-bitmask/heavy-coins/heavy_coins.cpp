// https://codeforces.com/gym/100712/attachments/download/3454/acm-amman-collegiate-programming-contest-en.pdf
// https://codeforces.com/gym/100712

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;

int main()
{
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, value;
        cin >> n >> value;

        vector<int> coins(n);

        for (int j = 0; j < n; j++)
        {
            cin >> coins[i];

            cout << coins[i] << endl;
            
        }
    }
    

	return 0;
}