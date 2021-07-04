//https://codeforces.com/contest/1295/problem/C
#include <bits/stdc++.h>

using namespace std;

int bb(vector<int> v, int index, int esq, int dir){
	int m;
	int size = v.size();
	m = (esq + dir)/2;
	if(esq >= dir)
	{
		if(index >= v[m]) return v[(m + 1) % size];
		else return v[m];
	}

	if(v[m] < index){
		return bb(v, index, m + 1, dir);
	}
	else if(v[m] > index){
		return bb(v, index, esq, m - 1);
	}
	else{
		return v[(m + 1) % v.size()];
	}
}

struct v_and_last
{
	int last;
	vector<int> v;
};

typedef struct v_and_last vl;

int next_index(vl *el)
{
	int *last = &(el->last);
	*last = (*last + 1) % el->v.size();

	return( el->v[*last] );
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
		map<char, vl> pos;

        cin >> s;
        cin >> t;

        for(int j = 0; j < s.length(); j++){
			char key = s.at(j);
			vl aux;

            if(pos.find(key) == pos.end()){
				aux.last = 0;
				aux.v = {j};
				pos[key] = aux;
			}
			else{
				pos[key].v.push_back(j);
			}
        }

		int last_index = -1, new_index;
		for(int k = 0; k < t.size(); k++){
			char key = t.at(k);
			if(pos.find(key) != pos.end()){

				//new_index = bb(pos[key], last_index, 0, pos[key].size()-1);
				new_index = next_index(&pos[key]);

				if(new_index <= last_index){
					ops++;
				}

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