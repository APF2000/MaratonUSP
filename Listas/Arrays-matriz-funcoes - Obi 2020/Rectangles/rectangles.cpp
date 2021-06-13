#include <bits/stdc++.h>

using namespace std;

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

    return 0;
}