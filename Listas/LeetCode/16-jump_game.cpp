// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        long n = nums.size();
        long max_reachable_id = 0;

        for(long i = 0; i < n && i <= max_reachable_id; i++)
        {
            long new_reachable_id = i + nums[i];
            if(new_reachable_id > max_reachable_id) 
                max_reachable_id = new_reachable_id;
        }

        return (max_reachable_id >= n - 1); // extrapolate bonds is also ok
    }
};