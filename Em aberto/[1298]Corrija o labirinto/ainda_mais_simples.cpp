#include <iostream>
//#include <iomanip>
#include <vector>

using namespace std;

#define BLOCK 'H'
#define FREE ' '
#define ERROR 'E'

//enum Direction { R, L, U, D, HALT };
#define R 'R'
#define U 'U'
#define L 'L'
#define D 'D'
#define HALT 'H'

#define HOR 'H'
#define VERT 'V'

char** createBar(int n)
{
    int rows = (2 * n - 1), cols = n;
    char** bar = new char*[rows];

    for(int i = 0; i < rows; i++)
    {
        bar[i] = new char[cols];
        for(int j = 0; j < cols; j++)
        {
            cin >> bar[i][j];
        }
    }

    return bar;
}

char** createMatrix(int larg, int comp)
{
    char **M = new char*[larg];
    for(int i = 0; i < larg; i++)
    {
        M[i] = new char[comp];
        for (int j = 0; j < comp; j++) M[i][j] = ' ';        
    }
    return M;
}

void freeMatrix(char **M, int larg)
{
    for(int i = 0; i < larg; i++) delete [] M[i];       
    delete [] M;
}

class Solver
{
    /*
    M
         0 1 2 3 4
          _ _ _ _ _
       0 | | | | | |
           *   *  
       1 | | | | | |
             *   *
       2 | | | | | |
           *   *
       3 | | | | | |

    bar

        VHV
        VHV 
        VVV
        VVV
        HHH

    */


    public:
        char **M, **bar;
        int rows, cols;

        Solver(int n)
        {
            int rows = 2 * n, cols = 2 * n + 1;

            this->bar = createBar(n);
            this->M = createMatrix(rows, cols);

            this->rows = rows;
            this->cols = cols;
        }

        bool right(int i, int j)
        {
            if(j == this->cols - 1) return false;
            if( (i + j) % 2 == 0 )
            {

            }
        }

        char direction(int i, int j)
        {
            int row, col;
            int id2 = i / 2, jd2 = j / 2;

            if(this->right(i, j)) return R;

            return HALT;
        }

        int minMoves(int n)
        {
            int rows = (2 * n), cols = (2 * n + 1);
            int count = 0;

            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    if(this->M[i][j] == BLOCK) continue;

                    int ii = i, jj = j;
                    while(this->M[ii][jj] == FREE)
                    {
                        this->M[ii][jj] = BLOCK;

                        switch (direction(ii, jj))
                        {
                        case R:
                            jj++;
                            break;
                        case L:
                            jj--;
                            break;
                        case U:
                            ii--;
                            break;
                        case D:
                            ii++;
                            break;
                        
                        default:
                            break;
                        }
                    }

                    // Individual graph island
                    count++;
                }
            }

            return count;
        }
};

int main()
{ 
    //char **M, **bar;
    int n;
    int result;

    while(cin >> n)
    {
        Solver *s = new Solver(n);
        int rows = (2 * n), cols = (2 * n + 1);
        //bar = createBar(n);

        //M = createMatrix(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "M[" << i << "][" << j << "] => move = " << s->direction(i, j) << "\n";
            }            
        }
        
        //cout << "M[0][0] = " << M[0][0] << "\n"; 
        //result = minMoves(M);

        //freeMatrix(M, rows);
    }

    return 0;
}