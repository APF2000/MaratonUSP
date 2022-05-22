// https://codeforces.com/problemset/problem/4/B

// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

#define debug(VAR) cout << #VAR << " = " << VAR << ", ";
#define debug_ln(VAR) cout << #VAR << " = " << VAR << endl;
#define debug_v(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;

int main()
{
	int days, total_req_time;
	int min_req_time = 0, max_req_time = 0;
	vector<int> min_times, max_times;

	cin >> days >> total_req_time;
	for (int i = 0; i < days; i++)
	{
		int min_time, max_time;
		cin >>  min_time >> max_time;

		max_times.push_back(max_time);
		min_times.push_back(min_time);

		min_req_time += min_time;
		max_req_time += max_time;
	}

	if(min_req_time > total_req_time || max_req_time < total_req_time)
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	int time_sum = min_req_time;
	for (int day = 0; day < days && time_sum != total_req_time; day++)
	{
		int delta_time = max_times[day] - min_times[day];

		int temp_sum = time_sum + delta_time;

		if(temp_sum >= total_req_time)
		{
			delta_time = total_req_time - time_sum;
		}

		time_sum += delta_time;

		int new_time = min_times[day] + delta_time;
		cout << new_time << " ";
	}

	cout << endl;

	return 0;
}
