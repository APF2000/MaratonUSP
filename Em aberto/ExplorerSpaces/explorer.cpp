// https://codeforces.com/problemset/problem/1517/D

#include <iostream>
#include <vector>
#include <map>
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define U_DIR {0,1}
#define D_DIR {0,-1}
#define L_DIR {-1,0}
#define R_DIR {1,0}
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

  bool can_move(int dir, int x, int y){
    vector<int> dir_mov = DIR[dir];
    x+= dir_mov[0];
    y+=dir_mov[1];
    return (x < m && x >= 0 && y < n && y >= 0);
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
