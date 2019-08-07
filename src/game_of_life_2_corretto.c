#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int x;
   int y;
}punto;

long M,N; /*numero di righe e colonne*/
long tmax; /*numero di generazioni*/
char r;
int **c; /*matrice della configurazione*/
int **ctemp; /*matrice temporanea della configurazione*/
punto *p;
FILE *config; /*file con la configurazione iniziale*/
FILE *risultati; /*file con l'evoluzione della precedente*/

int** matrice(int M,int N) /*assegna la memoria per una matrice*/
{
	int i;
	int **matrix;
	matrix=calloc(M,sizeof(int *));
	for(i=0;i<M;i++) matrix[i]=calloc(N,sizeof(int));
	return matrix;
}

void disegno() /*disegna una configurazione di punti*/
{
    int imax,i;
    config=fopen("config.dat","w");
	if(r=='1') /*Pentomino-R*/
    {
        imax=5;
        p=calloc(imax,sizeof(punto));
		p[0].x=0; p[0].y=1;
		p[1].x=1; p[1].y=0;
		p[2].x=1; p[2].y=1;
		p[3].x=2; p[3].y=1;
		p[4].x=2; p[4].y=2;
    }
    if(r=='2') /*Tetramino-T*/
    {
        imax=4;
        p=calloc(imax,sizeof(punto));
        p[0].x=0; p[0].y=1;
		p[1].x=1; p[1].y=0;
		p[2].x=1; p[2].y=1;
		p[3].x=2; p[3].y=1;
    }
    for(i=0;i<imax;i++)
    {
        c[p[i].x][p[i].y]=1;
        fprintf(config,"%d %d\n",p[i].x,p[i].y);
        ctemp[p[i].x][p[i].y]=c[p[i].x][p[i].y];
    }
}

void inizio() /*definisce i parametri e la configurazione iniziali*/
{
    printf("Inserire il numero di righe: ");
	scanf("%li",&M);
	while(M<=0)
	{
		printf("Il valore deve essere maggiore di zero. Reinserire: ");
		scanf("%li",&M);
	}

	printf("Inserire il numero di colonne: ");
	scanf("%li",&N);
	while(N<=0)
	{
		printf("Il valore deve essere maggiore di zero. Reinserire: ");
		scanf("%li",&N);
	}

	printf("Inserire il tempo di esecuzione: ");
	scanf("%li",&tmax);
	while(tmax<=0)
	{
		printf("Il valore deve essere maggiore di zero. Reinserire: ");
		scanf("%li",&tmax);
	}

    c=matrice(M,N);
	ctemp=matrice(M,N);

    printf("Le possibili configurazioni iniziali sono: \n");
	printf("1) Pentomino-R\n");
	printf("2) Tetramino-T\n");
	printf("Scegliere:");
	scanf(" %c",&r);
	while(r!='1' && r!='2')
	{
		printf("Valore non previsto. Reinserire: ");
		scanf("%c",&r);
	}

	disegno();
}

void regole(int sum,int i,int j) /*regole da Poundstone W.,The Recursive Universe,New York,Dover Publications,2013*/
{
    if(sum==2) c[i][j]=ctemp[i][j];
    else if(sum==3) c[i][j]=1;
    else c[i][j]=0;
}

void gioco() /*evolve il sistema e stampa su file*/
{
	risultati=fopen("risultati.dat","w");

	int i,j,t;
    int a,b,x,y,sum;
    for(t=0;t<tmax;t++)
    {
        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
            {
                sum=0;
                for(a=-1;a<=1;a++)
                {
                    for(b=-1;b<=1;b++)
                    {
                        if(a==0 && b==0) continue;
                        x=i+a;
                        y=j+b;
                        if(x>=0 && x<M && y>=0 && y<N) sum+=ctemp[x][y];
                    }
                }
                ctemp[i][j]=c[i][j];
                regole(sum,i,j);
				if(c[i][j]==1) fprintf(risultati,"%i %i %i\n",i,j,t);
            }
        }
    }
}

int main()
{
	inizio();

	gioco();

	fclose(config);
    fclose(risultati);
    free(c);
	free(ctemp);
	free(p);

	return 0;
}
