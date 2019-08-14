#include <stdio.h>
#include <stdlib.h>

int fun_automata(int tmax,int N,int scelta)
{
    int *c,*ctemp;
    FILE *results;
    c=calloc(N,sizeof(int *));
    ctemp=calloc(N,sizeof(int *));
    results=fopen("../out/results.dat","w");
    if(results==NULL) return 1;
    int t,i;
    ctemp[(int)(0.5*N)]=1;
    c[(int)(0.5*N)]=1;
    for(t=0;t<tmax;t++)
    {
        for(i=0;i<N;i++) if(c[i]==1) fprintf(results,"%d %d\n",i-(int)(0.5*N),t);
        for(i=1;i<N-1;i++)
        {
            if(scelta=='1') ctemp[i]=c[i-1]^(c[i]|c[i+1]);                    /*regola 30*/
            else if(scelta=='2') ctemp[i]=c[i-1]^c[i+1];                      /*regola 90*/
            else if(scelta=='3') ctemp[i]=(c[i-1]|c[i])^(c[i-1]&c[i]&c[i+1]); /*regola 110*/
            else ctemp[i]=(c[i-1]^c[i+1])^c[i];                               /*regola 150*/
        }
        for(i=0;i<N;i++) c[i]=ctemp[i];
    }
    fclose(results);
    return 0;
}