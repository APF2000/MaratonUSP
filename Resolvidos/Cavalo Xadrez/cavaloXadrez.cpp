#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


bool isValid(char letra, char num){

    if (letra > 'h' || letra < 'a')
        return false;
    
    if (num > '8' || num < '1')
        return false;

    return true;
}

void moverCavalo(char *letra, char*num, int move){
    switch (move % 8)
    {
    case 0: 
        // 1 direita, 2 cima
        (*letra)++; (*num) += 2;  break;
    case 1: 
        // 2 direita, 1 cima
        (*letra) += 2; (*num)++;  break;
    case 2: 
        // 2 direita, 1 baixo
        (*letra) += 2; (*num)--;  break;
    case 3: 
        // 1 direita, 2 baixo
        (*letra) ++; (*num) -= 2;  break;
    case 4: 
        // 1 esquerda, 2 baixo
        (*letra)--; (*num) -= 2;  break;
    case 5: 
        // 2 esquerda, 1 baixo
        (*letra) -= 2; (*num)--;  break;
    case 6: 
        // 2 esquerda, 1 cima
        (*letra) -= 2; (*num)++;  break;
    case 7: 
        // 1 esquerda, 2 cima
        (*letra)--; (*num) += 2;  break;
    default:
        (*letra)++;
        (*num) += 2;
    }
}

vector<string> listValidSquares(string posicao){

    vector<string> movimentos;
    string letraNum = "__";

    for(int i = 0; i < 8; i++){
        letraNum[0] = posicao[0];
        letraNum[1] = posicao[1];
        
        moverCavalo(&letraNum[0], &letraNum[1], i);

        if( isValid(letraNum[0], letraNum[1]) ){
            movimentos.push_back(letraNum);
        }

    }

    return movimentos;
}

int minimoMovimentos(string comeco, string fim, vector<string> fila){
        
    int count = 0;

    while(true){

        vector<string>::iterator it1, it2;
        vector<string> auxFila;
        for(it1 = fila.begin(); it1 != fila.end(); it1++){
          
            if( (*it1)[0] == fim[0] && (*it1)[1] == fim[1] ){
                return count;
            }

            vector<string> squaresToGo = listValidSquares(*it1);

            for(it2 = squaresToGo.begin(); it2 != squaresToGo.end(); it2++){
                auxFila.push_back((*it2));
            }
        }

        fila = auxFila;

        count++;
    }

    return 0;
}

int main(){

    string comeco, fim;

    while(cin >> comeco >> fim){
        int count = 0;

        vector<string> fila;
        fila.push_back(comeco);
        count = minimoMovimentos(comeco, fim, fila);
        
        cout << "To get from " << comeco << " to " << fim;
        cout << " takes " << count << " knight moves.\n";
    }

    return 0;
}

int minPassos(string comeco, string fim){
    string posicaoAtual = comeco;
    int count = 0;
    queue<string> movimentosPossiveis;
    vector<string> movAPartirDaqui;
    string aumentarContagem = comeco;
    movimentosPossiveis.push(comeco);
    do{
        posicaoAtual = movimentosPossiveis.front();
        movimentosPossiveis.pop();
        if(fim[0] == posicaoAtual[0]&&fim[1] == posicaoAtual[1]){
            return count;
        }
        movAPartirDaqui = listValidSquares(posicaoAtual);
        if(posicaoAtual[0]==aumentarContagem[0] && posicaoAtual[1] == aumentarContagem[1]){
            count++;
            aumentarContagem = movAPartirDaqui.back();
        }
    
        for(int i = 0; i < movAPartirDaqui.size(); i++){
            movimentosPossiveis.push(movAPartirDaqui[i]);
        }
    }while(true);




    /*if(podeIr){
        vector<string> squaresToGo = listValidSquares(comeco);
        vector<string>::iterator it1;
        //(*count)++;
        for(it1 = squaresToGo.begin(); it1 != squaresToGo.end(); it1++){
            
            if(minimoMovimentos((*it1), fim, count, false, fila)){
                (*count)++;
                return true;
            }
        }

        for(it1 = squaresToGo.begin(); it1 != squaresToGo.end(); it1++){
            
            if(minimoMovimentos((*it1), fim, count, true, fila)){
                (*count)++;
                return true;
            }
        }
            
            /*if((*it1)[0] == fim[0] && (*it1)[1] == fim[1]){
                (*count)++;
                cout << "Deu bom " << comeco << " " << fim << "\n";
                return true;
            } */
        //return false;
    //}

    /*if(podeIr){
        for(it1 = squaresToGo.begin(); it1 != squaresToGo.end(); it1++)
            if( minimoMovimentos((*it1), fim, count, false) ){
                (*count)++;
                return true;
            }

        //(*count)++;    
        
        /*for(it1 = squaresToGo.begin(); it1 != squaresToGo.end(); it1++)
            if( minimoMovimentos((*it1), fim, count, true) ){
                (*count)++;
                return true;
            } 
    }*/

}