//https://codeforces.com/problemset/problem/233/B
#include <iostream>
#include <vector>
#include <map>

#define UNDEF -1
#define MAX_SIZE 1000 * 1000 * 1000 // 10 ** 9

using namespace std;

typedef long long ll;

int s(ll x)
{
    int base = 10, sum = 0;
    ll x_orig = x;
    /*static int last_x;
    cout << "Last X: " << last_x;
    cout << "; New X: " << x << endl;
    last_x = x;*/
    static map<int, int> dig_sum;

    while(x != 0)
    {
        if(dig_sum.find(x) != dig_sum.end())
        {
            sum += dig_sum[x];
            cout << "Já tinha calculado: digsum[" << x << "] = " << dig_sum[x] << endl; 
            break;
        }
        sum += ( x % base );
        x = x / base;
    }
    dig_sum[x_orig] = sum;
    return sum;
}

ll formula(ll x)
{
    return ( x + s(x) ) * x;
}

ll solve(ll lower, ll upper)
{

}

int main()
{
    ll n; 
    cin >> n;
    cout << "Numero recebido: " << n << endl;

    // for(ll i = 0; i * i < n; i += 10)
    // {
    //     ll lower = i;
    //     ll upper = i + 9;

    //     cout << "Formula(" << i << ") = " << formula(i) << endl;


    //     if(formula(lower) <= n && formula(upper) >= n)
    //     {
    //         for(ll j = lower; j < upper; j++)
    //         {
    //             if(formula(j) == n)
    //             {
    //                 cout << j << endl;
    //                 return 0;
    //             }
    //         }
    //     }
    // }

    cout << -1 << endl;

    //cout << INF << endl;
    //cout << calcs[0] << endl;

    return 0;
}