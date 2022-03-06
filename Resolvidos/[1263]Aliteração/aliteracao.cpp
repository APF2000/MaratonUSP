#include <iostream>
#include <string>

#include <stdio.h>

using namespace std;

int main(){

    string input;
    string espaco = " ";
    int contador = 0;

    cin >> input;

    for (unsigned i=0; i<input.length(); ++i){
        cout << "'" << input.at(i) << "'" << "\n";
        // if (espaco == to_string(input.at(i))){
        //     cout << to_string(input.at(i-1)) << to_string(input.at(i+1));
        //     if (to_string(input.at(i-1)) == to_string(input.at(i+1))){
        //         contador ++;
        //    }
        }
    }
    
    cout << contador;
    char buffer[51] = "", lastWord[51] = "";
    char aux;
    char lastEqual = '';
    char firstLetterLastWord = ''
    int count = 0, tam = 0,ultimoEspaco = 1;

    while(scanf("%c", aux)){
        if(aux == '\n'){
            printf("%d\n", count);
            count = 0;
            ultimoEspaco = 1
            continue;
        }else if(aux = ' '){
            ultimoEspaco = 1;
        } 
        else if(ultimoEspaco){
            firstLetter = aux;
            ultimoEspaco = 0;
        }

        if(buffer[0] == lastEqual && buffer[0] != lastWord[0]){
            count ++;
        }

        printf("%s\n", buffer);

        lastEqual = lastWord[0];
        lastWord = buffer;
    }

    printf("\n%d", count);

    /*string frase;
    cin >> frase;
    string delim = " ";
    
    cout << frase.find(delim);

    while(ch != EOF){
        cin >> ch;
        cout << ch << "\n";
    }*/

    return 0;
}