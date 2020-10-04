#include <iostream>
#include <vector>

#define INF 10000

using namespace std;

vector<vector<int>> criarGrafo(int n, int k)
{
    vector<vector<int>> grafo(n);
    int x, y, h;

    // Criando o grafo
    for(int i = 0; i < n; i++)
    {
        grafo[i].resize(n);
        
        for(int j = 0; j < n; j++)
        {
            if(i != j) grafo[i][j] = INF;
        }
    }

    // Colocar as arestas do enunciado no grafo
    for(int i = 0; i < k; i++)
    {
        cin >> x >> y >> h;
        grafo[x - 1][y - 1] = h;
    }
    
    return grafo;
}

void solveGrafo(vector<vector<int>> *grafo, int n)
{

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((*grafo)[i][j] < INF && (*grafo)[j][i] < INF)
                {
                    (*grafo)[i][j] = 0;
                    (*grafo)[j][i] = 0;
                }

                int aux = (*grafo)[i][k] + (*grafo)[k][j];
                int fodase;

                if((*grafo)[i][j] > aux) (*grafo)[i][j] = aux;
            }
        }
    }
}

int main()
{
    int n, k;
    vector<vector<int>> grafo;

    cin >> n >> k;
    while( !(n == 0 && k == 0) )
    {
        grafo = criarGrafo(n, k);
        solveGrafo(&grafo, n);

        int t;
        cin >> t;

        for(int i = 0; i < t; i++)
        {
            int x, y;
            cin >> x >> y;

            if(grafo[x - 1][y - 1] != INF) cout << grafo[x - 1][y - 1] << "\n";
            else cout << "Nao e possivel entregar a carta\n";   
        }

        cout << "\n";
        cin >> n >> k;
    }

    return 0;
}

