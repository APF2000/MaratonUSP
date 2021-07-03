//https://codeforces.com/contest/1295/problem/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t, z;
    string prov;
    int T, com ;
	bool achou = false;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> s;
        cin >> t;
		z = "";
		com = 0;
        for(int j = 0; j < t.length(); j++){
            //cout << "T[" << j <<"]" << t[j] << endl;
			achou = false;
            for(int k = com; k < s.length(); k++){
                if(s[k] == t[j]){
					for(int a = 0; a < z.length(); a++){
						if(s[k] == z[a]){
							achou = true;
						}
					}
					if(!achou){
						prov = s[k];
                   		z.append(prov);
						achou = false;
                   		cout << "z[" << j <<"]" << z << endl;
					}
                }
            }
			com++;
        }
    }
    return 0;
}