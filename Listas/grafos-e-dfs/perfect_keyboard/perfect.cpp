//https://codeforces.com/problemset/problem/1303/C

#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;

<<<<<<< HEAD
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

bool is_possible(string* keyboard, string s){
	map<char, node*> visitados;
	keyboard->push_back(s[0]);
	node *root = constructor(s[0], NULL, NULL);
	visitados[s[0]] = root;
	for (int i = 1; i < s.size(); i++)
	{
		
		if(visitados.find(s[i]) != visitados.end()){

		}
		else{
			keyboard->push_back(s[i]);
=======
bool analisador(string s, vector<char> *kbrd){
	char analise;
	int position = 0;
	int visitados [26];
	if(kbrd->size() == 0){ //nó inicial
		kbrd += s[0];
		visitados[s[0] - 'a'] = 1;
	}
	for (int i = 1; i < s.size(); i++)
	{
		if(visitados[s[i] - 'a'] == 0){
			if(position == kbrd->size() - 1){ //insere no fim
				kbrd->push_back(s[i]);
				visitados[s[i] - 'a'] = 1;
				position++;
			}
			else{
				if(position == 0){ //insere no começo
					visitados[s[i] - 'a'] = 1;
					kbrd->insert(kbrd->begin(), s[i]);
				}
				else{
					return false;
				}
			}
		}
		else{ 
			if(position == kbrd->size() - 1){
				if(kbrd->at(kbrd->size()-2) == s[i]){
					position --;
					continue;
				}
				else{
					return false;
				}
			}
			else if(position == 0){
				if(kbrd->at(1) == s[i]){
					position++;
					continue;
				}
				else{
					return false;
				}
			}
			else{
				if(kbrd->at(position + 1) == s[i]){
					position++;
					continue;
				}
				else if(kbrd->at(position - 1) == s[i]){
					position--;
					continue;
				}
				else{
					return false;
				}
			}
>>>>>>> 05d895ee1b229d03384d0ba6a395e31e73ab8af9
		}
	}
	return false;
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
<<<<<<< HEAD
		string keyboard;
		if(is_possible(&keyboard, s)){
=======
		isPossible = analisador(s, &kbrd);
		if(isPossible){
>>>>>>> 05d895ee1b229d03384d0ba6a395e31e73ab8af9
			cout << "YES" << endl;
			cout << keyboard << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}