#include <stdio.h>
#include <stdlib.h>

long M,N;
int **c[][N],**ctemp[][N];
FILE *risultati;

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

int incr_x(int i, int S)
{
    i=i+S;
    while (i<0) i=i+M;
    while (i>=M) i=i-M;
    return i;
}

int incr_y(int i,int S)
{
    i=i+S;
    while (i<0) i=i+N;
    while (i>=N) i=i-N;
    return i;
}

int cont_adiac(int ctemp[M][N],int i,int j)
{
    int u,k,cont;

    cont = 0;
    for (u=-1;u<=1;u++)
    {
        for (k=-1;k<=1;k++) if (u!=0 || k!=0) cont++;
    }
    return cont;
}

void gioco()
{
    int i,j,S;
    int c[M][N];

    for (i=0;i<M;i++)
    {
        for (j=0;j<N;j++)
        {
            S=cont_adiac(board, i, j);
            if (S==2) c[i][j]=ctemp[i][j];
            if (S==3) c[i][j]=1;
            if (S<2) c[i][j]=0;
            if (S>3) c[i][j]=0;
        }
    }

    for (i=0;i<M;i++) for (j=0;j<N;j++) c[i][j]=ctemp[i][j];
}

void stampa()
{
    int i,j;

    risultati=fopen("risultati.dat","w");
	if(risultati==NULL)
	{
		printf("Errore nell'apertura del file. Il programma sarà chiuso.\n");
		exit(0);
	}

	for (i=0;i<M;i++) for(j=0;j<N;j++) fprintf("%i\n",c[i][j]);
}

int main()
{
    long t,i,j;

	inizio();

    c=(int *)calloc(N,sizeof(int));
    ctemp=(int *)calloc(N,sizeof(int));

    void gioco();

    void stampa();

    free(c);
    free(ctemp);

    exit(0);
}
