// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    bool is_palindrom(string s)
    {
        int n = s.size();
        int mid_id = (n % 2) ? (n / 2 - 1) : (n / 2);

        for(int i = 0; i <= mid_id; i++)
        {
            if(s[i] != s[n - 1 - i]) return false;
        }

        return true;
    }

    string longestPalindrome(string s) 
    {
        //int window_size = 1;
        //string ans = s.substr(0, 1); 
        queue<pair<int, int>> q_pairs = {};
        //queue<string> q_sub_s; 
        int size = (int) s.size();

        for(int i = 2; i <= 3; i++)
        {
            for(int j = 0; j <= size - i; j++)
            {
                string sub_s = s.substr(j, i);

                if(is_palindrom(sub_s))
                {
                    pair<int, int> p(j, j + i - 1);
                    q_pairs.push(p);
                    //q_sub_s.push(sub_s);
                    //break;
                }
            }
        }

        pair<int, int> p(0, 0);
        while(!q_pairs.empty())
        {
            p = q_pairs.front();
            q_pairs.pop();

            int beg_s = p.first, end_s = p.second;
            if(beg_s == 0 || end_s == size - 1) continue;
            if(s[beg_s - 1] != s[end_s + 1]) continue;

            pair<int, int> new_p(beg_s - 1, end_s + 1); 
            q_pairs.push(new_p);

            //window_size = end_s - beg_s + 2; //max(window_size, end_s);
        }

        int beg_s = p.first, end_s = p.second;
        string ans = s.substr(beg_s, end_s - beg_s + 1);

        return ans;
    }
};