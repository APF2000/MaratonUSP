#include <iostream>
#include <iomanip>

using namespace std;

#define BLOCK 'H'
#define PASS ' '
#define FREE ' '

#define V 'H'
#define H '='

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

int minMoves(char** M, char **bar, int n)
{
    int rows = (2 * n), cols = (2 * n + 1);


    return 0;
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