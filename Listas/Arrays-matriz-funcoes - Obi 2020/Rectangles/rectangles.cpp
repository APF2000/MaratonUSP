#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll binom(ll n)
{
    return ((ll) 1 << n) - 1;
}

ll sum_sets(vector<vector<ll>> mt, int n, int m)
{
    ll sum = 0;

    for (vector<ll> v : mt)
    {
        ll pow1 = 0, pow2 = 0;

        for (int j = 0; j < m; j++)
        {
            if(v[j] == 0) pow1 += 1;
            else pow2 += 1;
        }

        sum += (binom(pow1) + binom(pow2));
    }

    return sum;
}

void transpose(vector<vector<ll>> *mt, int n, int m)
{
    vector<vector<ll>> maux;
    vector<ll> vaux(n);
    for (int j = 0; j < m; j++) maux.push_back(vaux);

    for (int i = 0; i < n; i++)
    {
        vector<ll> vaux;
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

    vector<vector<ll>> mt;

    for (int i = 0; i < n; i++)
    {
        vector<ll> vaux;

        for (int j = 0; j < m; j++)
        {
            ll aux;
            cin >> aux;
            vaux.push_back(aux);
        }
        mt.push_back(vaux);
    }

    ll sum = 0;

    sum += sum_sets(mt, n, m);
    transpose(&mt, n, m);
    sum += sum_sets(mt, m, n);

    sum -= (m * n);

    cout << sum << endl;

    return 0;
}