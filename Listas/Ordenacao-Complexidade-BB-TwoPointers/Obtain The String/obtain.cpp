//https://codeforces.com/contest/1295/problem/C
#include <bits/stdc++.h>

using namespace std;

int bb(vector<int> v, int id_string, int esq, int dir){
	//cout << "{" << id_string << ", " << esq << ", " << dir<< "}, ";

	int m;
	int size = v.size();
	m = (esq + dir)/2;
	if(esq >= dir)
	{
		if(id_string >= v[m]) return (m+1)%size; //v[(m + 1) % size];
		else return m; //v[m];
	}

	if(v[m] < id_string){
		return bb(v, id_string, m + 1, dir);
	}
	else if(v[m] > id_string){
		return bb(v, id_string, esq, m - 1);
	}
	else{
		return (m+1)%size; //v[(m + 1) % v.size()];
	}
}


int main()
{
    string s, t;

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
		bool no_letter = false;
		int ops = 1;
		map<char, vector<int>> pos;
		map<char, int> mem;
        cin >> s;
        cin >> t;

        for(int j = 0; j < s.length(); j++){
			char key = s.at(j);
            if(pos.find(key) == pos.end()){
				pos[key] = {j};
				mem[key] = 0;
			}
			else{
				pos[key].push_back(j);
			}
        }

		int last_id_vec = -1, new_id_vec;
		for(int k = 0; k < t.size(); k++){
			char key = t.at(k);	
			if(pos.find(key) != pos.end()){
				new_id_vec = bb(pos[key], last_id_vec, mem[key], pos[key].size()-1);
				mem[key] = new_id_vec;
				if(pos[key][new_id_vec] <= pos[key][last_id_vec]){
					ops++;
				}
				last_id_vec = new_id_vec;
			}
			else{
				no_letter = true;
				break;
			}
		}
		if(no_letter){
			cout << "-1" << endl;
		}
		else{
			cout << ops << endl;
		}
    }
    return 0;
}
//mem: guardar indices (item) do vetor t, então n usar o count++
//usar ideia do pires do outro branch
/*
3
aabce
ace
abacaba
aax
ty
yyt
*/