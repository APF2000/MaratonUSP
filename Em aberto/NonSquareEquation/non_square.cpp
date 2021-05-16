//https://codeforces.com/problemset/problem/233/B
#include <iostream>
#include <vector>
#include <map>

#define UNDEF -1
#define MAX_SIZE 1000 * 1000 * 1000 // 10 ** 9

using namespace std;

int s(int x)
{
    int base = 10, sum = 0;
    int x_orig = x;
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
            //cout << "Já tinha calculado: digsum[" << x << "] = " << dig_sum[x] << endl; 
            break;
        }
        
        sum += ( x % base );
        x = x / base;
    }
    dig_sum[x_orig] = sum;
    return sum;
}

int formula(int x)
{
    return ( x + s(x) ) * x;
}

int main()
{
    long long int n; 
    cin >> n;
    cout << "Numero recebido: " << n << endl;
    //vector<int> calcs;
    //for(int i = 0; i < MAX_SIZE; i++) calcs.push_back(UNDEF);
    // map<int, int> dig_sum;
    // dig_sum[1] = 1;
    // dig_sum[2] = 2;
    // cout << "DIgsum[1]: " <<  dig_sum[1] << endl;
    // if(dig_sum.find(2) != dig_sum.end()) cout << "Tem o 2" << endl;

    for(int i = 0; i * i < n; i++)
    {
        if(formula(i) == n)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    //cout << INF << endl;
    //cout << calcs[0] << endl;

    return 0;
}