// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_to_qtty;

        for(int num : nums)
        {
            bool hasNumAsKey = (num_to_qtty.find(num) != num_to_qtty.end());
            if(hasNumAsKey)  num_to_qtty[num]++;
            else{
                num_to_qtty[num] = 1;
            }
        }

        vector<pair<int, int>> vec_aux;
        for(pair<int, int> p : num_to_qtty)
        {
            pair<int, int> inverted_p = {p.second, p.first};
            vec_aux.push_back(inverted_p);
        }
        sort(vec_aux.begin(), vec_aux.end());

        vector<int> ans;
        int n = vec_aux.size();
        for(int i = n - k; i < n; i++)
        {
            int pop_num = vec_aux[i].second;
            ans.push_back(pop_num);
        }

        return ans;
    }
};