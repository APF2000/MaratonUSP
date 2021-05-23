// https://codeforces.com/problemset/problem/1517/D

#include <iostream>
#include <vector>
#include <map>
#define INF 0xffffffff
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define R_DIR {0,1}
#define L_DIR {0,-1}
#define U_DIR {-1,0}
#define D_DIR {1,0}
using namespace std;
//map<int, vector<int> > DIR = {{UP, [0, 1]}, {DOWN, [0,-1]}, {LEFT, [-1, 0]}, {RIGHT, [1,0]}};
//map<int, (*int) > DIR = {{UP, {0, 1}}, {DOWN, {0,-1}}, {LEFT, {-1, 0}}, {RIGHT, {1,0}}};
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
    3
    4 2

    * 1 *
    4   2
    * 3 *
*/

class solver{
public:
  int m,n;
  vector< vector<int> > updown;
  vector< vector<int> > rl;

  bool can_move(int dir, int *x, int *y){
    vector<int> dir_mov = DIR[dir];
    int aux_x = *x;
    int aux_y = *y;
    aux_x+= dir_mov[0];
    aux_y+=dir_mov[1];
    if(aux_x < m && aux_x >= 0 && aux_y < n && aux_y >= 0){
      *x = aux_x;
      *y =  aux_y;
      return true;
    }
    return false;
  }
  int calc_cost(int dir, int x, int y){
    vector<int> dir_mov = DIR[dir];
    //x += dir_mov[0];
    //y += dir_mov[1];
    switch (dir){
      case UP: return updown[x-1][y];
      case DOWN: return updown[x][y];
      case LEFT: return rl[x][y-1];
      case RIGHT: return rl[x][y];
      default return INF
    }
    return 0;
  }

  int min_path(int x, int y, int x_fut, int y_fut, int cost, int k){
    if(k%2 == 1) return -1;
    if(k == 0) {
      if (x == x_fut && y == y_fut) return cost;
      else return INF;
    }
    vector<int> costs;
    for(int dir : {UP,DOWN,LEFT,RIGHT}){
      int aux_x = x;
      int aux_y = y;
      int new_cost = INF;
      if(can_move(dir, &aux_x, &aux_y)){
        new_cost = min_path(aux_x, aux_y, x_fut, y_fut, cost+calc_cost(dir,x,y), k-2);
      }
      costs.push_back(new_cost);
      cout << dir << endl;
    }
    int min = *min_element(costs.begin(), costs.end());
    return min+cost;
  }
};
int main()
{
    int n, m, k;
    int i,j, temp;
    cin >> n >> m >> k;
    solver solver_obj;
    solver_obj.m = m;
    solver_obj.n = n;
    for (int i = 0; i < n; i++)
    {
      vector<int> v;
      for (int j = 0; j < m - 1; j++)
      {
          cin >> temp;
          v.push_back(temp);
      }
      solver_obj.updown.push_back(v);
    }

    for (int i = 0; i < n - 1; i++)
    {
      vector<int> v;
      for (int j = 0; j < m ; j++)
      {
        cin >> temp;
        v.push_back(temp);
      }
      solver_obj.rl.push_back(v);
    }
    cout << solver_obj.can_move(UP, 0,0) << endl;
    cout << solver_obj.can_move(DOWN, 0,0) << endl;
    cout << solver_obj.can_move(LEFT, 0,0) << endl;
    cout << solver_obj.can_move(RIGHT, 0,0) << endl;


    return 0;
}
