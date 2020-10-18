#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

#include "word.h"
#include "printer.h"
#include "letter.h"

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

                    Word *w = new Word(x_ini, y_ini, x_fim,  y_fim, "");
                    spots.push_back(w);
                }
            }
            
        }
        
        if(lendo_espaco) 
        {
            x_fim = x_ini;
            y_fim = y_ini;
            Word *w = new Word(x_ini, y_ini, x_fim, y_fim, "");
            spots.push_back(w);
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

                    Word *w = new Word(x_ini, y_ini, x_fim, y_fim, "");
                    spots.push_back(w);
                }
            }
            
        }

        if(lendo_espaco) 
        {
            x_fim = x_ini;
            y_fim = y_ini;
            Word *w = new Word(x_ini, y_ini, x_fim, y_fim, "");
            spots.push_back(w);
        }
        

    }        

    return spots;
} 

int word_size(Word *w)
{
    int x_ini = w->x_ini, y_ini = w->y_ini;
    int x_fim = w->x_fim, y_fim = w->y_fim;
    int tam_x, tam_y;
    
    tam_x = x_fim - x_ini + 1;
    tam_y = y_fim - y_ini + 1;

    if(tam_x == 1) return tam_y;
    return tam_x;
}

bool word_size_fits(Word *w, Word *spot)
{
    return ( word_size(spot) == (w->w).length() );
}

bool spot_greater_than(Word *w1, Word *w2)
{
    return ( word_size(w1) > word_size(w2) );
}

vector<vector<char>>* solve_puzzle(vector<vector<char>> map, vector<string> wordlist, vector<Word*> spots)
{
    // Backtracking :(

    stack<Letter*> pilha;
    //vector<Word*> spots = find_spots(map, m, n);

    Printer *p = new Printer();

    cout << "Antes:\n";
    p->print_vector(spots);
    sort(spots.begin(), spots.end(), spot_greater_than);
    cout << "\n Depois:\n";
    p->print_vector(spots);

    return NULL;
}

int main()
{
    //stack<Word*> pilha;
    Word *batata, *nabo;

    batata = new Word(1, 10, 1, 15, "Batata");
    nabo = new Word(2, 4, 5, 10, "Nabo");

    //pilha.push(pal1);
    //pilha.push(pal2);

    int m, n;
    cin >> m >> n;
    vector<vector<char>> map = criar_mapa(m, n);
    //cout << "Printar mapa \n";
    //print_map(map, m, n);
    //showstack(pilha);
    Printer *p = new Printer();

    vector<Word*> spots = find_spots(map, m, n);
    //p->print_vector(spots);

    //cout << "Batata fits ? " << word_size_fits(batata, spots[25]) << "\n";
    //cout << "Nabo fits ? " << word_size_fits(nabo, spots[25]) << "\n";

    int qtde_palavras;
    vector<string> wordlist;

    cin >> qtde_palavras;
    for(int i = 0; i < qtde_palavras; i++)
    {
        string aux;
        cin >> aux;

        wordlist.push_back(aux);
    }

    vector<vector<char>> *sol = solve_puzzle(map, wordlist, spots);

    if(!sol) cout << "Deu ruim, nao tem como\n";
    else cout << "Deu bom, e aqui esta : \n";

    //p->print_vector_strings(wordlist);

    return 0;
}