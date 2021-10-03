//https://codeforces.com/problemset/problem/1303/C

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

struct node{
	char letter;
	struct node *next;
	struct node *previous;
};

node* constructor(char letter, node* next, node* previous){
	node *root = new node;
	root->letter = letter;
	root->next = next;
	root->previous = previous;
	return root;
}


void print_keyboard(node* keyboard)
{
	for(node* node = keyboard; node != NULL; node = node->next)
	{
		cout << node->letter;
	}
	cout << endl;
}

node* is_possible(string s){
	map<char, node*> visitados;
	char ch = s[0];
	node* keyboard = constructor(ch, NULL, NULL);

	unordered_set<char> unused_letters;
	for(char ch = 'a'; ch <= 'z'; ch++) unused_letters.insert(ch);
	unused_letters.erase(ch);

	node* end_kb = keyboard;

	visitados[ch] = keyboard;

	for (int i = 1; i < s.size(); i++)
	{
		char this_letter = s[i];
		char last_letter = s[i - 1];
		
		if(visitados.find(s[i]) != visitados.end())
		{ 	// has key

			node* last_node = visitados[last_letter];
			node* next = last_node->next;
			node* previous = last_node->previous;

			bool ok_keyboard = (next != NULL && next->letter == this_letter)
				|| (previous != NULL && previous->letter == this_letter);

			if(!ok_keyboard)
			{
				return NULL;
			}
		}
		else
		{	// hasnt key
			
			node* last_node = visitados[last_letter];
			node* this_node;

			if(last_node->next == NULL)
			{
				this_node = constructor(this_letter, NULL, last_node);
				last_node->next = this_node;

				end_kb = this_node;
			}
			else if(last_node->previous == NULL)
			{
				this_node = constructor(this_letter, last_node, NULL);
				last_node->previous = this_node;

				keyboard = this_node;
			}
			else{
				return NULL;
			}

			unused_letters.erase(this_letter);
			visitados[this_letter] = this_node;
		}
	}

	for(char ch : unused_letters)
	{
		node *aux_node = constructor(ch, NULL, NULL);
		end_kb->next = aux_node;
		end_kb = aux_node;
	}

	return keyboard;
}

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;

		node* keyboard = is_possible(s);
		if(keyboard != NULL)
		{
			cout << "YES" << endl;
			print_keyboard(keyboard);
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}