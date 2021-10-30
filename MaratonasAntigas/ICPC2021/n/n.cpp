#include <bits/stdc++.h>

using namespace std;

struct competitor
{
	long a, p, f;
};

struct ranking
{
	long id, xi;
	ranking *next;
};

bool ord_competitor(competitor c1, competitor c2)
{
	return (c1.f < c2.f);
}

// bool ord_ranking(ranking r1, ranking r2)
// {
// 	return (r1.xi < r2.xi);
// }

int main()
{
	long y, n, xi, azar = 0;
	ranking *root_rs, *last_r = NULL;
	unordered_map<long, ranking*> mp;

	cin >> y >> n;

	//cout << "ok1 " << endl;
	for(long i = 0; i < y; i++){
		ranking *r = new ranking();
		cin >> r->xi;
		r->id = i;
		r->next = NULL;

		if(i == 0) root_rs = r;
		else
		{
			last_r->next = r;
		}

		last_r = r;
		mp[i] = r;
	}

	// check
	// ranking *aux = rs;
	// while(aux != nULL)
	// {
	// 	cout << "r: " << aux->xi << endl;
	// 	aux = aux->next;
	// }

	vector<competitor> cs;
	for(long i = 0; i < n; i++){
		long a, p, f;
		cin >> a;
		cin >> p;
		cin >> f;

		competitor c;
		c.a = a;
		c.p = p;
		c.f = f;

		cs.push_back(c);

		//cout << "a = " << a << endl;
		//cout << "f = " << f << endl;
		//cout << "a+f= " << a+f << endl;
		// for(long j = a; j < a+f; j++){
		// 	//cout << "j = " << j << " x[j] = " << x[j] << endl;
		// 	//cout << "x[j]-p " << x[j] - p << endl;
		// 	if(x[j]-p >= 0) azar++;
		// }
		// if(x[a-1]-p >= 0){
		// 	azar = 0;
		// }
		// cout << azar << endl;
		// azar = 0;	
	}

	sort(cs.begin(), cs.end(), ord_competitor); // n log n
	//sort(rs.begin(), rs.end(), ord_ranking); // y log y

	for(competitor c : cs)
	{
		//ranking *last_r_for_c;// = mp[c.p];
		long count = 0;

		for (long i = c.a; i < c.a + c.f; i++)
		{
			if(mp.find(i) != mp.end()) // achou no map
			{
				ranking *aux_r = mp[i];
				if(aux_r->xi < c.p) // se a classificacao pra passar eh mais competitiva
				{
					mp.erase(i);
					mp[i - 1]->next = mp[i + 1]; // religa a lista ligada
				}else
				{
					count ++;
				}
			}
		}

		cout << count << endl;
		
	}

	return 0;
}