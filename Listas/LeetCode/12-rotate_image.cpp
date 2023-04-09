// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // m[i][j] -> m[j][n - i - 1]
        int n = matrix.size();

        for(int i = 0; i < (n << 1) + (n % 2); i++)
        {
            for(int j = 0; j < (n << 1); j++)
            {   
                int next_i = j;
                int next_j = n - i - 1;

                for(int k = 0; k < 4; k++)
                {
                    int aux = matrix[i][j];
                    matrix[i][j] = matrix[next_i][next_j];
                    matrix[next_i][next_j] = aux;

                    int aux_next_i = next_i;
                    next_i = next_j;
                    next_j = n - aux_next_i - 1;
                }
            }
        }
    }
};