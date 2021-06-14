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
        //bool zpass = true;
        bool is_first = true;
        long v_first = 0;

        long pow = 1;
        vector<long> sums;
        for (int j = 0; j < m; j++)
        {
            if(v[j] == v[(j + 1 + m) % m]) {
                if(j == m - 1)
                { 
                    pow += v_first;
                    sums.push_back(binom(pow));
                }else pow++; 
            }else
            {
                if(is_first) 
                {
                    v_first = pow;
                    is_first = false;
                    if(v[j] != v[m - 1]) sums.push_back(binom(pow));
                }else{
                    sums.push_back(binom(pow));
                }
                pow = 1;
            }
        }

        for(long s : sums) {
            sum += s;
            cout << s << " + ";
        }
        cout << " === " << sum << endl;
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