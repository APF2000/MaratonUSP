// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) 
    {
        int count_palindromes = 0;

        for(int start_id = 0; start_id < s.size(); start_id++)
        {
            for(int end_id = start_id; end_id < s.size(); end_id++)
            {
                // check if s[start_id : end_id] is palindrome
                int size_sub_s = end_id - start_id + 1;
                bool is_palindrome = true;

                for(int sub_s_id = 0; sub_s_id < size_sub_s / 2; sub_s_id++)
                {
                    char beg_sub_s_ch = s[start_id + sub_s_id];
                    char end_sub_s_ch = s[end_id - sub_s_id];
                    if(beg_sub_s_ch != end_sub_s_ch) 
                    {
                        is_palindrome = false;
                        break;
                    }
                }

                if(is_palindrome)
                {
                    count_palindromes++;
                }
            }
        }

        return count_palindromes;
    }
};