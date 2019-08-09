#include <stdio.h>
#include <stdlib.h>

struct punto{
   int x,y;
};

int M,N; /*numero di righe e colonne*/
int tmax; /*numero di generazioni*/
char scelta;
int **c; /*matrice della configurazione*/
int **ctemp; /*matrice temporanea della configurazione*/
FILE *parametri,*inizio,*fine;

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
    int x0=0.5*M;
    int y0=0.5*N;
    struct punto p[10];
    inizio=fopen("inizio.dat","w");
	if(scelta=='1') /*Pentomino-R*/
    {
        imax=5;
		p[0].x=x0;   p[0].y=y0;
		p[1].x=x0;   p[1].y=y0+1;
		p[2].x=x0+1; p[2].y=y0+1;
		p[3].x=x0;   p[3].y=y0-1;
		p[4].x=x0-1; p[4].y=y0;
    }
    if(scelta=='2') /*Tetramino-T*/
    {
        imax=4;
        p[0].x=x0;   p[0].y=y0;
		p[1].x=x0-1; p[1].y=y0;
		p[2].x=x0+1; p[2].y=y0;
		p[3].x=x0;   p[3].y=y0-1;
    }
    for(i=0;i<imax;i++)
    {
        c[p[i].x][p[i].y]=1;
        fprintf(inizio,"%d %d\n",p[i].x,p[i].y);
        ctemp[p[i].x][p[i].y]=c[p[i].x][p[i].y];
    }
}

void definizioni() /*definisce i parametri e la configurazione iniziali*/
{
    parametri=fopen("parametri.dat","r");
    fscanf(parametri,"%d %d %d %c",&M,&N,&tmax,&scelta);
    fclose(parametri);
    c=matrice(M,N);
    ctemp=matrice(M,N);
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
	fine=fopen("fine.dat","w");
	int i,j,t;
    int a,b,x,y,sum;
    for(t=1;t<=tmax;t++)
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
				if(c[i][j]==1) fprintf(fine,"%i %i %i\n",i,j,t);
            }
        }
    }
}

int main()
{
	definizioni();

	gioco();

	fclose(inizio);
    fclose(fine);
    free(c);
	free(ctemp);

	return 0;
}
