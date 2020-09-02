#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

void printWord(string word){
    cout << word;
}

void inicializarCom1(vector<int> *v){
    for(int i = 0; i < (*v).size(); i++){
        (*v).at(i) = 1;
    }
}

void printaVetor(vector<int> v){
    string line ="";
    for(int i = 0; i < v.size(); i++){
        if(i % 5 == 0){
            //cout << "PASSEI AQUI " << v.at(i) << "\n";
            cout << line << "\n";
            line = "";
        }
        line += to_string(v.at(i)) + " ";
    }
    cout << line << "\n";
}

int main(){
    vector<int> v(22);
    //v.push_back(2);
    //v.pop_back();
    //v.at(0) = 1;
    //cout << v.size() << "\n";
    // v.front(); v.back()
    // v.data(void)
    // v.erase(v.begin(), v.begin()+7); - apaga de um pedaço do vetor (até 7)
    
    inicializarCom1(&v);
    printaVetor(v);
    v.erase(v.begin(), v.begin()+7);
    
    //cout<< v.size() << "Foi embaixo \n";
    printaVetor(v);
    return 0;
}
