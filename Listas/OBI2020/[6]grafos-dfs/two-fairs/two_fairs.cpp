// https://codeforces.com/problemset/problem/1276/B

#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<long> paint_nodes(unordered_map<long, unordered_set<long> > graph, long begin, long end)
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

		remaining_nodes.erase(next_node);
	}	

	return painted_nodes;
}

set<long> diff_sets(set<long> s1, set<long> s2)
{
	set<long> s3;

	set_difference(
			s1.begin(), s1.end(),
        	s2.begin(), s2.end(),
        	inserter(s3, s3.begin())
	);
			
	return s3;
}

set<long> intersec_sets(set<long> s1, set<long> s2)
{
	set<long> s3;

	set_intersection(
			s1.begin(), s1.end(),
			s2.begin(), s2.end(),
			inserter(s3, s3.begin())
	);
			
	return s3;
}

unsigned long long solve(unordered_map<long, unordered_set<long> > graph, long a, long b)
{
	unordered_set<long> us_a = paint_nodes(graph, a, b);
	unordered_set<long> us_b = paint_nodes(graph, b, a);

	set<long> a_paint, b_paint;

	for(long el : us_a) a_paint.insert(el);
	for(long el : us_b) b_paint.insert(el);

	// set<long> a_exclusive = diff_sets(a_paint, b_paint);
	// set<long> b_exclusive = diff_sets(b_paint, a_paint);

	set<long> intersec = intersec_sets(a_paint, b_paint);

	unsigned long long s_a, s_b, s_i;
	s_a = us_a.size();
	s_b = us_b.size();
	s_i = intersec.size();

	return (s_a - s_i - 1) * (s_b - s_i - 1);
	//return (a_exclusive.size() - 1) * (b_exclusive.size() - 1);
}

void add_edge(unordered_map<long, unordered_set<long> > *graph, long v1, long v2)
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

		unordered_map< long, unordered_set<long> > graph;

		for (int j = 0; j < m; j++)
		{
			long v1, v2;
			cin >> v1 >> v2;

			add_edge(&graph, v1, v2);
			add_edge(&graph, v2, v1);
		}
		
		unsigned long long ans = solve(graph, a, b);
		cout << ans << endl;
	}
	

	return 0;
}