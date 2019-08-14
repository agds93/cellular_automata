#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define x0 (int)0.5*M
#define y0 (int)0.5*N

int **c,**ctemp;
FILE *results;
point p[10];

void shape(int M,int N,int scelta)
{
    int nmax,n;
    if(scelta=='1') /*Pentomino-R*/
    {
        nmax=5;
        p[0].x=x0;   p[0].y=y0;
        p[1].x=x0;   p[1].y=y0+1;
        p[2].x=x0+1; p[2].y=y0+1;
        p[3].x=x0;   p[3].y=y0-1;
        p[4].x=x0-1; p[4].y=y0;
    }
    for(n=0;n<nmax;n++)
    {
        ctemp[p[n].x][p[n].y]=1;
        c[p[n].x][p[n].y]=1;
    }
}

void rules(int sum,int i,int j)
{
    if(ctemp[i][j]==1)
    {
        if(sum==2 || sum==3) ctemp[i][j]=1;
        else ctemp[i][j]=0;
    }
    else
    {
        if(sum==3) ctemp[i][j]=1;
        else ctemp[i][j]=0;
    }
}

int fun_life(int tmax,int M,int N,int scelta)
{
    c=def_matrix(M,N);
    ctemp=def_matrix(M,N);
    results=fopen("../out/results.dat","w");
    if(results==NULL) return 1;
    shape(M,N,scelta);
    int t,i,j;
    int xn,a,yn,b,sum;
    for(t=0;t<tmax;t++)
    {
        for(i=0;i<M;i++) for(j=0;j<N;j++) if(c[i][j]==1) fprintf(results,"%d %d %d\n",i,j,t);
        for(i=0;i<M-1;i++)
        {
            for(j=0;j<N-1;j++)
            {
                sum=0;
                for(a=-1;a<=1;a++)
                {
                    for(b=-1;b<=1;b++)
                    {
                        if(a==0 && b==0) continue;
                        xn=i+a;
                        yn=j+b;
                        if(xn>=0 && xn<M && yn>=0 && yn<N) sum+=ctemp[xn][yn];
                    }
                }
                rules(sum,i,j);
            }
        }
        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
            {
                c[i][j]=ctemp[i][j];
                if(c[i][j]==1) fprintf(results,"%d %d %d\n",i,j,t);
            }
        }
    }
    fclose(results);
    return 0;
}
