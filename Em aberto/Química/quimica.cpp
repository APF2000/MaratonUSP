#include <iostream>

#include<vector>
#include <string>

using namespace std;

typedef struct node
{
	node *left;
	node *right;
	
	string substance;
}node, *Node;

int main()
{
	//node *a, *b, *c;
	Node a, b, c;
	node d;

	//a = new Node(NULL, NULL, "abc");

	cout << a;
	cout << b;
	cout << c;
	//cout << (*a);

	cin >> (d.substance);
	cin >> a->substance;

	return 0;
}
