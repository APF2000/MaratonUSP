#include "printer.h"

void Printer::print_map(vector<vector<char>> map, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        cout << "Linha " << i << " : "; 
        for(int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void Printer::print_vector(vector<Word*> spots)
{
    for(int i = 0; i < spots.size(); i++)
    {
        Word *aux = spots[i];

        cout << "spots[" << aux->x_ini << " -> " << aux->x_fim << "]"; 
        cout << "[" << aux->y_ini  << " -> " << aux->y_fim << "]";
        cout << " = " << aux->w << '\n'; 
    }
}

void Printer::print_vector_strings(vector<string> wordlist)
{
    for(int i = 0; i < wordlist.size(); i++)
    {

        cout << i << " : " << wordlist[i] << "\n";
    }
}

void Printer::showstack(stack <Word*> s) 
{ 
    while (!s.empty()) 
    { 
        Word *aux = s.top();

        cout << "tab[" << aux->x_ini << " -> " << aux->x_fim << "]"; 
        cout << "[" << aux->y_ini << " -> " << aux->y_fim << "]";
        cout << " = " << aux->w << '\n'; 
        s.pop(); 
    } 
    cout << '\n'; 
} 
