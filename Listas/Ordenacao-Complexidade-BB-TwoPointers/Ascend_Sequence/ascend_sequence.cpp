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

int binomial(int i){
// n!/2!(n-2)! - n_asc!/2 
    int binom;
    binom = i*(i-1)/2;
    return binom;
}

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
    // 1 2 3 4
    // 
    vector<vector<int>> asc;
    vector<asc_seq> n_asc;
    
   for(vector<int> vec: seqs){
      int aux_menor = vec[0];
      int aux_maior = vec[0];
      bool isAsc = false;
      for (unsigned int i = 1; i < vec.size(); i++)
      {
          if(vec.at(i) < aux_menor){
            aux_menor = vec.at(i);
          }
          if(vec.at(i) > aux_maior){
            aux_maior = vec.at(i);
          }
          if(vec.at(i) > aux_menor){
            isAsc = true;
            break;
          }
      }
      if(isAsc){
        asc.push_back(vec);
      }
      else{
        asc_seq temp;
        temp.min = aux_menor;
        temp.max = aux_maior;
        temp.v = vec;
        n_asc.push_back(temp);
      }
    }
    unsigned long count = 0;
    count += asc.size()*asc.size() + 2*asc.size()*n_asc.size();
    
    for (int i = 0; i < n_asc.size(); i++)
    {
      for (int j = 0; j < n_asc.size(); j++)
      {
        asc_seq a = n_asc[i], b = n_asc[j];
        if(a.max > b.min){
          count ++;
        }
      }
      
    }
    cout << count << endl;
    return 0;
}
