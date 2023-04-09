// https://leetcode.com/problems/two-sum/

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