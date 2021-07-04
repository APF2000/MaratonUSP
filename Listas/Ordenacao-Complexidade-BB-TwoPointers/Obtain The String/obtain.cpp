//https://codeforces.com/contest/1295/problem/C
#include <bits/stdc++.h>

using namespace std;

int bb(vector<int> v, int index, int esq, int dir){
	int m;
	int size = v.size();
	m = (esq + dir)/2;
	// cout << "dir: " << dir << "; esq: " << esq << "; index: " << index << endl;
	// cout << "size: "<< size << endl;

	if(esq >= dir)
	{
		if(index >= v[m]) return v[(m + 1) % size];
		else return v[m];
		//if(v[m] < index) return v[m];
		//else if(v[m] > index) return v[(m - 1 + size) % size];
	}
	/*if(m == esq || v[m] == index){
		return v[(m + 1) % v.size()];
		/*if(m == v.size()-1){
			return v[0];
		}
		return v[m];*
	}*/
	if(v[m] < index){
		return bb(v, index, m + 1, dir);
	}
	else if(v[m] > index){
		return bb(v, index, esq, m - 1);
	}
	else{
		return v[(m + 1) % v.size()];
		/*if(m == v.size()-1){
			return -1;
		}*/
		return m;//m+1;
	}
}
// 1 3 5 8 10 15 23
// 1 4 7 9 13 14
int main()
{
    string s, t;// z;
    //string prov;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
		bool no_letter = false;
        cin >> s;
        cin >> t;
		//z = "";
		int ops = 1;
		map<char, vector<int>> pos;
        for(int j = 0; j < s.length(); j++){
			char key = s.at(j);
            if(pos.find(key) == pos.end()){
				pos[key] = {j};
			}
			else{
				pos[key].push_back(j);
			}
        }
		int last_index = -1, new_index;
		for(int k = 0; k < t.size(); k++){
			char key = t.at(k);
			if(pos.find(key) != pos.end()){
				// cout << "key: " << key << endl; 
				// cout << "lastindex: " << last_index << endl;
				
				new_index = bb(pos[key], last_index, 0, pos[key].size()-1);

				//cout << "newindex: " << new_index << endl;

				// if(new_index == pos[key].size()){
				// 	new_index = last_index;
				// }

				if(new_index <= last_index){
					ops++;
				}
				//cout << "newops: " << ops << endl;
				last_index = new_index;
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

/*
3
aabce
ace
abacaba
aax
ty
yyt
*/