#include <stdio.h>
#include <stdlib.h>

int permutacao_ok(int first, int n)
{
	int permutacao[n];
	int i, j;
	int pivot, menor, sequence;

	permutacao[0] = first;

	for(i = 1; i < n; i++)
	{
		scanf("%d", &first);
		permutacao[i] = first;
	}
	
	for(i = 0; i < n; i++)
	{
		pivot = permutacao[i];
		menor = pivot;
		for(j = i + 1; j < n; j++)
		{	
			sequence = permutacao[j];
			if(sequence < pivot)
			{
				if(sequence < menor) menor = sequence;
				else return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);

	int first;
	while(n!= 0)
	{

		scanf("%d", &first);
		while(first != 0)
		{
			printf("%s\n", (permutacao_ok(first, n) ? "Yes" : "No"));
			scanf("%d", &first);
		}
		
		printf("\n");
		scanf("%d", &n);
	}

	return 0;
}
