// https://codeforces.com/gym/103485/problem/A

#include <bits/stdc++.h>
typedef long long ll;
//#define debug(VAR) cout << #VAR << " = " << VAR << endl;

using namespace std;

vector<double> sides;

int main()
{
	ll n;
	vector<ll> x, y, v_dx, v_dy;
	
	cin >> n;
	for(ll i = 0; i < n; i++)
	{
		ll xi, yi;
		cin >> xi >> yi;
		x.push_back(xi);
		y.push_back(yi);
		// v_dx.push_back(0);
		// v_dy.push_back(0);
	}

	for(ll i = 0; i < n; i++)
	{
		ll id_this = i, id_next = (i + 1) % n; 
		ll ldx = x[id_next] - x[id_this]; 
		ll ldy = y[id_next] - y[id_this]; 

		v_dx.push_back(ldx);
		v_dy.push_back(ldy);

		//cout << "--------------" << endl;

		//debug(ldx);
		//debug(x[id_this]);
		//debug(x[id_next]);

		double dx = ldx;
		double dy = ldy;

		//debug(dx);
		//debug(dy);

		double side = sqrt(dx * dx + dy * dy);
		//debug(side);

		sides.push_back( side );
	}

	// for(double side : sides)
	// {
	// 	//debug(side);
	// }

	//cout << "============" << endl;
	for(ll i = 0; i < n; i++)
	{
		ll ref_dx = v_dx[i], ref_dy = v_dy[i];
		double len = sides[i];

		for(ll j = 0; j < n; j++)
		{
	//cout << "============" << endl;
			//debug(i);
			//debug(j);

			ll id = (j + i + 1) % n;

			ll mx = v_dx[id] * ref_dx; 
			ll my = v_dy[id] * ref_dy; 
			ll dot = mx + my; // produto escalar

			//debug(v_dx[id]);
			//debug(v_dy[id]);
			//debug(ref_dx);
			//debug(ref_dy);

			//debug(i);
			//debug(mx);
			//debug(my);
			//debug(dot);

			
			if(dot <= 0)
			{
				break;
			}

			len += sides[id];
			//debug(len);
		}

		cout << setprecision(20) << len << endl;
	}

	return 0;
}