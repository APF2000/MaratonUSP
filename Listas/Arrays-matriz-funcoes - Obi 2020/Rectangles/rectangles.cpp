#include <bits/stdc++.h>

using namespace std;

int binom(int n)
{
    return (1 << n) - 1;
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
            /*if(j == 0 && v[0] == v[m - 1]) zpass = false;
            else
            {
                pow++;
                if(j == m - 1){
                    if(!zpass) pow++;
                    sum += binom(pow);
                }else
                {

                }
            }*/
        }

        for(int s : sums) sum += s;
        cout << sum << endl;
    }



    return 0;
}