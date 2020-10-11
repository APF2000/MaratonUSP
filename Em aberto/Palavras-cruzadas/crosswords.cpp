#include <iostream>
#include <stack>
#include <vector>
#include "word.h"
#include "printer.h"

#define BLOCK '*'
#define EMPTY '_'

#define INTERSECT '+'
#define WORDEND '|'

using namespace std;

vector<vector<char>> criar_mapa(int m, int n)
{
    vector<vector<char>> map(m);
    //cout << "Comecando a montar mapa";

    for(int i = 0; i < m; i++)
    {
        //cout << "linha " << i << "\n";
        map[i].resize(n);

        for(int j = 0; j < n; j++)
        {
            int aux;
            cin >> aux;

            if(aux == -1) map[i][j] = BLOCK;
            else map[i][j] = EMPTY;
        }
    }

    return map;
} 

vector<Word*> find_spots(vector<vector<char>> map, int m, int n)
{
    vector<Word*> spots;
    bool lendo_espaco;
    int x_ini, y_ini;
    int x_fim, y_fim;
    
    // Ver palavras na horizontal
    //Ver palavras na horizontal
    for(int i = 0; i < m; i++)
    {
        lendo_espaco = false;
        for(int j = 0; j < n; j++)
        {
            if(!lendo_espaco && map[i][j] == EMPTY)
            {
                lendo_espaco = true;
                x_ini = i;
                y_ini = j;
            }
            else if(lendo_espaco)
            {
                bool cond1 = (map[i][j] == BLOCK);
                bool cond2 = (j == n - 1);                
                
                if(cond1 || cond2)
                {
                    lendo_espaco = false;
                    x_fim = i;
                    if(cond1) y_fim = j - 1;
                    else if(cond2) y_fim = j;    

                    Word *w = new Word(x_ini, x_fim, y_ini, y_fim, "");
                    spots.push_back(w);
                }
            }
            
        }

    }        

    // Vertical
    for(int j = 0; j < n; j++)
    {
        lendo_espaco = false;
        for(int i = 0; i < m; i++)
        {
            if(!lendo_espaco && map[i][j] == EMPTY)
            {
                lendo_espaco = true;
                x_ini = i;
                y_ini = j;
            }
            else if(lendo_espaco)
            {
                bool cond1 = (map[i][j] == BLOCK);
                bool cond2 = (i == m - 1);                
                
                if(cond1 || cond2)
                {
                    lendo_espaco = false;
                    y_fim = j;
                    if(cond1) x_fim = i - 1;
                    else if(cond2) x_fim = i;    

                    Word *w = new Word(x_ini, x_fim, y_ini, y_fim, "");
                    spots.push_back(w);
                }
            }
            
        }

    }        

    return spots;
} 

int main()
{
    stack<Word*> pilha;
    Word *pal1, *pal2;

    pal1 = new Word(1, 10, 1, 15, "Batata");
    pal2 = new Word(2, 4, 5, 10, "Nabo");

    pilha.push(pal1);
    pilha.push(pal2);

    int m, n;
    cin >> m >> n;
    vector<vector<char>> map = criar_mapa(m, n);
    //cout << "Printar mapa \n";
    //print_map(map, m, n);
    //showstack(pilha);
    Printer *p = new Printer();

    vector<Word*> spots = find_spots(map, m, n);
    p->print_vector(spots);

    return 0;
}