// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> spiral_order_vec(m * n);

        bool is_moving_in_row = true;
        bool is_movin_reverse = false;


        int global_i = 0, global_j = 0;
        int low_row_border = 0, high_row_border = m - 1;
        int low_col_border = 0, high_col_border = n - 1;


        for(int k = 0; k < m * n; k++)
        {            
            spiral_order_vec[k] = matrix[global_i][global_j];

            bool has_to_turn = false;
            
            if(is_moving_in_row && !is_movin_reverse)
            {
                if(global_j == high_col_border)
                {
                    has_to_turn = true;
                    low_row_border++;
                    global_i++;
                }else
                {
                    global_j++;
                }
            }
            else if(!is_moving_in_row && !is_movin_reverse)
            {
                if(global_i == high_row_border)
                {
                    has_to_turn = true;
                    high_col_border--;
                    global_j--;
                }else
                {
                    global_i++;
                }
            }
            else if(is_moving_in_row && is_movin_reverse)
            {
                if(global_j == low_col_border)
                {
                    has_to_turn = true;
                    high_row_border--;
                    global_i--;
                }else
                {
                    global_j--;
                }
            }else
            {
                if(global_i == low_row_border)
                {
                    has_to_turn = true;
                    low_col_border++;
                    global_j++;
                }else
                {
                    global_i--;
                }
            }

            if(has_to_turn)
            {
                // xnor between bools
                is_movin_reverse = !(is_movin_reverse ^ is_moving_in_row);
                is_moving_in_row = !is_moving_in_row;
            }
        }

        return spiral_order_vec;
    }
};