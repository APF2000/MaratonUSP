//https://codeforces.com/contest/1284/problem/B

#include <vector>
#include <iostream>
#include <map>
#include <algorithm> // min_element, max_element

using namespace std;

struct ascend_node
{
  int max;
  int min;
  map<bool, struct ascend_node*> sons; // direita e esquerda
  long unsigned count = 0;
  //vector<int> v;
};

typedef struct ascend_node asc_node;

void count_right_tree(asc_node *last, asc_node* new_node, long unsigned *count){
	if(last == NULL){
		cout << new_node->min << ", " << new_node->max << " DEU NULL" << endl;
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

		cout << "Count total: " << *count << endl;
		
		next = last->sons[is_greater];
		if(next == NULL) last->sons[is_greater] = new_node;
		last = next;
	}
}

void print_spaces(int qtty)
{ 
	for (int i = 0; i < qtty; i++) cout << "\t";
 }

void print_tree(asc_node *root, int depth)
{
	if(root == NULL) return;

	cout << "(" << root->min << ", " << root->max << ")-> " << endl;

	print_spaces(depth + 1);
	cout << "e: {";
	print_tree(root->sons[true], depth + 1);
	print_spaces(depth + 1);
	cout << "} " << endl;

	print_spaces(depth + 1);
	cout << "d: {";
	print_tree(root->sons[false], depth + 1);
	print_spaces(depth + 1);
	cout << "} " << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<asc_node> seqs;
    unsigned long count = 0;

    for(int i = 0; i < n; i++ ){
		int l;
		cin >> l;

		vector<int> aux(l);
		for (int j = 0; j < l; j++)
		{
			cin >> aux[j];
		}

		int min = *(min_element(aux.begin(), aux.end()));
		int max = *(max_element(aux.begin(), aux.end()));

		if(max > min) count += 2;

		asc_node anode;
		anode.min = min;
		anode.max = max;

		seqs.push_back(anode);
    }

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
		asc_node *new_node = &seqs[i];
		insert_node(root, new_node, &count);
    }
	//print_tree(root, 0);

	cout << count << endl;

    return 0;
}

/*
4
2 2 4
2 1 3
2 3 5
2 1 1

            (2, 4)
        (1,1)       (1, 3)
                		(3, 5)

			(1,1)
					(3,5)
				(1,3)	(2,4)
2 4 2 4
2 4 2 4
1 3 1 3
1 3 1 3
3 5 3 5
3 5 3 5

2 3
2 5
1 5

1 5
1 3
1 4
3 4
1 2


11
2 31 35
3 62 24 39
1 17
1 99
1 60
1 64
1 30
2 79 29
2 20 73
2 85 37
1 100

          24
    17         99
            60     100  
         30   64
               79
                73
                 85

				100
			85
		30	    73
	17     35     	79
						64
				60				99
					62

5
1 1
1 1
1 2
1 4
1 3

             1
      1             2
                        4
                    3



             3
        2        4
     1
   1

1 2
1 2
2 4
1 4
1 4
1 3
1 3
2 3
*/