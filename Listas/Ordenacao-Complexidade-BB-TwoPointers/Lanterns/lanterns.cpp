//https://codeforces.com/problemset/problem/492/B
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
    int n,l;
    double rad;
    cin >> n >> l ;
    vector<int> vec(n);
    int aux;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vec[i]= aux;
    }
    sort(vec.begin(),vec.end());
    if(vec[0] > l-vec[n-1]){
      rad = vec[0];
    } else {
      rad = l - vec[n-1];
    }
    for (int i = 0; i < n-1; i++) {
      /* code */
      double dist_inter = (double)(vec[i+1] - vec[i])/2;
      if(dist_inter > rad){
        rad = dist_inter;
      }
    }
    cout << setprecision(9) << rad << endl;
    return 0;
}
