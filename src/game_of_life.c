#include <stdio.h>
#include <stdlib.h>

long tmax,M,N;
char **c;

void inizio()
{
    printf("Inserire il tempo di esecuzione: ");
	scanf("%li",&tmax);
	while(tmax<=0)
	{
		printf("Il valore deve essere maggiore di zero. Reinserire: ");
		scanf("%li",&tmax);
	}

	printf("Inserire il numero di righe: ");
	scanf("%li",&M);
	while(M<=0)
	{
		printf("Il valore deve essere maggiore di zero. Reinserire: ");
		scanf("%li",&M);
	}

	printf("Inserire il numero di colonne: ");
	scanf("%li",&N);
	while(M<=0)
	{
		printf("Il valore deve essere maggiore di zero. Reinserire: ");
		scanf("%li",&N);
	}
}

int main()
{
    long t,i,j;
	FILE *risultati;

	inizio();

    c=(char *)calloc(N,sizeof(char));



    free(c);

    exit(0);
}
