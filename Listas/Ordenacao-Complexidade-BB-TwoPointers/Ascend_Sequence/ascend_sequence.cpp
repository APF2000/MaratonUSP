//https://codeforces.com/contest/1284/problem/B
#include <vector>
#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> cards;
    int dir,esq;
    int sereja = 0, dima = 0;
    int aux;
    bool vez_sereja = true;
    for(int esq = 0; esq < n; esq++ ){
      cin >> aux;
      cards.push_back(aux);
    }
    while(cards.size() > 0){
      esq = cards[0];
      dir = cards[cards.size() - 1];
      if(esq > dir){
        aux = esq;
        cards.erase(cards.begin());
      } else {
        aux = dir;
        cards.pop_back();
      }
      if(vez_sereja){
        sereja+=aux;
        vez_sereja = false;
      } else{
        dima += aux;
        vez_sereja = true;
      }
    }
    cout << sereja << " " << dima << endl;
    return 0;
}
/*
7
1 2 3 4 5 6 7
*/
