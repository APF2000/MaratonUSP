// https://www.urionlinejudge.com.br/judge/pt/problems/view/1093


#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	int EV1, EV2, AT, D;
	
	cin >> EV1 >> EV2 >> AT >> D;
	while(EV1 && EV2 && AT && D){
		EV1 = ceil( (double) EV1/D);
		EV2 = ceil( (double) EV2/D);
		double p = AT/6.0;
		double q = 1 - p;
		double aux1;
		double aux2;
		double resp;
		//cout << "p: " << p << " q: " << q << endl;
		if (AT == 3){
			resp = (double) EV2/ (EV1 + EV2);
		}
		else{
			aux1 = pow((p/q), EV2);
			aux2 = pow((p/q), EV1 + EV2);
			resp = (1-aux1)/(1 - aux2);
			//cout << "aux1: " << aux1 << " aux2: " << aux2 << endl;
		}
		cout.precision(1);
		cout << fixed << (1 - resp)*100 << endl;
		cin >> EV1 >> EV2 >> AT >> D;
	} 
	return 0;
}
