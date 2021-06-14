#include <bits/stdc++.h>

using namespace std;

long binom(long n)
{
    return (1 << n) - 1;
}

long sum_sets(vector<vector<long>> mt, int n, int m)
{
    long sum = 0;

    for (vector<long> v : mt)
    {
        long pow1 = 0, pow2 = 0;

        for (int j = 0; j < m; j++)
        {
            if(v[j] == 0) pow1 += 1;
            else pow2 += 1;
        }

        sum += (binom(pow1) + binom(pow2));

        cout << pow1 << " + " << pow2 << " === " << pow1 + pow2 << endl;
    }
    return sum;
}

void transpose(vector<vector<long>> *mt, int n, int m)
{
    vector<vector<long>> maux;
    vector<long> vaux(n);
    for (int j = 0; j < m; j++) maux.push_back(vaux);

    for (int i = 0; i < n; i++)
    {
        vector<long> vaux;
        for (int j = 0; j < m; j++)
        {
            maux[j][i] = (*mt)[i][j];
        }
    }

    (*mt) = maux;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long>> mt;

    for (int i = 0; i < n; i++)
    {
        vector<long> vaux;

        for (int j = 0; j < m; j++)
        {
            long aux;
            cin >> aux;
            vaux.push_back(aux);
        }
        mt.push_back(vaux);
    }

    long sum = 0;

    sum += sum_sets(mt, n, m);
    transpose(&mt, n, m);
    sum += sum_sets(mt, m, n);

    sum -= (m * n);

    cout << sum << endl;

    return 0;
}