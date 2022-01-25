#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    map<int, string> m;
    m.insert(pair<int, string>(11, "Sao Paulo"));
    
    int ddd;
    cin >> ddd;

    if(m.count(ddd) == 0){
        cout << "sem ddd";
    }else{
        //cout << m.at(ddd);
    }

    return 0;
}