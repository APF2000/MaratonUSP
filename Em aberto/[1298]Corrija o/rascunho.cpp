#include <iostream>

using namespace std;

#define BLOCK '*'
#define PASS '-'
#define FREE 'f'

char** createBar(int n)
{
    int rows = n, cols = (2 * n - 1);
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

char** createMatrix(int n, char** bar)
{
    int rows = (4 * n - 1), cols = (4 * n + 1);
    char** M[rows][cols];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            //if()
        }
    }

    return M;
}

int main()
{ 
    char **M, **bar;
    int n;
    int result;

    while(cin >> n)
    {
        bar = createBar(n);

        M = createMatrix(n, bar);

        cout << "M[0][0] = " << M[0][0] << "\n"; 
        //result = minMoves(M);
    }

    return 0;
}