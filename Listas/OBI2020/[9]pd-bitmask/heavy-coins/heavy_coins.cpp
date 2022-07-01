// https://codeforces.com/gym/100712/attachments/download/3454/acm-amman-collegiate-programming-contest-en.pdf
// https://codeforces.com/gym/100712

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <bitset>

using namespace std;

#define BLANK 1e9
#define INVALID -1

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }

int max_coins(vector<int>coins, int debt, int n)
{
    int result = 0;

    for (int i = 0; i < (1 << n); i++)
    {
        int value_sum = 0, lowest_coin = 0, qtty_sum = 0;

        for (int aux_num = i, j = n - 1; aux_num > 0; aux_num /= 2, j--)
        {
            bool should_use_coin = (aux_num % 2 == 1);
            if(should_use_coin)
            {
                int this_coin = coins[j];
                lowest_coin = this_coin;
                value_sum += this_coin;
                qtty_sum += 1;
            }
        }

        bool is_max_coins_case = qtty_sum > result;
        bool is_exact_debt = value_sum == debt;
        bool cant_remove_excess = (value_sum > debt && value_sum - lowest_coin < debt);

        if( is_max_coins_case && ( is_exact_debt || cant_remove_excess ) )
        {
            result = qtty_sum;
        }
    }

    return result;
}

int main()
{
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, debt;
        cin >> n >> debt;

        vector<int> coins(n);

        for (int j = 0; j < n; j++)
        {
            cin >> coins[j];  
        }
        
        sort(coins.begin(), coins.end());

        int result = max_coins(coins, debt, n);

        cout << result << endl;
    }
    

	return 0;
}