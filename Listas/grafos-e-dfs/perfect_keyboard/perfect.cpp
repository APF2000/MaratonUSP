//https://codeforces.com/problemset/problem/1303/C

#include<iostream>
#include <string>
#include <vector>
#include<map>
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
		string keyboard;
		if(is_possible(&keyboard, s)){
			cout << "YES" << endl;
			cout << keyboard << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}