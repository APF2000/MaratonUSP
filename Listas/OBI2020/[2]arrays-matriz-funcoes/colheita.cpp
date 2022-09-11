#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    int s = 0; // cenouras
    vector<vector<int>> m;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> vaux;
        for (int j = 0; j < n; j++)
        {
            int aux;
            cin >> aux;
            vaux.push_back(aux);
        }
        m.push_back(vaux);
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int li, ci, lf, cf;
        cin >> li >> ci >> lf >> cf;
        li--;
        ci--;
        lf--;
        cf--;

        for (int j = li; j <= lf; j++)
        {        
            for (int k = ci; k <= cf; k++)
            {
                s += m[j][k];
                m[j][k] = 0;
            }
        }
    }

    cout << s << endl;

    return 0;
}