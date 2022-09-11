// https://codeforces.com/problemset/problem/908/C

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define CHANGE 'C'
#define PROD 'P'

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }

int main()
{
    int n, r;
    cin >> n >> r;

    vector<int> xs(n);
    vector<double> ys(n);

    cout.precision(20);

    for (int i = 0; i < n; i++)
    {
        int new_x;
        cin >> new_x;
        xs[i] = new_x;

        double new_y = r;
        for (int j = 0; j < i; j++)
        {
            int old_x = xs[j];
            int delta_x = new_x - old_x;

            double old_y = ys[j];

            double aux_new_y = old_y + sqrt(4 * r * r - delta_x * delta_x);
            if(aux_new_y > new_y) new_y = aux_new_y;
        }        

        ys[i] = new_y;
        cout << ys[i] << " ";
    }    

    cout << endl;

	return 0;
}