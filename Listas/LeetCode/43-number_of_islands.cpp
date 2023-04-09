// https://leetcode.com/problems/number-of-islands/

#define LAND '1'

class Solution {
public:
    int m, n;

    int numIslands(vector<vector<char>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited_els_grid(m, vector<bool>(n, false));

        int num_islands = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                bool was_visited = visited_els_grid[i][j];
                if(was_visited) continue;

                visited_els_grid[i][j] = true;

                char grid_el = grid[i][j];

                bool is_land = (grid_el == LAND);
                if(!is_land) 
                {
                    // num_islands--;
                    continue;
                }

                queue<pair<int, int>> adj_coords_to_visit;
                adj_coords_to_visit.push({i , j});

                while(!adj_coords_to_visit.empty())
                {
                    pair<int, int> coords = adj_coords_to_visit.front();
                    adj_coords_to_visit.pop();

                    int new_i = coords.first;
                    int new_j = coords.second;

                    // dfs 2D
                    bool has_land_above =   (new_i > 0      && grid[new_i - 1][new_j] == LAND && !visited_els_grid[new_i - 1][new_j]);
                    bool has_land_below =   (new_i < m - 1  && grid[new_i + 1][new_j] == LAND && !visited_els_grid[new_i + 1][new_j]);
                    bool has_land_left =    (new_j > 0      && grid[new_i][new_j - 1] == LAND && !visited_els_grid[new_i][new_j - 1]);
                    bool has_land_right =   (new_j < n - 1  && grid[new_i][new_j + 1] == LAND && !visited_els_grid[new_i][new_j + 1]);
                    if(has_land_above)  
                    {
                        visited_els_grid[new_i - 1][new_j] = true;
                        adj_coords_to_visit.push({new_i - 1, new_j});
                    }
                    if(has_land_below)
                    {
                        visited_els_grid[new_i + 1][new_j] = true;
                        adj_coords_to_visit.push({new_i + 1, new_j});
                    }
                    if(has_land_left)
                    {
                        visited_els_grid[new_i][new_j - 1] = true;
                        adj_coords_to_visit.push({new_i, new_j - 1});
                    }
                    if(has_land_right)
                    {
                        visited_els_grid[new_i][new_j + 1] = true;
                        adj_coords_to_visit.push({new_i, new_j + 1});
                    }
                }

                num_islands++;             
            }
        }

        return num_islands;
    }
};