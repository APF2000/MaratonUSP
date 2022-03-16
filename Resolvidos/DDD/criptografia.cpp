#include <iostream>
#include <string>

using namespace std;

string passo1(string st)
{
    char ch;
    string aux;

    for(int i = 0; i < st.length(); i++)
    {
        ch = st[i];

        if(isalpha(ch)) ch += 3;

        aux.push_back(ch);
    }

    return aux;
}

int main()
{
    string st;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        getline(cin, st);
        
        st = passo1(st);
        cout << "Mudado 1: " << st << "\n";
        //st = passo2(st);
        //st = passo3(st);
    }    
    
    return 0;
}