#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

/*EU ASSUMI QUE O LIDER DEVE SER SEMPRE O ULTIMO DOS MEMBROS QUE JA SE ENCONTRARAM PELO MENOS UMA VEZ*/
int existeMembro(int hierarquia[10], int membro, int tamanho){ /*Testador para ver se o numero aleatario gerado nao se repete ( hierarquias iguais) */
int i;
for(i = 0; i < tamanho; i++){
    if (membro == hierarquia[i]){
        return TRUE;
    }
}
return FALSE;
}
void GeraHierarquia(int membros, int limite, int hierarquia[10]){ /*Essa funcao gera aleatoriamente a hierarquia dos membros mas em posicoes aleatorias( nao ordenada)*/
int i, testador;
srand(time(NULL));
for (i = 0; i < membros; i++){
    hierarquia[i] = 0;
}
  for (i = 0; i < membros; i++)
  {
    testador = rand() % limite;
    while(existeMembro(hierarquia, testador, i)){
    testador = rand() % limite;
    }
     hierarquia[i] = testador;
  }
}
void encontro(int *pi, int *pj){ /*Quando um membro na posicao do ponteiro i encontra outro em j, se a hierarquia i < j , entao eles devem trocar de lugar no vetor*/
int aux;
    if( *pi <= *pj && pi >= pj){
        aux = *pi;
        *pi = *pj;
        *pj = aux;
    }
    else if( *pi >= *pj && pi <= pj){
        aux = *pi;
        *pi = *pj;
        *pj = aux;
    }
}
int ameaca(int hierarquia[10], int tamanho, int i,int poder[10]){ /*Percorre ate encontrar o lider e depois escolhe o de menor poder*/
    int anterior = hierarquia[i];
    int proximo = hierarquia[i];
    int inicio = i;
    int menorpoder = poder[inicio];
    if( i == tamanho-1){ /*Quem encontrou a ameaca eh o lider*/
        i--;
        proximo = hierarquia[i];
        while(anterior > proximo && i >= 0){ /*Se o anterior for maior que o lider, isso significa que eles nao se encontraram ainda*/
        anterior = proximo;
        i--;
        proximo = hierarquia[i];
    }
    i = i+2; /* o i esta defasado de 2 por conta dos looping */
    while(i <= inicio){
        if(poder[i] <= menorpoder)
            menorpoder = poder[i];
        i++;
    }
    }
    else if(anterior <= proximo){ /*Nesse caso eh um membro que possui um superior direto */
    while(anterior <= proximo && i < tamanho){ /*o proximo eh o "lider" para quem o detectou . Ela para quando encontrar um membro com menor hierarquia que o anterior*/
        anterior = proximo;
        i++;
        proximo = hierarquia[i];
    }
    i--;
    while(i >= inicio){ /*percorre a lista do primeiro, que chamou a funcao, at� o �ltimo com quem fora detectado*/
        if(poder[i] <= menorpoder)
            menorpoder = poder[i];
            i--;
    }
    }
    return menorpoder;
}

int main(){
    int hierarquia[10];
    int i, teste = 0;
    int poder[] = {7, 8 , 9 , 2 , 1 , 2 , 1 , 11 , 10, 6};

    srand(time(NULL));
    GeraHierarquia(10, 10, hierarquia);
    printf("Hierarquia = { ");

    for( i = 0; i < 10; i++){
        printf("%d, ", hierarquia[i]);
    }
    while( teste < 20){
        encontro(&hierarquia[rand() % 9], &hierarquia[rand()%9]);
        teste++;
    }
    printf(" }\n\n");
    printf("Hierarquia nova = { ");
    for( i = 0; i < 10; i++)
        printf("%d,  ", hierarquia[i]);
        printf(" }\n\n");
        printf("\n%d", ameaca(hierarquia, 10, 4, poder));

    return 0;
}

