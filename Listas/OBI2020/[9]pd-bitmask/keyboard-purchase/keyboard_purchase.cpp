// https://codeforces.com/problemset/problem/1238/E

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

#define BLANK 1e9
#define INVALID -1
#define MAX_LETTERS 20

#define d(VAR) cout << #VAR << " = " << VAR << ", ";
#define dln(VAR) cout << #VAR << " = " << VAR << endl;
#define dv(v) cout << #v << " = \n"; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = \n"; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }
#define dmp(mp) cout << #mp << " = \n"; for(auto& kv : mp) { cout << kv.first << " : " << kv.second << endl; }

long n, m;
unordered_map<string, long> pair_to_freq;
unordered_map<string, long> bitmask_to_cost;

vector<ll> fats;
void calc_fat()
{
    ll fat = 1;
    for (ll i = 1; i < MAX_LETTERS + 1; i++)
    {
        fats.push_back(fat);
        fat *= i;
    }    
}

long calc_min_cost(vector<char> unused_letters)
{
    if(unused_letters.size() == 0) return 0;

    char first_letter = unused_letters.back();
    d(first_letter);
    //unused_letters.erase(first_letter);
    //unused_letters.pop_back();

    vector<char> keyboard = unused_letters;
    for (ll i = 0; i < fats[unused_letters.size()]; i++)
    {
        next_permutation(keyboard.begin(), keyboard.end());
        dv(keyboard);
    }

    return 0;//calc_min_cost(unused_letters);
}

int main()
{
    cin >> n >> m;

    calc_fat();

    string psswd;
    cin >> psswd;

    set<char> aux_unused = {};
    vector<char> unused_letters; // must maintain letter order : set and not unordered set
    for(char letter : psswd)
    {
        if(aux_unused.find(letter) == aux_unused.end())
        {
            unused_letters.push_back(letter);
            aux_unused.insert(letter);
        }
    }

    for (long i = 1; i < n; i++)
    {
        char ch1 = psswd[i - 1], ch2 = psswd[i];

        if(ch2 < ch1)
        {
            char aux = ch1;
            ch1 = ch2;
            ch2 = aux;
        }
        string s = {ch1, ch2};

        long old_freq = 0;

        bool has_pair = pair_to_freq.find(s) != pair_to_freq.end(); 
        
        if(has_pair)
        {
            old_freq = pair_to_freq[s];
        }

        old_freq++;
        pair_to_freq[s] = old_freq;
    }
    
    
    dmp(pair_to_freq);
    dv(aux_unused);

    long result = calc_min_cost(unused_letters);

    cout << result << endl;

	return 0;
}