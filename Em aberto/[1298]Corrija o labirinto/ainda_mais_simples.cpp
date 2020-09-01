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
            if(j == this->cols - 1) return false; // Last col
            else if(this->M[i][j + 1] == BLOCK) return false; // Already passed there
            else if(i == 0) // First row
            {
                if(this->M[i][j + 1] != BLOCK && j % 2 == 1) return true; // Black tile
                //return false; // Nonsense
            }
            else if(i == this->rows - 1) // Last row
            {
                if(this->M[i][j + 1] != BLOCK && j % 2 == 1) return true; // Black tile
                //return false; // Nonsense
            }

            if( (i + j) % 2 == 0 && this->bar[i][j / 2] == VERT ) return false; // Barrier, black tile
            else if( (i + j) % 2 == 1 && this->bar[i - 1][j / 2] == VERT ) return false; // Barrier, white tile

            return true;
        }

        bool left(int i, int j)
        {
            if(j == 0) return false; // First col
            else if(this->M[i][j - 1] == BLOCK) return false; // Already passed there
            else if(i == 0) // First row
            {
                if(this->M[i][j - 1] != BLOCK && j % 2 == 0) return true; // Black tile
                //return false; // Nonsense
            }
            else if(i == this->rows - 1) // Last row
            {
                if(this->M[i][j - 1] != BLOCK && j % 2 == 0) return true; // White tile
                //return false; // Nonsense
            }

            if( (i + j) % 2 == 0 && this->bar[i - 1][(j - 1) / 2] == VERT ) return false; // Barrier, black tile
            else if( (i + j) % 2 == 1 && this->bar[i][(j - 1) / 2] == VERT ) return false; // Barrier, white tile

            return true;
        }

        bool up(int i, int j)
        {
            if(i == 0) return false; // First row
            else if(this->M[i - 1][j] == BLOCK) return false; // Already passed there
            else if(j == this->cols - 1) // Last col
            {
                if(this->M[i - 1][j] != BLOCK && i % 2 == 1) return true; // White tile
                return false; // Nonsense
            }
            else if(j == 0) // First col
            {
                if(this->M[i - 1][j] != BLOCK && i % 2 == 0) return true; // Black tile
                //return false; // Nonsense
            }

            if( (i + j) % 2 == 0 && this->bar[i - 1][(j - 1) / 2] == HOR ) return false; // Barrier, black tile
            else if( (i + j) % 2 == 1 && this->bar[i - 1][j / 2] == HOR ) return false; // Barrier, white tile

            return true;
        }

        bool down(int i, int j)
        {
            if(i == this->rows - 1) return false; // Last row
            else if(this->M[i + 1][j] == BLOCK) return false; // Already passed there
            else if(j == 0) // First col
            {
                if(this->M[i + 1][j] != BLOCK && i % 2 == 1) return true; // White tile
                //return false; // Nonsense
            }
            else if(j == this->cols - 1) // Last col
            {
                if(this->M[i + 1][j] != BLOCK && i % 2 == 0) return true; // Black tile
                //return false; // Nonsense
            }

            if( (i + j) % 2 == 0 && this->bar[i][j / 2] == HOR ) return false; // Barrier, black tile
            else if( (i + j) % 2 == 1 && this->bar[i][(j - 1) / 2] == HOR ) return false; // Barrier, white tile

            return true;
        }

        char direction(int i, int j)
        {
            int row, col;
            int id2 = i / 2, jd2 = j / 2;

            if(this->right(i, j)) return R;
            else if(this->left(i, j)) return L;
            else if(this->up(i, j)) return U;
            else if(this->down(i, j)) return D;

            return HALT;
        }

        int minMoves()
        {
            //int rows = (2 * n), cols = (2 * n + 1);
            int count = 0;

            for(int i = 0; i < this->rows; i++)
            {
                for(int j = 0; j < this->cols; j++)
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

            return count - 1;
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

        /*for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "M[" << i << "][" << j << "] => move = " << s->direction(i, j) << "\n";
            }            
        }*/
        
        //cout << "M[0][0] = " << M[0][0] << "\n"; 
        result = s->minMoves();
        cout << "result = " << result << "\n";

        //freeMatrix(M, rows);
    }

    return 0;
}