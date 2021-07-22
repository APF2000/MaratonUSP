//https://codeforces.com/contest/1295/problem/C
#include <bits/stdc++.h>

using namespace std;

int bb(vector<int> v, int index, int esq, int dir){
	//cout << "{" << index << ", " << esq << ", " << dir<< "}, ";

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

        cin >> s;
        cin >> t;

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
		map<char, vector<int>> mem;
		for(int k = 0; k < t.size(); k++){
			char key = t.at(k);
			bool primeira_vez = true;
			int  count = 0;
			if(pos.find(key) != pos.end()){

				//cout << "k = " << k << ", size = " << t.size() << endl;

				chrono::steady_clock sc;   // create an object of `steady_clock` class
				auto start = sc.now();     // start timer

				// do stuff....

				auto end = sc.now();   

				//cout << key << ": ";
				if(primeira_vez)
				new_index = bb(pos[key], last_index, 0, pos[key].size()-1);
				else{
				cout << mem[key][count] << endl;
				new_index = bb(pos[key], last_index, mem[key][count], pos[key].size()-1);
				count++;
				}

    			// end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
				auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
				//cout<<" Operation took: " << time_span.count() *1000000000 << " nano seconds !!!" << endl;
				
				//cout << endl;

				if(new_index <= last_index){
					ops++;
				}
				mem[key].push_back(new_index);
				last_index = new_index;
				primeira_vez = false;
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