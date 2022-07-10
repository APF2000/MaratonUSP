// https://neps.academy/br/exercise/327

#include <iostream>
#include <vector>
using namespace std;

#define CHANGE 'C'
#define PROD 'P'

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }


vector<int> values, tree;

void build(int id, int l, int r)
{
    if(l == r)
    {
        tree[id] = values[l];
    }
    else
    {
        int m = (l + r) / 2;
        build(2 * id, l, m);
        build(2 * id + 1, m + 1, r);
        tree[id] = tree[2 * id] * tree[2 * id + 1];    
    }
}

void update(int id, int l, int r, int ql, int qr, int value)
{
    if(ql <= l && r <= qr)
    {
        tree[id] = value; // verificar
        return;
    }

    if(qr < l || ql > r) return;

    int m = (l + r) / 2;
    update(2 * id, l, m, ql, qr, value);
    update(2 * id + 1, m, r, ql, qr, value);
}

int query(int id, int l, int r, int ql, int qr)
{
    if(id >= values.size()) return 1;

    if(ql <= l && qr >= r) return values[id];
    if(qr < l || r < ql) return 1;

    int m = (l + r) / 2; 

    return query(2 * id, l, m, ql, qr) 
        * query(2 * id + 1, m, r, ql, qr);
}

int main()
{
    long n, k;

    while(cin >> n >> k)
    {
        values = vector<int>(n + 1, 1);
        tree = vector<int>(4 * (n + 1), 1);
        long prod = 1;

        for (long i = 0; i < n; i++)
        {
            // int aux;
            // cin >> aux;
            cin >> values[i];
            //values.push_back(aux);
        }

        //dv(tree);
        dv(values);
        build(0, 0, n - 1);
        dv(tree);
        
        for (long i = 0; i < k; i++)
        {

            char cmd;
            cin >> cmd;
            if(cmd == CHANGE)
            {
                long id;
                int value;

                cin >> id >> value;

                update(id, 1, n - 1, 1, n - 1, value);

                //dv(tree);

                //values[id - 1] = value;
            
                //dv(values);

                // cout << query(0, 1, n - 1, 1, 3) << endl;
                // cout << query(0, 1, n - 1, 0, values.size()-1) << endl;
                // cout << query(0, 1, n - 1, 0, 2) << endl;
            }
            else if(cmd == PROD)
            {
                long id;
                int value;

                cin >> id >> value;
            }
        }
        
    } 

	return 0;
}