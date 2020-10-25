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

vector<Word*> find_spots_in_line(vector<vector<char>> map, int m, int n)
{
    vector<Word*> spots;
    bool lendo_espaco;
    int x_ini, y_ini;
    int x_fim, y_fim;

    // Ver palavras na horizontal
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
        
        if(lendo_espaco) 
        {
            x_fim = x_ini;
            y_fim = y_ini;
            Word *w = new Word(x_ini, x_fim, y_ini, y_fim, "");
            spots.push_back(w);
        }
    }

    return spots;
}

vector<Word*> find_spots(vector<vector<char>> map, int m, int n)
{
    vector<Word*> spots;
    bool lendo_espaco;
    int x_ini, y_ini;
    int x_fim, y_fim;
    
    spots = find_spots_in_line(map, m, n);
    //spots = find_spots_in_line(map, n, m);

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