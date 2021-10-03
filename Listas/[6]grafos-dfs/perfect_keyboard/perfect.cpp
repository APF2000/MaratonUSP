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

node* is_possible(string s){
	map<char, node*> visitados;
	char ch = s[0];
	node* keyboard = constructor(ch, NULL, NULL);

	unordered_set<char> unused_letters;
	for(char ch = 'a'; ch <= 'z'; ch++) unused_letters.insert(ch);

	node* end_kb = keyboard;

	visitados[ch] = keyboard;

	for (int i = 1; i < s.size(); i++)
	{
		char this_letter = s[i];
		char last_letter = s[i - 1];
		
		if(visitados.find(s[i]) != visitados.end())
		{ 	// has key
			node* this_node = visitados[this_letter];
			node* next = this_node->next;
			node* previous = this_node->previous;

			if( (next != NULL && next->letter != last_letter)
				|| (previous != NULL && previous->letter != last_letter) )
			{
				return NULL;
			}
		}
		else
		{	// hasnt key
			node* last_node = visitados[last_letter];
			node* this_node = constructor(this_letter, NULL, last_node);
			last_node->next = this_node;

			visitados[this_letter] = this_node;

			end_kb = this_node;

			unused_letters.erase(this_letter);
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

void print_keyboard(node* keyboard)
{
	for(node* node = keyboard; node != NULL; node = node->next)
	{
		cout << node->letter;
	}
	cout << endl;
}

int main(void){
	/*cout << "WIN dows" << endl;
	node *no1;//= new node;
	node *no2; //= new node;
	no1->id = 'a';
	no2->id = 'b';
	no1->next = no2;
	no2->previous = no1;
	cout << no1->id << "   " << no2->id << endl;*/
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;

		node* keyboard = is_possible(s);
		if(keyboard != NULL){
			cout << "YES" << endl;
			//cout << keyboard << endl;
			print_keyboard(keyboard);
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}