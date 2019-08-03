#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct punto punto;

struct punto {
   int x;
   int y;
};

long M,N; /*numero di righe e colonne*/
long tmax; /*tempo di esecuzione o numero di generazioni*/
char r;
int **c; /*matrice configurazione*/
punto p[4];
FILE *config,*risultati;

int** matrice(int M,int N) /*assegna la memoria per una matrice*/
{
	int i;
	int **matrix;
	matrix=calloc(M,sizeof(int *));
	for(i=0;i<M;i++) matrix[i]=calloc(N,sizeof(int));
	return matrix;
}

void disegno(int x,int y,punto *p) /*disegna uno schema di punti*/
{
    int i;
    c[x,y]=1;
    for(i=0;i<4;i++)
    {
        c[x+p[i].x,y+p[i].y]=1;
        fprintf(config,"%li %li\n",x+p[i].x,y+p[i].y);
    }
}

void inizio() /*definisce i parametri iniziali*/
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
    config=fopen("config.dat","w");

    printf("Le possibili configurazioni iniziali sono: \n");
	printf("1) pentomino-R\n");
	printf("Scegliere: ");
	scanf("%c",&r);
	while(r!='1')
	{
		printf("Valore non previsto. Reinserire: ");
		scanf("%c",&r);
	}

	int x0,y0;
	x0=(int)(0.5*M);
	y0=(int)(0.5*N);

	if(r!='1')
    {
        p[4]={{1,0},{1,1},{0,-1},{-1,0}};
        disegno(x0,y0,p);
    }
}

void regole(int sum,int i,int j) /*regole del gioco*/
{
    if(sum==2 || sum==3) c[i][j]=1;
    else c[i][j]=0;
}

int main()
{
    int i,j,t;
    int sum;

    inizio();

    risultati=fopen("risultati.dat","w");

    /*calcolo somma primi vicini per regole nel tempo*/
    int a,b,x,y;
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
                        if(x>=0 && x<M && y>=0 && y<N) sum+=c[x][y];
                    }
                }
                regole(sum,i,j);
                if(c[i][j]==1) fprintf(risultati,"%li %li %li\n",i,j,t);
            }
        }
    }

    fclose(config);
    fclose(risultati);
    free(c);

    return 0;
}
