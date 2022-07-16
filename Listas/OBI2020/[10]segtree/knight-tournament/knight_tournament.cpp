// https://codeforces.com/contest/356/problem/A

#include <iostream>
#include <vector>
using namespace std;

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }


vector<bool> values, tree;
vector<long> bullys;

void build(long id, long l, long r)
{
    if(l == r)
    {
        tree[id] = values[l];
        return;
    }

    long m = (l + r) / 2;
    long l_tree = 2 * id + 1, r_tree = 2 * id + 2;

    // build left and right subtress
    build(l_tree, l, m);
    build(r_tree, m + 1, r);

    tree[id] = tree[l_tree] && tree[r_tree]; // all dead 
}

void update(long id, long l, long r, long ql, long qr, long winner)
{
    if(qr < l || r < ql) return;

    if(l == r)
    {
        long pos = l;
        bool result = (winner != pos); // reached round winner ?

        d(id);
        d(pos);
        d(winner);
        dln(result);

        tree[id] = result; 
        values[pos] = result; 
    
        dv(tree);

        return;
    }

    long m = (l + r) / 2;
    long l_tree = 2 * id + 1, r_tree = 2 * id + 2;
    
    dln(id);
    // d(ql);
    // dln(qr);
    // d(l_tree);
    // dln(r_tree);
    dv(tree);

    update(l_tree, l, m, ql, qr, winner);
    update(r_tree, m + 1, r, ql, qr, winner);
    tree[id] = tree[l_tree] && tree[r_tree]; // all dead ?
}

bool query(long id, long l, long r, long ql, long qr)
{
    if(ql <= l && qr >= r) return tree[id];
    if(qr < l || r < ql) return true;

    long m = (l + r) / 2; 
    long l_tree = 2 * id + 1, r_tree = 2 * id + 2;

    return query(l_tree, l, m, ql, qr) 
        && query(r_tree, m + 1, r, ql, qr); // al dead ?
}

int main()
{
    long n, m;
    cin >> n >> m;

    values = vector<bool>(n, false);
    tree = vector<bool>(4 * n, false);
    
    build(0, 0, n - 1);
    
    dv(values);
    dv(tree);

    for (long i = 0; i < m; i++)
    {
        long ql, qr, winner;
        cin >> ql >> qr >> winner;

        ql--; qr--; winner--;
        dln(ql);
        dln(qr);
        dln(winner);

        update(0, 0, n - 1, ql, qr, winner);
        dln("-----------------")
    }

    dv(bullys);
    

	return 0;
}