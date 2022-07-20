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
        note_count[0] = 1;
        tree[id] = note_count; // id of most frequent element
        //piano[l];
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

void update(long id, long l, long r, long ql, long qr, long add_value)
{
    if(qr < l || r < ql) return;

    if(l == r) // leaf
    {
        long pos = l;
        // bool is_not_round_winner = (winner != pos); // reached round winner ?

        // tree[id] = is_not_round_winner; 
        // piano[pos] = is_not_round_winner; 

        //if(is_not_round_winner) bullys[pos] = winner + 1; // 1-based index

        return;
    }

    long m = (l + r) / 2;
    long l_tree = 2 * id + 1, r_tree = 2 * id + 2;
    // bool l_all_dead = tree[l_tree], r_all_dead = tree[r_tree];

    // // if(!l_all_dead) update(l_tree, l, m, ql, qr, winner);
    // // if(!r_all_dead) update(r_tree, m + 1, r, ql, qr, winner);

    // // obs: get tree again, because now it's been updated
    // tree[id] = tree[l_tree] && tree[r_tree]; // all dead ?
}

long query(long id, long l, long r, long ql, long qr)
{
    if(ql <= l && qr >= r) 
    {
        vector<long> note_count = tree[id];
        long max_count = note_count[0];
        //long max_note = 0; 

        for (long note = 0; note < MAX; note++)
        {
            long aux_count = note_count[note];
            if(aux_count > max_count) 
            {
                max_count = aux_count;
                //max_note = note;
            }
        }

        return max_count; 
    }
    if(qr < l || r < ql) return 0;

    long m = (l + r) / 2; 
    long l_tree = 2 * id + 1, r_tree = 2 * id + 2;

    vector<long> l_note_count = tree[l_tree];
    vector<long> r_note_count = tree[r_tree];
    vector<long> aux_note_count(MAX, 0);

    for (long i = 0; i < MAX; i++)
    {
        aux_note_count[i] = l_note_count[i] + r_note_count[i];
    }

    long max_count = aux_note_count[0];
    dln(max_count);
    //long max_note = 0;
    for (long note = 0; note < MAX; note++)
    {
        long aux_count = aux_note_count[note];
        if(aux_count > max_count) 
        {
            max_count = aux_count;
            //max_note = note;
        }
    }

    return max_count;
}

int main()
{
    long n, m;
    cin >> n >> m;

    piano = vector<long>(n, 1);
    tree = vector<vector<long>>(4 * n, vector<long>(MAX, 0));
    //vector<long>::iterator beg = piano.begin();
    
    build(0, 0, n - 1);
    dm(tree);

    for (long i = 0; i < m; i++)
    {
        long a, b;
        cin >> a >> b;

        //a--; b--;

        //piano.data();

        // long max_freq = max_element(&(piano[a]), &(piano[b]));
        // long max_freq = val_of_max_freq_el(piano, a, b);
        d(a); dln(b)

        long max_freq = query(0, 0, n - 1, a, b);
        dln(max_freq);

        //update(0, 0, n - 1, a, b, max_freq);
    }    

    for (long i = 0; i < n; i++)
    {
        cout << piano[i] << endl;
    }    

	return 0;
}