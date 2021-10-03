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
		//cout << "=============================================" << endl;

	for (int i = 1; i < s.size(); i++)
	{
		char this_letter = s[i];
		char last_letter = s[i - 1];
		//cout << "----------------------------------------" << endl;
		
		if(visitados.find(s[i]) != visitados.end())
		{ 	// has key
			//cout << "HAS KEY" << endl;

			node* last_node = visitados[last_letter];
			node* next = last_node->next;
			node* previous = last_node->previous;

			bool ok_keyboard = (next != NULL && next->letter == this_letter)
				|| (previous != NULL && previous->letter == this_letter);

			if(!ok_keyboard)
			{
				////cout << this_letter << " != " << previous->letter << endl;
				return NULL;
			}
			//print_keyboard(keyboard);
		}
		else
		{	// hasnt key
			//cout << "HASnt KEY" << endl;
			
			node* last_node = visitados[last_letter];
			node* this_node;

			if(last_node->next == NULL)
			{
				this_node = constructor(this_letter, NULL, last_node);
				last_node->next = this_node;

				end_kb = this_node;

				//cout << "diretia " << this_letter << endl;
			}
			else if(last_node->previous == NULL)
			{
				this_node = constructor(this_letter, last_node, NULL);
				last_node->previous = this_node;

				keyboard = this_node;
				//cout << "esq " << this_letter << endl;
			}
			else{
				//cout << "WTF??????????????????" << endl;
				return NULL;
			}

			unused_letters.erase(this_letter);
			visitados[this_letter] = this_node;
			//print_keyboard(keyboard);
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