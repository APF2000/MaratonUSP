#include <iostream>
#include <iomanip>

using namespace std;

#define BLOCK 'H'
#define FREE ' '

enum Direction { R, L, U, D };
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

char direction(char **M, char **bar, int i, int j)
{
    return ' ';
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

                switch (direction(M, bar, ii, jj))
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