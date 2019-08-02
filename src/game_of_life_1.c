#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int M,N; /*numero di righe e colonne*/
int **c; /*matrice configurazione*/


int** matrice(int M,int N) /*assegna la memoria per una matrice*/
{
	int i;
	int **matrix;
	matrix=calloc(M,sizeof(int *));
	for(i=0;i<M;i++) matrix[i]=calloc(N,sizeof(int));
	return matrix;
}

int casuale(int min,int max) /*genera un numero casuale intero*/
{
  int nc;
  nc=min+(rand()%(max-min+1));
  return nc;
}

void inizio() /*definisce i paramentri iniziali*/
{
    M=10;
    N=10;
    c=matrice(M,N);

    srand(time(0));
}

void regole(int sum,int i,int j) /*regole del gioco*/
{
    if(sum==2 || sum==3) c[i][j]=1;
    else c[i][j]=0;
}

int main()
{
    int i,j,a,b;
    int sum;

    inizio();

    /*creazione configurazione iniziale casuale*/
    for(i=0;i<M;i++) for(j=0;j<N;j++) c[i][j]=casuale(0,1);

    /*stampa configurazione iniziale*/
    printf("Inizio:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d",c[i][j]);
        }
        printf("\n");
    }

    /*calcolo somma primi 8 vicini di ogni cella per regole*/
    int x,y;
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
                    if(x>=0 && x<M && y>=0 && y<N) sum+=c[x][y];
                }
            }
            regole(sum,i,j);
        }
    }
    printf("\n");

    /*stampa configurazione finale*/
    printf("Fine:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d",c[i][j]);
        }
        printf("\n");
    }

    free(c);

    return 0;
}
