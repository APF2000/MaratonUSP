#include <stdio.h>

int main(){
	char buffer[52];
	int aux;

	while((aux = scanf("%51s", buffer)) != EOF){
		printf("%s %d\n", buffer, aux);
	}

	printf("\n%d", aux);

	return 0;
}
