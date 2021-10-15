// https://codeforces.com/problemset/problem/1276/B

#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
//#include <queue>
#include <algorithm>

using namespace std;

// struct node
// {
// 	unordered_set<long> adjs;
// 	//bool dirty;
// };

// node construct_node(unordered_set<long> adjs)
// {
// 	node n;
// 	n.adjs = adjs;

// 	//n.dirty = false;

// 	return n;
// }

unordered_set<long> paint_nodes(map<long, unordered_set<long> > graph, long begin, long end)
{
	unordered_set<long> painted_nodes = {};
	unordered_set<long> remaining_nodes = { begin };

	while(!remaining_nodes.empty())
	{
		long next_node = *(remaining_nodes.begin());

		painted_nodes.insert(next_node);

		for(long adj_node : graph[next_node])
		{
			if(adj_node != end && painted_nodes.find(adj_node) == painted_nodes.end())
			{
				// if not end AND not painted yet
				remaining_nodes.insert(adj_node);	
			}
		}
	}	

	return painted_nodes;
}

set<long> diff_sets(set<long> s1, set<long> s2)
{
	set<long> s3;

	set_difference(s1.begin(), s1.end(),
             s2.begin(), s2.end(),
             inserter(s3, s3.begin()));
			
	return s3;
}

void print_set(set<long> s)
{
	for(long el : s)
	{
		cout << el << " ";
	}
	cout << endl;
}

unsigned long long solve(map<long, unordered_set<long> > graph, long a, long b)
{
	unordered_set<long> us_a = paint_nodes(graph, a, b);
	unordered_set<long> us_b = paint_nodes(graph, b, a);

	set<long> a_paint, b_paint;

	for(long el : us_a) a_paint.insert(el);
	for(long el : us_b) a_paint.insert(el);

	set<long> a_exclusive = diff_sets(a_paint, b_paint);
	set<long> b_exclusive = diff_sets(b_paint, a_paint);

	cout << "------------\nprinting sets" << endl;
	print_set(a_paint);
	print_set(b_paint);
	print_set(a_exclusive);
	print_set(b_exclusive);
	cout << "-----------" << endl;


	return 0;
}

void add_edge(map<long, unordered_set<long> > *graph, long v1, long v2)
{

	if(graph->find(v1) == graph->end())
	{
		unordered_set<long> s = {};

		(*graph)[v1] = s;
	}

	(*graph)[v1].insert(v2);
}

int main()
{
	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long n, m, a, b;
		cin >> n >> m >> a >> b;

		map< long, unordered_set<long> > graph;

		for (int j = 0; j < m; j++)
		{
			long v1, v2;
			cin >> v1 >> v2;

			add_edge(&graph, v1, v2);
			add_edge(&graph, v2, v1);
		}
		
		unsigned long long ans = solve(graph, a, b);
		cout << ans << endl;
		//cout << "-------------------------------" << endl;
	}
	

	return 0;
}