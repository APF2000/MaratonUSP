// https://codeforces.com/problemset/problem/1517/D

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define INF 0xffff //ffff
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define U_DIR {-1, 0}
#define D_DIR {1, 0}
#define L_DIR {0, -1}
#define R_DIR {0, 1}

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
  vector< vector<int> > updown;
  vector< vector<int> > rl;
  vector< vector< map<int, int> > > mem_costs;

  solver (int n, int m){
    this->n = n;
    this->m = m;

    int temp;
    for (int i = 0; i < n; i++)
    {
      vector<int> v;
      for (int j = 0; j < m - 1; j++)
      {
          cin >> temp;
          v.push_back(temp);
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
    if(aux_x < m && aux_x >= 0 && aux_y < n && aux_y >= 0){
        //cout << "(" << *x << ", " << *y << ") -> (" << aux_x << ", " << aux_y << ") e valido" << endl;

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

  int min_path(int x, int y, int x_fut, int y_fut, int cost, int k){
    if(k % 2 == 1) return -1;
    if(k == 0) {
      /*if (x == x_fut && y == y_fut)*/ return cost;
      //else return INF;
    }
    vector<int> costs = {};
    for(int dir : {UP,DOWN,LEFT,RIGHT}){
      int aux_x = x;
      int aux_y = y;
      int new_cost = INF;
      if(can_move(dir, &aux_x, &aux_y)){
        int tmp_cost = calc_cost(dir,x,y);
        if(tmp_cost != INF) tmp_cost += tmp_cost + cost; // soma tmp com ele mesmo para contar ida e volta
        //tmp_cost *= 2;

        //cout << "Chamando min_path(" << aux_x << ", " << aux_y << ", " << x_fut << ", " << y_fut << ", " << tmp_cost << ", " << k-2 << "){" << endl;
        if(cost_was_calc(aux_x, aux_y, k)){
          new_cost = mem_costs[aux_x][aux_y][k];
          //cout << "Valor ja existia: mem_costs[" << aux_x << "][" << aux_y << "][" << k << "] == " << new_cost << endl;
        }
        else{
          new_cost = min_path(aux_x, aux_y, x_fut, y_fut, tmp_cost, k-2);
          mem_costs[aux_x][aux_y][k] = new_cost;
          //cout << "Novo valor : mem_costs[" << aux_x << "][" << aux_y << "][" << k << "] = " << new_cost << endl; 
        }
        //cout << "} (" << k << ")" << endl;
        //cout << "Para a pos = (" << aux_x << ", " << aux_y << ") =>  cost antigo: " << tmp_cost << "; newcost: " << new_cost << endl;

      }
      costs.push_back(new_cost);
      //cout << dir << endl;
    }
    //int min = *(min_element(costs.begin(), costs.end()));
    sort(costs.begin(), costs.end());
    int min = costs[0];
    //cout << "Min cost: " << min << endl;//", max: " << costs[3] << endl;

    return min;// + cost;
  }
};
int main()
{
    int n, m, k;
    int i,j;
    cin >> n >> m >> k;

    solver *solver_obj = new solver(n, m);    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //cout << "Custo maximo (" << i << ", " <<  j << "): " 
            cout << solver_obj->min_path(i, j, i, j, 0, k) << " ";
        }
        cout << endl;
    }
    

    return 0;
}
