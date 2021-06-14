#include <bits/stdc++.h>

using namespace std;

int binom(int n)
{
    return (1 << n) - 1;
}

int sum_sets(vector<vector<int>> mt, int n, int m)
{
    int sum = 0;

    for (vector<int> v : mt)
    {
        //bool zpass = true;
        bool is_first = true;
        int v_first = 0;

        int pow = 1;
        vector<int> sums;
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

        for(int s : sums) sum += s;
        cout << sum << endl;
    }
}

void transpose(vector<vector<int>> *mt, int n, int m)
{
    vector<vector<int>> maux;
    vector<int> vaux(n);
    for (int j = 0; j < m; j++) maux.push_back(vaux);

    for (int i = 0; i < n; i++)
    {
        vector<int> vaux;
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

    vector<vector<int>> mt;

    for (int i = 0; i < n; i++)
    {
        vector<int> vaux;

        for (int j = 0; j < m; j++)
        {
            int aux;
            cin >> aux;
            vaux.push_back(aux);
        }
        mt.push_back(vaux);
    }

    int sum = 0;

    sum += sum_sets(mt, n, m);
    transpose(&mt, n, m);
    sum += sum_sets(mt, m, n);

    return 0;
}