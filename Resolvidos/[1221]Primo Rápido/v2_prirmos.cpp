#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int index_element(vector<int> vec, int element)
{
	int pos = lower_bound(vec.begin(), vec.end(), element) - vec.begin();
	if(pos >= vec.size()) return -1;
	if(vec.at(pos) == element) return pos;
	return -1;
}

vector<int> primos = {2};
bool is_prime(int num)
{
	if(num <= primos.back())
	{
		int result = index_element(primos, num);
		if(result == -1) return false;
		return true;
	}

	vector<int>::iterator it;
	int last_prime;
	for(it = primos.begin(); it < primos.end(); it++)
	{
		last_prime = (*it);
		if(num % last_prime == 0) return false;
		if(last_prime * last_prime > num) return true;
	}
	for(int i = last_prime + 1; i * i <= num; i++)
	{
		cout << i << "\n";
		if(is_prime(i))
		{
			primos.push_back(i);
			if(num % i == 0) return false;
		}
	}
	return true;
}



int main(int argc, char **argv)
{
	int n;

	cin >> n;
	for(int i=0; i < n; i++){
		int num;
		cout << "Primos ate agora : ";
		for(vector<int>::iterator it = primos.begin(); it != primos.end(); ++it) {
   			cout << (*it) << ", "; 		
		}
		cout << "\n";
		cin >> num;
		cout << /*num << " : " <<*/ (is_prime(num) ? "Prime" : "Not Prime" ) << '\n';
	}
	return 0;
}
