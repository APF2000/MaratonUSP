//https://codeforces.com/problemset/problem/676/C
#include <bits/stdc++.h>

using namespace std;

int contagem(string s){
for(unsigned pont = 0; pont < s.length()-1; pont++){
	int count = 0, max_lenght = 0;
		cout << "count for " << count << endl;
		if(s.at(pont) == 'b'){
			if(max_lenght < count){
				max_lenght = count;
			}

			count = 0;
		}
		else{
			count++;
		}
	}
	cout << "max lenght " << max_lenght << endl;
	cout << "count " << count << endl;
	if(max_lenght < count){
		max_lenght = count;
	}
	cout << max_lenght << endl;
	return max_lenght;
}



int main()
{
    string s;
    int n, k;
    cin >> n >> k;
	
	cin >> s;
	
    return 0;
}