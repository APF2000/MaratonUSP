// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        // create lines with n columns and default value of 1
        // because there is only 1 way to reach blocks on the same line
        vector<int> last_line(n, 1);
        vector<int> next_line(n, 1);

        for(int i = 0; i < m - 1; i++)
        {
            for(int j = 0; j < n - 1; j++)
            {
                next_line[j + 1] = next_line[j] + last_line[j + 1];
            }
            
            last_line = next_line;
        }

        return next_line[n - 1];
    }
};