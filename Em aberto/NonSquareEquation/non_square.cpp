//https://codeforces.com/problemset/problem/233/B
#include <iostream>
#include <vector>
#include <map>

#define UNDEF -1
#define MAX_SIZE 1000 * 1000 * 1000 // 10 ** 9

using namespace std;

int s(long long int x)
{
    int base = 10, sum = 0;
    long long int x_orig = x;
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

long long int formula(long long int x)
{
    return ( x + s(x) ) * x;
}

int main()
{
    long long int n; 
    cin >> n;
    cout << "Numero recebido: " << n << endl;

    // for(long long int i = 0; i * i < n; i += 10)
    // {
    //     long long int lower = i;
    //     long long int upper = i + 9;

    //     cout << "Formula(" << i << ") = " << formula(i) << endl;


    //     if(formula(lower) <= n && formula(upper) >= n)
    //     {
    //         for(long long int j = lower; j < upper; j++)
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