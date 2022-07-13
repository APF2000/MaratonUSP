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
        return;
    }

    int m = (l + r) / 2;
    int l_tree = 2 * id + 1, r_tree = 2 * id + 2;

    // build left and right subtress
    build(l_tree, l, m);
    build(r_tree, m + 1, r);

    tree[id] = tree[l_tree] * tree[r_tree];  
    // d(id);
    // d(l);
    // dln(r);
    // dv(tree);
}

void update(int id, int l, int r, int pos, int value)
{
    if(l == r)
    {
        tree[id] = value; 
        values[pos] = value; 
        return;
    }

    int m = (l + r) / 2;
    int l_tree = 2 * id + 1, r_tree = 2 * id + 2;

    if(pos <= m) update(l_tree, l, m, pos, value);
    else update(r_tree, m + 1, r, pos, value);
    tree[id] = tree[l_tree] * tree[r_tree];
}

int query(int id, int l, int r, int ql, int qr)
{
    //if(id >= values.size()) return 1;

    if(ql <= l && qr >= r) return tree[id];
    if(qr < l || r < ql) return 1;

    int m = (l + r) / 2; 
    int l_tree = 2 * id + 1, r_tree = 2 * id + 2;

    return query(l_tree, l, m, ql, qr) 
        * query(r_tree, m + 1, r, ql, qr);
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

        dln(query(0, 0, n - 1, 0, 1));
        dln(query(0, 0, n - 1, 3, 4));
        dln(query(0, 0, n - 1, 0, 4));
        dln(query(0, 0, n - 1, 1, 3));
        dln(query(0, 0, n - 1, 1, 1));
        
        for (long i = 0; i < k; i++)
        {

            char cmd;
            cin >> cmd;
            if(cmd == CHANGE)
            {
                long pos;
                int value;

                dln("CHANGE");

                cin >> pos >> value;
                pos--;
                d(pos); dln(value);

                update(0, 0, n - 1, pos, value);

                dv(values);

                //values[id - 1] = value;
            
                //dv(values);

                // cout << query(0, 1, n - 1, 1, 3) << endl;
                // cout << query(0, 1, n - 1, 0, values.size()-1) << endl;
                // cout << query(0, 1, n - 1, 0, 2) << endl;
            }
            else if(cmd == PROD)
            {
                long i, j;
                dln("PROD");

                cin >> i >> j;
                i--, j--;
                d(i); dln(j);

                dln(query(0, 0, n - 1, i, j));
            }
        }
        
    } 

	return 0;
}