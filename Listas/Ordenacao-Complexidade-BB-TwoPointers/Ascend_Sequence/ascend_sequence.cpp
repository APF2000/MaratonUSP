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
  //vector<int> v;
};

typedef struct ascend_node asc_node;

void insert_node(asc_node *root, asc_node *new_node, long unsigned *count)
{
	asc_node *last = root, *next = root;

	while(next != NULL)
	{
		bool is_greater = (new_node->max > next->min);

		next = last->sons[is_greater];
		if(next == NULL) last->sons[is_greater] = new_node;
		last = next;

		(*count)++;
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

		asc_node anode;
		anode.min = min;
		anode.max = max;

		seqs.push_back(anode);
    }

    unsigned long count = 0;

	// Ida
    asc_node *root = &seqs[0];
    for (int i = 1; i < n; i++)
    {
		asc_node *new_node = &seqs[i];
		insert_node(root, new_node, &count);
    }
	print_tree(root, 0);

	// Resetar ponteiros
	for (int i = 0; i < n; i++)
	{
		asc_node *node = &seqs[i];

		node->sons[true] = NULL;
		node->sons[false] = NULL;
	}

	// Volta
	root = &seqs[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
		asc_node *new_node = &seqs[i];
		insert_node(root, new_node, &count);
    }
	print_tree(root, 0);

	cout << count << endl;

    return 0;
}
