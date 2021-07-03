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

typedef struct ascend_node asc_node;

void count_right_tree(asc_node *last, asc_node* new_node, long unsigned *count){
	if(last == NULL){
		//cout << new_node->min << ", " << new_node->max << " DEU NULL" << endl;
		return;
	} 
	bool is_greater_aux = (new_node->max > last->min);
	if(is_greater_aux){
		cout << new_node->max << " > " <<  last->min << endl;
		*count ++;
	}
	count_right_tree(last->sons[true], new_node, count);
	count_right_tree(last->sons[false], new_node, count);
}

void insert_node(asc_node *root, asc_node *new_node, long unsigned *count)
{
	asc_node *last = root, *next = root;

	long unsigned antes_count = *count;
	while(next != NULL)
	{
		bool is_greater = (new_node->max > last->min);
		//bool is_less = (new_node->max < last->min);

		cout << "------------------------------------------" << endl;
		
		//cout << "Count last: " << last->count << endl;

		if(is_greater)
		{
			cout << new_node->max << " > " << last->min << endl;
			(*count) += (1 + last->count);
		}else 
		{
			//cout << "Is less: " << is_less << endl;

			last->count++;
			count_right_tree(last->sons[!is_greater], new_node, count);
			
			cout << new_node->max << " < " << next->min << " : count esq = " << next->count << endl;
		
		}

		//cout << "Count total: " << *count << endl;
		
		next = last->sons[is_greater];
		if(next == NULL) last->sons[is_greater] = new_node;
		last = next;
	}
	cout << new_node->min << ", " << new_node->max << ": ";
	cout << "antes= " << antes_count << "; depois= " << *count << endl; 
}

void print_spaces(int qtty)
{ 
	for (int i = 0; i < qtty; i++) cout << "\t";
 }


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


    vector<asc_node> seqs;
    unsigned long count = 0;
	long asc = 0, not_asc = 0;

    for(int i = 0; i < n; i++ ){
		int l;
		cin >> l;

		vector<int> aux(l);
		for (int j = 0; j < l; j++)
		{
			cin >> aux[j];
		}

		bool is_asc = false;
		int min = aux[0], max = aux[0];
		for(int el : aux)
		{
			if(el < min) min = el;
			else if(el > max) max = el;

			if(el > min) is_asc = true;
		}

		//if(max > min) count += 1;//2;
		if(is_asc)
		{
			asc++;
		}else
		{
			//int min = *(min_element(aux.begin(), aux.end()));
			//int max = *(max_element(aux.begin(), aux.end()));
			if(max > min) count += 1; // not_asc seguido de not_asc

			asc_node anode;
			anode.min = min;
			anode.max = max;

			seqs.push_back(anode);
			not_asc++;
		}
    }

	count += (asc * asc) + 2 * (asc * not_asc);
	cout << "Prim count: " << count << endl;
	cout << "Asc: " << asc << ", nasc: " << not_asc << endl;

	// Arvore so com os not_asc
	n = not_asc;

	// Ida
    asc_node *root = &seqs[0];
    for (int i = 1; i < n; i++)
    {
		asc_node *new_node = &seqs[i];
		insert_node(root, new_node, &count);
    }
	//print_tree(root, 0);

	// Resetar ponteiros
	for (int i = 0; i < n; i++)
	{
		asc_node *node = &seqs[i];

		node->sons[true] = NULL;
		node->sons[false] = NULL;

		node->count = 0;
	}

	// Volta
	root = &seqs[n - 1];
    for (int i = n - 2; i >= 0; i--)

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

	//print_tree(root, 0);

	cout << count << endl;

    return 0;
}