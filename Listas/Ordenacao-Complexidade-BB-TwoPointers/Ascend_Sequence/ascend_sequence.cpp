//https://codeforces.com/contest/1284/problem/B
#include <vector>
#include <iostream>

using namespace std;

struct ascend_sequence
{
  int max;
  int min;
  vector<int> v;
};

typedef struct ascend_sequence asc_seq;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> seqs;

    for(int i = 0; i < n; i++ ){
      int l;
      cin >> l;
      vector<int> aux(l);
      for (int j = 0; j < l; j++)
      {
        cin >> aux[j];
      }
      seqs.push_back(aux);
    }
    
    unsigned long count = 0;
    
    cout << count << endl;
    return 0;
}
