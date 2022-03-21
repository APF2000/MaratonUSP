//https://www.urionlinejudge.com.br/judge/pt/problems/view/1050
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int padrao[]={61, 71, 11, 21, 32, 19, 27, 31}, ddd, i, achou = 0;
    string nome[]={"Brasilia","Salvador", "Sao Paulo", "Rio de Janeiro", 
        "Juiz de Fora", "Campinas", "Vitoria", "Belo Horizonte"};
    cin >> ddd;
    for(i = 0; i < 8; i++){
        if(ddd == padrao[i]){
            cout << nome[i]; 
            return 0;
        }  
    }
    if(achou == 0)
        cout << "DDD nao cadastrado";
    return 0;
}