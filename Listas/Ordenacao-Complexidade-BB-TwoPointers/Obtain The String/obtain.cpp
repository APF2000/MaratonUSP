#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t, z;
    string prov;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> s;
        cin >> t;
        for(int j = 0; j < t.length(); j++){
            //cout << "T[" << j <<"]" << t[j] << endl;
            for(int k = 0; k < s.length(); k++){
                if(s[k] == t[j]){
                    prov = s[k];
                   z.append(prov);
                   cout << "z[" << j <<"]" << z << endl;
                }
            }
        }
    }
    return 0;
}