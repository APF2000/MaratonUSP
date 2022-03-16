// https://www.codechef.com/HCKATHON/problems/PAR

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n ; i ++){
		cout << "Caso " << i << endl << endl;
		int numMob;
		cout << "Esperando numMob" << endl;
		cin >> numMob;
		int nextMobExpected = numMob;
		stack<int> orderedMobs;
		stack<int> waitTurnMobs;

		int temp;
		vector<int> v;
		for(int k = 0; k < numMob; k++){
			cin >> temp;
			v.push_back(temp);
		}

		for (int j = 0; j < numMob; j++){
			int mob;
			mob = v[j];
			waitTurnMobs.push(mob);
			if(mob == nextMobExpected){
				//orderedMobs.push(mob);
				//nextMobExpected--;
				if(!waitTurnMobs.empty()){
					while(nextMobExpected == waitTurnMobs.top() ){
						waitTurnMobs.pop();
						orderedMobs.push(nextMobExpected);
						nextMobExpected--;
						if(waitTurnMobs.empty()){
							break;
						}
					}
				}
			}
			cout << "j vale " << j << endl;
		}
			cout << "verificando caso" << endl;
		  if(orderedMobs.size()==numMob){

 		 		cout << "yes" << endl;
 	    } else {
				cout << "no" << endl;
			}
	 }

	 return 0;
	}

// test cases
/*
1
10
1 2 3 6 5 4 7 8 10 9

no




5
5
5 1 2 4 3
5
5 4 3 2 1
5
1 2 3 4 5
5
5 1 3 2 4
5
1 4 2 5 3

expected

yes
yes
yes
no
no

6
3
1 2 3
3
1 3 2
3
2 1 3
3
2 3 1
3
3 2 1
3
3 1 2

expected
yes
yes
no
yes
yes
yes
*/
