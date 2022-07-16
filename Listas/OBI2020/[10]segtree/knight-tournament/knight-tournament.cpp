// https://codeforces.com/contest/356/problem/A

#include <iostream>
#include <vector>
using namespace std;

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


	return 0;
}