#include <iostream>
#include <vector>
using namespace std;
 
int main(){
	int n;
	vector<unsigned long long int> nums;
	cin >> n;
	for(int i = 0; i < n; i++){
		unsigned long long int aux;
		cin >> aux;
		nums.push_back(aux);
	}
	for(int i = 0; i < n; i++){
		unsigned long long int cont_divs = 2;
		unsigned long long int cur_num =  nums[i];
		for(unsigned long long int divs = 2; (divs*divs <= cur_num && cont_divs <= 3); divs++){
			if(cur_num % divs == 0){
				if(cur_num/divs == divs){
					cont_divs++;
				} else {
					cont_divs = cont_divs + 2;
				}
			}
		}
		if(cont_divs == 3){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}