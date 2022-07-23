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

        dv(aux_note_count);
        dv(new_note_count);

        tree[id] = new_note_count;

        long new_note = (piano[pos] + max_note) % MAX;
        //piano[pos] = (new_note != 0 ? new_note : 1);
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
    // bool l_all_dead = tree[l_tree], r_all_dead = tree[r_tree];

    // // if(!l_all_dead) update(l_tree, l, m, ql, qr, winner);
    // // if(!r_all_dead) update(r_tree, m + 1, r, ql, qr, winner);

    // // obs: get tree again, because now it's been updated
    // tree[id] = tree[l_tree] && tree[r_tree]; // all dead ?
}

vector<long> query(long id, long l, long r, long ql, long qr)
{
    if(qr < l || r < ql) return vector<long>(MAX, 0);

    if(ql <= l && qr >= r) 
    {
    //dln("BATATA2");
        vector<long> note_count = tree[id];
    //dln("BATATA3");
        //long max_count = note_count[0];
        //long max_note = 0; 

        // for (long note = 0; note < MAX; note++)
        // {
        //     long aux_count = note_count[note];
        //     if(aux_count > max_count) 
        //     {
        //         max_count = aux_count;
        //         //max_note = note;
        //     }
        // }

        return note_count; 
    }

    //dln("BATATA");

    long m = (l + r) / 2; 
    long l_tree = 2 * id + 1, r_tree = 2 * id + 2;

    vector<long> l_note_count = query(l_tree, l, m, ql, qr);
    vector<long> r_note_count = query(r_tree, m + 1, r, ql, qr);

    //dln("BATATA4");
    vector<long> aux_note_count(MAX, 0);

    
    //dln("BATATA5");
    for (long note = 0; note < MAX; note++)
    {
        aux_note_count[note] = l_note_count[note] + r_note_count[note];
    }
    //dln("BATATA6");

    // long max_count = aux_note_count[0];
    // //long max_note = 0;
    // for (long note = 0; note < MAX; note++)
    // {
    //     long aux_count = aux_note_count[note];
    //     if(aux_count > max_count) 
    //     {
    //         max_count = aux_count;
    //         //max_note = note;
    //     }
    // }
    // dln(max_count);

    return aux_note_count;
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
    dv(piano);

    for (long i = 0; i < m; i++)
    {
        long a, b;
        cin >> a >> b;

        //a--; b--;

        //piano.data();

        // long max_freq = max_element(&(piano[a]), &(piano[b]));
        // long max_freq = val_of_max_freq_el(piano, a, b);
        d(a); dln(b)

        vector<long> note_count = query(0, 0, n - 1, a, b);
        dv(note_count);

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
        max_note++;
        d(max_note);
        dln(max_count);

        update(0, 0, n - 1, a, b, max_note);
        dv(piano);
        dm(tree);
        dln("--------------------------");
    }    

    for (long i = 0; i < n; i++)
    {
        cout << piano[i] << endl;
    }    

	return 0;
}