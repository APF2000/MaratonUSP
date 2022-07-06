// https://neps.academy/br/exercise/327

#include <iostream>
#include <vector>
using namespace std;

#define BLANK 1e9
#define INVALID -1

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }

vector<int>coins

int query(int id, int l, int r, int ql, int qr)
{
    if(ql <= l && qr >= r) return [id];
    if(qr < l || r < ql) return 0;

    int m = (l + r) / 2; 

    return query(2 * id, l, m, ql, qr) 
        * query(2 * id + 1, m, r, ql, qr);
}

int main()
{
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
    }
    

	return 0;
}