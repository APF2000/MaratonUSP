//https://codeforces.com/contest/275/problem/C

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main()
{
    unsigned long long int n;
    cin >> n;
    unsigned long long int k;
    cin >> k;

		map<unsigned long long int,unsigned long long int> aux;
		for (unsigned long long int j = 0; j < n; j++)
		{
      unsigned long long int temp,tempk;
      cin >> temp;
      tempk = k*temp;
      aux.insert(pair<unsigned long long int, unsigned long long int>(temp,tempk));
		}
    for (auto const& element : aux){
        // Accessing KEY from element
        unsigned long long int word = element.first;
        // Accessing VALUE from element.
        unsigned long long int count = element.second;
        map<unsigned long long int,unsigned long long int>::iterator it = aux.find(count);
        if(it != aux.end() && k != 1){
          aux.erase(count);
        }
    }
    cout << aux.size()<< endl;
    return 0;
}
