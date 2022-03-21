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
bool compare_with_primos(int size, int num)
{
          	bool is_primo = true;
                for(int j = 0; j < size; j++)
                {
                        int primo = primos[j];
                        if(num % primo == 0) // N e primo
                        {
                        	return false;
                        }
                        if(primo * primo >= num) break; // E primo
                }
		return is_primo;

}

bool e_primo(int num)
{
	int size = primos.size();
	int topo = primos[size - 1]; 
	if(index_element(primos, num) == -1)
	{
	      	if(topo > num) return false;
	}else
	{
		return true;
	}
	
	if(!compare_with_primos(size, num)) return false; 

	bool is_primo, found_next_primo = false;
	for(int i = topo + 1; i <= num; i++)
	{
		is_primo = compare_with_primos(size, i);
	
		if(is_primo)
		{ 
			primos.push_back(i);
			size++;

			if(i == num)
                        {
                                return true;
                        }else
                        {
                                if(i > num) found_next_primo = true;
                        }

			topo = primos[size - 1];
			if(num % topo == 0) return false;
		}

	}	
	return false;
}

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	for(int i=0; i < n; i++){
		int num;
		cin >> num;
		cout << num << " : " << (e_primo(num) ? "Prime" : "Not Prime" ) << '\n';
	}
	return 0;
}
