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
        bool is_not_round_winner = (winner != pos); // reached round winner ?

        tree[id] = is_not_round_winner; 
        values[pos] = is_not_round_winner; 

        if(is_not_round_winner) bullys[pos] = winner + 1; // 1-based index

        return;
    }

    long m = (l + r) / 2;
    long l_tree = 2 * id + 1, r_tree = 2 * id + 2;
    bool l_all_dead = tree[l_tree], r_all_dead = tree[r_tree];

    if(!l_all_dead) update(l_tree, l, m, ql, qr, winner);
    if(!r_all_dead) update(r_tree, m + 1, r, ql, qr, winner);

    // obs: get tree again, because now it's been updated
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
    bullys = vector<long>(n);
    
    build(0, 0, n - 1);

    for (long i = 0; i < m; i++)
    {
        long ql, qr, winner;
        cin >> ql >> qr >> winner;

        ql--; qr--; winner--;

        update(0, 0, n - 1, ql, qr, winner);
    }    

    for (long i = 0; i < n; i++)
    {
        cout << bullys[i] << " ";
    }
    cout << endl;
    

	return 0;
}