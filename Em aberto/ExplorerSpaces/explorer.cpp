// https://codeforces.com/problemset/problem/1517/D
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAX_K 20
#define MAX_CELL 1000 * 1000
#define INF MAX_K * MAX_CELL
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define U_DIR {-1, 0}
#define D_DIR {1, 0}
#define L_DIR {0, -1}
#define R_DIR {0, 1}

using namespace std;

map<int, vector< int > > DIR = {{UP, U_DIR}, {DOWN, D_DIR}, {LEFT, L_DIR}, {RIGHT, R_DIR}};


/*
3 3 10
1 1
1 1
1 1
1 1 1
1 1 1

    * 1 * 1 *
    1   1   1
    * 1 * 1 *
    1   1   1
    * 1 * 1 *

2 2 4
1
1
1 1

    2 2 4
    1
    3
    4 2

    * 1 *
    4   2
    * 3 *
*/

class solver{
public:
  int m, n;
  int t_x, t_y, t_k;
  int min_cost;
  vector< vector<int> > updown;
  vector< vector<int> > rl;
  vector< vector< map<int, int> > > mem_costs;

  solver (int n, int m){
    this->n = n;
    this->m = m;
    min_cost = INF;
    int temp;
    for (int i = 0; i < n; i++)
    {
      vector<int> v;
      for (int j = 0; j < m - 1; j++)
      {
          cin >> temp;
          v.push_back(temp);
          if(temp < min_cost) min_cost = temp;
      }
      rl.push_back(v);
    }

    for (int i = 0; i < n - 1; i++)
    {
      vector<int> v;
      for (int j = 0; j < m ; j++)
      {
        cin >> temp;
        v.push_back(temp);
        if(temp < min_cost) min_cost = temp;
      }
      updown.push_back(v);
    }

    map<int, int> aux_map;
    for (int i = 0; i < n; i++)
    {
      vector< map<int, int> > v;
      for (int j = 0; j < m; j++)
      {
        v.push_back(aux_map);
      }
      mem_costs.push_back(v);
    }

  }

  bool cost_was_calc(int x, int y, int k){
    map<int, int> m = mem_costs[x][y];
    return( m.find(k) != m.end() );
  }

  bool can_move(int dir, int *x, int *y){
    vector<int> dir_mov = DIR[dir];
    int aux_x = *x;
    int aux_y = *y;
    aux_x+= dir_mov[0];
    aux_y+=dir_mov[1];
    if(aux_x < n && aux_x >= 0 && aux_y < m && aux_y >= 0){
      *x = aux_x;
      *y =  aux_y;

      return true;
    }
    return false;
  }
  int calc_cost(int dir, int x, int y){
    switch (dir)
    {
        case UP: return updown[x - 1][y];
        case DOWN: return updown[x][y];
        case RIGHT: return rl[x][y];
        case LEFT: return rl[x][y - 1];
        default: return -INF;
    }
  }

  int min_path(int x, int y, int k){
    if(k % 2 == 1) return -1;
    if(k == 0) return 0;

    int total_cost = INF*2;
    int aux_k = k -2;

    for(int dir : {UP,DOWN,LEFT,RIGHT}){
      int aux_x = x;
      int aux_y = y;

      int new_cost = INF;

      if(can_move(dir, &aux_x, &aux_y)){

        int move_cost = calc_cost(dir,x,y);
        if(move_cost != INF) move_cost = (2 * move_cost); // x2 para contar ida e volta

        bool t_was_calc = cost_was_calc(t_x, t_y, t_k);
        int next_cell_cost = INF;
        if(cost_was_calc(aux_x, aux_y, aux_k)){
          next_cell_cost = mem_costs[aux_x][aux_y][aux_k];
        } 
        else{
          bool found_min_cost = false;
          if(t_was_calc){
           found_min_cost = (move_cost + aux_k*min_cost < mem_costs[t_x][t_y][t_k]);
          }
          if(!found_min_cost){
            next_cell_cost = min_path(aux_x, aux_y, aux_k);
            mem_costs[aux_x][aux_y][aux_k] = next_cell_cost;
          }
          else{
            //next_cell_cost = INF+2*min_cost;
          }
        }

        new_cost = next_cell_cost + move_cost;

        if(new_cost < total_cost) total_cost = new_cost;
        if(x == t_x && y == t_y && k == t_k ){
          if(!t_was_calc || total_cost < mem_costs[t_x][t_y][t_k]){
             mem_costs[t_x][t_y][t_k] = total_cost;
          }
        }
      }
    }

    return total_cost;
  }

  void define_target(int _t_x, int _t_y, int _t_k){
    t_x = _t_x;
    t_y = _t_y;
    t_k = _t_k;
  }
};
int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    solver *solver_obj = new solver(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            solver_obj->define_target(i,j,k);
            cout << solver_obj->min_path(i, j, k) << " ";
        }
        cout << endl;
    }


    return 0;
}
