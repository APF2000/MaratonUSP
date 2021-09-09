#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;

bool analaisador(string s, vector<char> *kbrd){
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
			if(position == kbrd->size() - 1){
				kbrd->push_back(s[i]);
				visitados[s[i] - 'a'] = 1;
				position++;
			}
			else{
				if(position == 0){
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
		}
		
	}
	return true;
}

int main(){
	int T;
	string s;
	vector<char> kbrd;
	bool isPossible;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> s;
		isPossible = analaisador(s, &kbrd);
		if(isPossible){
			cout << "YES" << endl;
			for(int i = 0; i < kbrd.size() - 1; i++){
				cout << kbrd.at(i) << endl;
			}
		} else{
			cout << "NO" << endl;
		}
	}
	return 0;
}