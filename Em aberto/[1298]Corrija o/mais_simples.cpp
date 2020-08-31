#include <iostream>
#include <iomanip>

using namespace std;

#define BLOCK 'H'
#define FREE ' '
#define ERROR 'E'

enum Direction { R, L, U, D, HALT};
/*#define PASS ' '

#define V 'H'
#define H '='*/

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

char direction(char **M, char **bar, int i, int j, int rows, int cols)
{
    int row, col;
    int id2 = i / 2, jd2 = j / 2;

    // Black tile
    if( (i + j) % 2 == 0)
    {
        // First line
        if(i == 0)
        {
            if(j < cols -1)
            {
                // Right blocked
                if(bar[i][jd2] == VERT)
                {
                    if(M[i][j - 1] == BLOCK) return D;
                    return L;
                }
                // Down blocked
                else
                {
                    if(M[i][j - 1] == BLOCK) return R;
                    return L;
                }
            }
            // Up-right corner
            if(M[i][j - 1] == BLOCK) return D;
            return L;
        }

        // Last line
        else if(i == rows - 1)
        {
            if(j < cols -1)
            {
                // Left blocked
                if(bar[i - 1][jd2] == VERT) // i - 1 => standarize line of barrel
                {
                    if(M[i - 1][j] == BLOCK) return R;
                    return U;
                }
                // Up blocked
                else
                {
                    if(M[i][j - 1] == BLOCK) return R;
                    return L;
                }
            }
            // Bottom-right corner
            if(M[i][j - 1] == BLOCK) return U;
            return L;
        }

        // First column
        else if(j == 0)
        {
            if(i > 0 && i < rows -1)
            {
                // Right blocked
                if(bar[i][jd2] == VERT)
                {
                    if(M[i - 1][j] == BLOCK) return D;
                    return U;
                }
                // Down blocked
                else
                {
                    if(M[i - 1][j] == BLOCK) return R;
                    return U;
                }
            }
            
            // End of maze
            return HALT;
        }

        // Last column
        else if(j == cols - 1)
        {
            if(i > 0 && i < rows -1)
            {
                // Left blocked
                if(bar[i][jd2 - 1] == VERT) // j/2 - 1 => Standarize last col barrel
                {
                    if(M[i - 1][j] == BLOCK) return D;
                    return U;
                }
                // Up blocked
                else
                {
                    if(M[i][j - 1] == BLOCK) return L;
                    return D;
                }
            }            
        }

        /*/ Middle tile
        else
        {
            // Right blocked
            if(bar[i][jd2] == VERT)
            {
                // Left blocked
                if(bar[i - 1][jd2] == VERT)
                {
                    if(M[])
                }
            }
            // Down blocked
            else
            {
                
            }
            
        }*/
    }
    // White tile
    else
    {

    }

    return ERROR;
}

int minMoves(char** M, char **bar, int n)
{
    int rows = (2 * n), cols = (2 * n + 1);
    int count = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(M[i][j] == BLOCK) continue;

            int ii = i, jj = j;
            while(M[ii][jj] == FREE)
            {
                M[ii][jj] = BLOCK;

                switch (direction(M, bar, ii, jj, rows, cols))
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

int main()
{ 
    char **M, **bar;
    int n;
    int result;

    while(cin >> n)
    {
        bar = createBar(n);

        M = createMatrix(2 * n, 2 * n + 1);

        cout << "M[0][0] = " << M[0][0] << "\n"; 
        //result = minMoves(M);

        freeMatrix(M, 2 * n);
    }

    return 0;
}