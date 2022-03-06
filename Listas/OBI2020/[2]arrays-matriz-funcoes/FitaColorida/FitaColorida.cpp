//https://neps.academy/br/exercise/49
#include <vector>
#include <iostream>

using namespace std;
#define INF 10


int main()
{
    int n;
    cin >> n ;
    vector<int> vec;
    int aux;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vec.push_back(aux);
    }
    vector<int> dists(n);
    int dist;
    //Indo para direita
    dist = INF;
    for ( int i = 0; i < n; i++)
    {
        if(vec[i]==0){
          dist = 1;
          dists[i] = 0;
        } else{
          dists[i] = dist;
          if(dist < 9){
            dist++;
          }
        }
    }
    //Indo para esquerda
    dist = INF;
    for ( int i = n - 1; i >= 0; i--) {
      /* code */
      if(vec[i]==0){
        dist = 1;
      } else{
        if(dist < dists[i]){
          dists[i] = dist;
        }
        if(dist < 9){
          dist++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      /* code */
      cout << dists[i] << " ";
    }
    cout << endl;
    return 0;
}
