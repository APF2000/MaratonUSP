// https://codeforces.com/gym/100712/attachments/download/3454/acm-amman-collegiate-programming-contest-en.pdf
// https://codeforces.com/gym/100712

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define BLANK 1e9

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }

int max_coins(vector<int>coins, int debt, int n, 
    unordered_set<int> used_coins, vector<vector<int>> &mem)
{
    // d(debt);
    // d(n);
    // dv(used_coins);
    //dm(mem);

    if(used_coins.size() == n) return 0;
    if(debt <= 0) return 0;

    int max_coins_qtty = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        bool was_used = (used_coins.find(i) != used_coins.end());
        if(!was_used)
        {
            int value = coins[i];
            int new_debt = debt - value;
            
            // dln(value);
            // dln(debt);
            // dln(i);
            // dm(mem);

            if(new_debt < 0) 
            {
                max_coins_qtty = 0;
                break;
            }
            
            int coins_qtty = mem[new_debt][i];

            if(coins_qtty == BLANK)
            {
                unordered_set<int> aux_used_coins = used_coins;
                aux_used_coins.insert(i);

                coins_qtty = max_coins(coins, debt - value, n, aux_used_coins, mem);
                mem[debt - value][i] = coins_qtty;
            }

            max_coins_qtty = max(max_coins_qtty, coins_qtty);
        }
    }    

    return max_coins_qtty + 1;
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

        vector<vector<int>> mem;
        for (int i = 0; i < debt; i++)
        {
            vector<int> aux;
            for (int j = 0; j < n; j++)
            {
                aux.push_back(BLANK);
            }      
                
            mem.push_back(aux);  
        }
        
        sort(coins.begin(), coins.end());

        int result = max_coins(coins, debt, n, {}, mem);

        cout << result << endl;
    }
    

	return 0;
}