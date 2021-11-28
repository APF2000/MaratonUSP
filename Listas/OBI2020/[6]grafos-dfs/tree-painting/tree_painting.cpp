// https://codeforces.com/problemset/problem/1187/E

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << ", ";

long n;
long count = 0;
unordered_map<long, unordered_map<long, long>> scores, qttys;
unordered_map<long, unordered_set<long>> not_visited, conns;
unordered_map<long , long> fathers;

void add_score(long v1, long v2)
{
	if(conns.find(v1) == conns.end())
	{
		conns[v1] = {};
		//visited[v1] = {};
	}

	DEBUG(v1);
	DEBUG(v2);
	cout << endl;

	conns[v1].insert(v2);


	if(scores.find(v1) == scores.end())
	{
		scores[v1] = {};
		qttys[v1] = {};
	}


	scores[v1][v2] = -1;
	qttys[v1][v2] = -1;
}

void initial_score(long root, long req_node, long *score, long *qtty)
{
	long new_score = 1;
	long new_qtty = 1;

	for(long child : conns[req_node])
	{
		long c_node = child;
		long c_score = scores[req_node][c_node];
		long c_qtty = qttys[req_node][c_node];

		if(c_node == root) continue;

		DEBUG(c_node);
		DEBUG(req_node);
		cout << endl;


		if(c_score == -1 || c_qtty == -1)
		{
			count++;
			initial_score(req_node, c_node, &c_score, &c_qtty);

			scores[req_node][c_node] = c_score;
			qttys[req_node][c_node] = c_qtty;

			fathers[c_node] = req_node;
			cout << "------------------" << endl;
			for(pair<long, long> aux : fathers)
			{
				DEBUG(aux.first);
				DEBUG(aux.second);
				cout << endl;
			}
		}	

		new_qtty += c_qtty;
		new_score += (c_score + c_qtty);
	}

	*score = new_score;
	*qtty = new_qtty;
}

int main()
{
	cin >> n;
	for (long i = 0; i < n - 1; i++)
	{
		long v1, v2;
		cin >> v1 >> v2;
		

		add_score(v1, v2);
		add_score(v2, v1);
	}

	
	long new_score, new_qtty;
	initial_score(1, 1, &new_score, &new_qtty);
	scores[0][1] = new_score;
	qttys[0][1] = new_qtty;

	unordered_set<long> children = conns[1], visited;
	while(!children.empty())
	{
		long child = *( children.begin() );
		long father = fathers[child];

		children.erase(child);
		//visited.insert(child);

		for(long grand_child : conns[child])
		{
			//if(visited.find(grand_child) != visited.end()) continue;
			if(grand_child == father) continue;

			children.insert(grand_child);
		}

		// rerooting
		long sc_father = scores[father][child];
		long qt_father = qttys[father][child] - 1;
		long qt_other_children = 0;

		for(long brother : conns[father])
		{
			if(brother == child) continue;

			DEBUG(brother);
			qt_other_children += qttys[father][brother];
		}

		long score_except_my_subtree = sc_father - (qt_father - 1);
		long new_score = score_except_my_subtree + qt_other_children;

		scores[child][father] = score_except_my_subtree;
		qttys[child][father] = qt_father;

		DEBUG(child);
		DEBUG(father);

		DEBUG(sc_father);
		DEBUG(qt_father);
		DEBUG(qt_other_children);
		DEBUG(score_except_my_subtree);
		DEBUG(new_score);

		cout << endl;

		int aaaaaaaaaaaaaaaa;
		cin >> aaaaaaaaaaaaaaaa;
	}
	
	//long max_score = -1;
	//if(new_score > max_score) max_score = new_score;


	// cout << max_score << endl;
	// cout << count << endl;

	return 0;
}