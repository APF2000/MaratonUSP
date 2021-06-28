//https://codeforces.com/contest/1284/problem/B
#include <vector>
#include <iostream>
#include <algorithm>

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

    vector<asc_seq> seqs;

    for(int i = 0; i < n; i++ ){
      int l;
      cin >> l;
      vector<int> aux(l);
      for (int j = 0; j < l; j++)
      {
        cin >> aux[j];
      }
	  int min = *min_element(aux.begin(), aux.end());
	  int max = *max_element(aux.begin(), aux.end());
	  asc_seq aux_asc;
	  aux_asc.min = min;
	  aux_asc.max = max;
	  aux_asc.v = aux;
      seqs.push_back(aux_asc);
    }
    // 1 2 3 4
    // 
    vector<vector<int>> asc;
    vector<asc_seq> n_asc;
    
  
    unsigned long count = 0;
    
    
    for (int i = 0; i < seqs.size(); i++)
    {
      for (int j = 0; j < seqs.size(); j++)
      {
        asc_seq a = seqs[i], b = seqs[j];
        if(a.min < b.max){
          count ++;
		  cout << "( "<< i << ", " << j  << ")"<< "{" ;
		  for (int k = 0; k < a.v.size(); k++)
		  {
			 cout << a.v[k] << " ";
		  }
		  cout << "}, {";
		   for (int k = 0; k < b.v.size(); k++)
		  {
			 cout << b.v[k] << " ";
		  }
		  cout << "}" <<endl;
        }
      }
      
    }
    cout << count << endl;
    return 0;
}