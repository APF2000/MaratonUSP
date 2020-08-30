#include <iostream>
#include <iomanip>

using namespace std;

#define BLOCK '*'
#define PASS ' '
#define FREE ' '

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

char** createMatrix(int n, char** bar)
{
    int rows = (4 * n - 1), cols = (4 * n + 1);
    char** M = new char*[rows];

    cout << "Matrix: \n";

    for(int i = 0; i < rows; i++)
    {
        M[i] = new char[cols];
        cout << "Linha " << setw(2) << i << ": ";

        for(int j = 0; j < cols; j++)
        {
            int im2 = i % 2, im4 = i % 4;
            int jm2 = j % 2, jm4 = j % 4;
            int ijm4 = (i + j) % 4;

            if(im2 == 0 && jm2 == 0) M[i][j] = FREE; 
            else if(im2 == 1 && jm2 == 1 && ijm4 == 2) M[i][j] = BLOCK;
            else
            {
                //int row = i / 2, col = j / 4;
                //if(i == rows - 1) row--;
                //if(j == cols - 1) cols--;

                //char conf = bar[row][col];

                bool v1 = j < cols - 1 && (im4 == 0 || im4 == 2) && jm4 == 1;
                bool v3 = i < rows - 1 && i > 1 && j < cols -1 && (im4 == 0 || im4 == 2) && jm4 == 3;

                bool h1 = j < cols - 2 && (jm4 == 0 || jm4 == 2) && im4 == 1;
                bool h3 = i < rows - 1 && j > 1 && (jm4 == 0 || jm4 == 2) && im4 == 3;

                //cout << "[id4=" << id4 << ", jd4=" << jd4 << "]";
                if(i == 6){// && j == 3){
                    //cout << "\n";
                }

                if(v1 && bar[2 * (i / 4)][(j-1) / 4] == VERT) M[i][j] = BLOCK;
                else if(v3 && bar[2 * ((i - 2) / 4) + 1][(j-1) / 4] == VERT) M[i][j] = BLOCK;

                else if(h1 && bar[2 * (i / 4)][(j / 4)] == HOR) M[i][j] = BLOCK;
                else if(h3 && bar[2 * (i / 4) + 1][(j-2) / 4] == HOR) M[i][j] = BLOCK;

                /* Vertical
                if(j > 0 && jm4 != 1) col = (j - 1) / 4;
                else col = j / 4;

                if(i > 0 && im4 != 1) row = (i - 1) / 4;
                else row = i / 4;*/

                /*int conf = bar[row][col];

                // Vertical
                if( (im4 == 0 || im4 == 2) && jm4 == 1 && conf == VERT) M[i][j] = BLOCK;
                else if( (im4 == 0 || im4 == 2) && /*(i > 0 && i < rows - 1)*/ /*&& jm4 == 3 && conf == VERT) M[i][j] = BLOCK;

                // Horizontal
                else if( (jm4 == 0 || jm4 == 2) && im4 == 1 && conf == HOR) M[i][j] = BLOCK;
                else if( (jm4 == 0 || jm4 == 2) && /*(j > 0 && j < cols - 1) &&*//* im4 == 3 && conf == HOR) M[i][j] = BLOCK;
                */
                // Transitions
                else M[i][j] = PASS;
            }

            cout << M[i][j];//<< ", ";
        }
        cout << "\n";
    }

    cout << "\nFim\n";
    //cin >> rows;

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