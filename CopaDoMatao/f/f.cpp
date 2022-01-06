// https://codeforces.com/gym/103485/problem/F

#include <bits/stdc++.h>
typedef unsigned long ul;
#define DEBUG(x) cout << #x << " = " << x << endl;

using namespace std;

struct rad{
	ul rad;
	ul id;
};

bool foo(rad r1, rad r2)
{
	return r1.rad < r2.rad;
}

vector<ul> get_primes(ul num)
{
	vector<ul> primes;
    primes.push_back(2);

    for(ul i=3; i < num; i++)
    {
        bool prime=true;
        for(ul j=0;j<primes.size() && primes[j]*primes[j] <= i;j++)
        {
            if(i % primes[j] == 0)
            {
                prime=false;
                break;
            }
        }
        if(prime) 
        {
            primes.push_back(i);
        }
    }
	return primes;
}


vector<ul> pots;
unordered_set<ul> nums;
vector<rad> rads;
vector<ul> resps;

ul n, q;
ul max_num = 0;

int main()
{
	cin >> n >> q;
	for(ul i = 0; i < n; i++)
	{
		ul num;
		cin >> num;
		nums.insert(num);

		if(num > max_num) max_num = num;
	}
	
	for(ul i = 0; i < q; i++)
	{
		rad r;
		cin >> r.rad;
		r.id = i;

		rads.push_back(r);
		resps.push_back(0);
	}

	sort(rads.begin(), rads.end(), foo);
	
	// for (ul i = 0; i < max_num; i++)
	// {

	// 	pots.push_back(i + 1);
	// }
	pots = get_primes(max_num);
	
	for(ul primo : pots)
	{
		DEBUG(primo);
	}

	//DEBUG(max_num);

	vector<ul> aux_pots = pots;
	ul rad_ate_agora = 1;
	for(rad r : rads)
	{
		ul count = 0;

		//cout << "================" << endl;
		//DEBUG(r.rad);

		for (ul i = 0; i < pots.size(); i++)
		{
			ul aux = pots[i];

			//cout << "---------------------" << endl;

			// DEBUG(i);
			// //DEBUG(r.id);

			// DEBUG(aux);
			for (ul j = rad_ate_agora; j < r.rad; j++)
			{
				aux *= aux_pots[i];
				//DEBUG(aux);
			}
			pots[i] = aux;

			if(nums.find(aux) != nums.end()) // achou
			{
				count++;
			}

			if(aux >= max_num) break;
		}		
		rad_ate_agora = r.rad;
		resps[r.id] = count;
	}

	for(ul resp : resps)		
	{
		cout << resp << endl;
	}

	return 0;
}