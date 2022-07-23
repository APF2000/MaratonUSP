// https://neps.academy/br/exercise/29

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }

#define MAX 9

vector<long> piano;
vector<vector<long>> tree;

void build(long id, long l, long r)
{
    if(l == r) // leaf
    {
        long pos = l;
        vector<long> note_count(MAX, 0);
        note_count[1] = 1;
        tree[id] = note_count; // id of most frequent element
        return;
    }

    long m = (l + r) / 2;
    long l_tree = 2 * id + 1, r_tree = 2 * id + 2;

    // build left and right subtress
    build(l_tree, l, m);
    build(r_tree, m + 1, r);

    vector<long> l_note_count = tree[l_tree];
    vector<long> r_note_count = tree[r_tree];

    for (long i = 0; i < MAX; i++)
    {
        tree[id][i] = l_note_count[i] + r_note_count[i];
    }
}

void update(long id, long l, long r, long ql, long qr, long max_note)
{
    if(qr < l || r < ql) return;

    if(l == r) // leaf
    {
        long pos = l;

        vector<long> aux_note_count = tree[id];
        vector<long> new_note_count = vector<long>(MAX);

        
        for (long note = 0; note < MAX; note++)
        {
            new_note_count[(note + max_note) % MAX] = aux_note_count[note];
        }

        tree[id] = new_note_count;

        long new_note = (piano[pos] + max_note) % MAX;
        piano[pos] = new_note;

        return;
    }

    long m = (l + r) / 2;
    long l_tree = 2 * id + 1, r_tree = 2 * id + 2;

    update(l_tree, l, m, ql, qr, max_note);
    update(r_tree, m + 1, r, ql, qr, max_note);

    vector<long> l_note_count = tree[l_tree];
    vector<long> r_note_count = tree[r_tree];

    for (long i = 0; i < MAX; i++)
    {
        tree[id][i] = l_note_count[i] + r_note_count[i];
    }
}

vector<long> query(long id, long l, long r, long ql, long qr)
{
    if(qr < l || r < ql) return vector<long>(MAX, 0);

    if(ql <= l && qr >= r) 
    {
        vector<long> note_count = tree[id];
        return note_count; 
    }

    long m = (l + r) / 2; 
    long l_tree = 2 * id + 1, r_tree = 2 * id + 2;

    vector<long> l_note_count = query(l_tree, l, m, ql, qr);
    vector<long> r_note_count = query(r_tree, m + 1, r, ql, qr);

    vector<long> aux_note_count(MAX, 0);
    for (long note = 0; note < MAX; note++)
    {
        aux_note_count[note] = l_note_count[note] + r_note_count[note];
    }

    return aux_note_count;
}

int main()
{
    long n, m;
    cin >> n >> m;

    piano = vector<long>(n, 1);
    tree = vector<vector<long>>(4 * n, vector<long>(MAX, 0));
    
    build(0, 0, n - 1);

    for (long i = 0; i < m; i++)
    {
        long a, b;
        cin >> a >> b;

        vector<long> note_count = query(0, 0, n - 1, a, b);

        long max_note, max_count = 0;
        for (long note = 0; note < MAX; note++)
        {
            long aux_count = note_count[note];
            if(aux_count >= max_count) 
            {
                max_count = aux_count;
                max_note = note;
            }
        }

        update(0, 0, n - 1, a, b, max_note);
    }    

    for (long i = 0; i < n; i++)
    {
        cout << piano[i] << endl;
    }    

	return 0;
}