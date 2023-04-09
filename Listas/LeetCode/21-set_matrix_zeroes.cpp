// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        unordered_set<uint8_t> rows_to_fill, cols_to_fill;
        uint8_t m = matrix.size();
        uint8_t n = matrix[0].size();

        for(uint8_t i = 0; i < m; i++)  
        {
            for(uint8_t j = 0; j < n; j++) 
            {
                if(matrix[i][j] == 0)
                {
                    rows_to_fill.insert(i);
                    cols_to_fill.insert(j);
                }
            }
        } 

        for(uint8_t row_id : rows_to_fill)
        {
            for(uint8_t i = 0; i < n; i++) 
            {
                matrix[row_id][i] = 0;
            }
        } 

        for(uint8_t col_id : cols_to_fill)
        {
            for(uint8_t i = 0; i < m; i++) 
            {
                matrix[i][col_id] = 0;
            }
        } 
    }
};