#include<iostream>
#include <string>
#include<map>
using namespace std;

bool analaisador(string s, string *kbrd){
	char analise;
	string kbrd;
	map<char, char> visitados;
	if(kbrd->size() == 0){ //nó inicial
		kbrd += s[0];
	}
	for (int i = 0; i < s.size(); i++)
	{
		
	}
	
}

int main(){
	int T;
	string s, kbrd;
	bool isPossible;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> s;
		isPossible = analaisador(s, &kbrd);
		if(isPossible){
			cout << "YES" << endl;
			cout << kbrd << endl;
		} else{
			cout << "NO" << endl;
		}
	}
	
	return -1;
}