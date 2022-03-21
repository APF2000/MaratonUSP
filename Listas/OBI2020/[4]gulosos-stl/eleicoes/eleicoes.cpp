// https://br.spoj.com/problems/ELEICOES/
// Resolvido: https://br.spoj.com/status/

#include<iostream>
#include<map>

using namespace std;

int main()
{
	long n; 			// 1 <= n <= 100.000 = 10^5
	cin >> n;

	long max = -1;
	long winner = -1;
	map<long, long> cand_to_votes;
	for (long i = 0; i < n; i++)
	{
		long xi; 	// 1 < Xi ≤ 1.000.000.000 = 10^9
		cin >> xi;

		if(cand_to_votes.find(xi) == cand_to_votes.end()) // not counted yet
		{
			cand_to_votes[xi] = 1;
		}else
		{
			cand_to_votes[xi]++;
		}

		long vote_count = cand_to_votes[xi];
		if(vote_count > max)
		{
			max = vote_count;
			winner = xi;
		}
	}
	
	cout << winner << endl;

	return 0;
}