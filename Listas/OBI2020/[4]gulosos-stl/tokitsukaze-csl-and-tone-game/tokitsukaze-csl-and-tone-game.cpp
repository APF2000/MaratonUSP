// https://codeforces.com/contest/1191/problem/D

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

bool ganhei(long n,long soma){
	long sum_pa = ((n - 1)*n)/2;
	return (soma - sum_pa)%2;
}
int main()
{
	long n;
	cin >> n;
	vector<long> pilhas;
	long temp;
	long soma = 0;
	for(long i = 0; i < n ; i ++){
		cin >> temp;
		pilhas.push_back(temp);
		soma+=temp;
	}
	long repetido_id;
	sort(pilhas.begin(), pilhas.end());
	int cresc = -1;
	for(long i = 1; i < n ; i ++){
		if(pilhas[i-1] == pilhas[i]){
			repetido_id = i - 1;
			cresc++;
		}
	}
	if(cresc > 0){
		cout << "cslnb" << endl;
		return 0;
	} else if (cresc == 0){
		if((pilhas[repetido_id - 1] == pilhas[repetido_id]-1) || pilhas[repetido_id] == 0){
			cout << "cslnb" << endl;
			return 0;
		} 
		// soma--
	}
	if (ganhei(n,soma)){
		cout << "sjfnb" << endl;
	} else {
		cout << "cslnb" <<endl;
	}
	return 0;
}

/*pilha_ideal + 3*n
3 4 4 5 | 16 - 6 = 10 => 0 1 1 2   1 2 3 4 5  6 7 8
3 4 5 6
3 4 4 6 | 17 - 6 = 11 => 0 1 1 3     jogador1         
2 4 4 5 => 2 3 4 5 => 14 - 6 = 8     jogador2     

jogador2 1 3 4 5 
jogador1 1 2 4 5
jogador2 0 2 4 5
jogador1 0 1 4 5
jogador2 0 1 3 5
jogador1 0 1 2 5
jogador2 0 1 2 4
jogador1 0 1 2 3 */