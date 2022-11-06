// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define dv(v) cout << #v << " = "; for(auto el : v) cout << el << ", "; cout << endl;
#define dm(m) cout << #m << " = "; for(auto v : m) { for(auto el : v) cout << el << ", ";  cout << endl; }

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> num_to_index; 

        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int complement = target - num;

            bool found_complement = (num_to_index.find(complement) != num_to_index.end());
            if(found_complement)
            {
                int prev_index = num_to_index[complement];
                vector<int> sol = {prev_index, i};
                return sol;
            }

            num_to_index[num] = i;
        }

        return {};
    }
};

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> sol = Solution::twoSum(nums, target);
    dv(nums);
    dv(sol);

	return 0;
}