#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct node
{
	bool dir;
	long t, key;
	struct node *l, *r;
};

int main()
{
	long n;
	cin >> n;
	node batata;
	batata.r = new node();
	node last_node, first_node;

	for(int i = 0; i < n; i++){
		node no;
		cin >> no.t >> no.dir;
		no.key = no.t + 10;
		if(i = 0){
			no.l = NULL;
			first_node = no;
		}
		else if (i = n -1)
		{
			no.r = NULL;
		}
		else{
			if(no.dir != first_node.dir){
				no.l = &last_node;
				last_node.r = &no;
			}else{
				if(no.t <= no.key){
					last_node.r = &no;
					no.l = &last_node;
				}
			}
			
		}
		last_node = no;

		cout << "no(" << i << ") = " << no.t << " , " << no.dir << endl;
	}

return 0;
}