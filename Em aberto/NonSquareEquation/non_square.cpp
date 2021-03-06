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
    static map<int, int> dig_sum;

    while(x != 0)
    {
        if(dig_sum.find(x) != dig_sum.end())
        {
            sum += dig_sum[x];
            //cout << "Já tinha calculado: digsum[" << x << "] = " << dig_sum[x] << endl; 
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

ll solve(ll lower, ll upper, ll n)
{
    if(lower >= upper){
        cout << "lower>=upper" << endl;
        return UNDEF;
    }

    if(upper - lower <= 10)
    {
        cout << "upper-lower < 10" << endl;
        for(ll x = lower; x <= upper; x++)
        {
            if(formula(x) == n)
            {
                return x;
            }
        }
        return UNDEF;
    }

    // pegar numero que acaba em 9
    ll middle = 10 * ((upper + lower) / 20) - 1; 

    ll f_lower = formula(lower);
    ll f_upper = formula(upper);
    ll f_middle = formula(middle);
    //cout << "Formula(" << middle << ") = " << f_middle << endl;
    
    if(f_lower == n) return lower;
    if(f_upper == n) return upper;

    if(f_middle <= n) return solve(middle, upper - 1, n);
    // esse +10 é para garantir convergência
    else return solve(lower + 1, middle + 10, n); 
}

int main()
{
    //echo 1000 1000000 | time -o stats.txt -v ./a.out >> stats.txt && grep -i max stats.txt
    ll n; 
    cin >> n;

    cout << solve(0, MAX_SIZE, n) << endl;
    for(ll x=99999959; x < 100000050; x++) cout << "formula(" << x << ") = " << formula(x) << endl;
    
    // ll lower, upper;
    // cin >> lower >> upper;
    // for(ll x=lower; x < upper; x++) cout << "formula(" << x << ") = " << formula(x) << endl;

    return 0;
}