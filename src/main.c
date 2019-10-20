#include <stdio.h>
#include <stdlib.h>
#include "life.h"
#include "automata.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
int main()
{
    FILE *parameters;
    int exit_code=0;
    int prog;
    int tmax,N,scelta,caso;
    parameters = fopen("../in/parameters.dat","r");
    if(parameters == NULL) return 1;
    fscanf(parameters,"%d",&prog);
    if(prog==1)
    {
        fscanf(parameters,"%d",&tmax);
        fscanf(parameters,"%d",&N);
        fscanf(parameters,"%d",&scelta);
        fscanf(parameters,"%d",&caso);
        exit_code = fun_automata(tmax,N,scelta,caso);
    }
    else if(prog==2)
    {
        int M;
        fscanf(parameters,"%d",&tmax);
        fscanf(parameters,"%d",&M);
        fscanf(parameters,"%d",&N);
        fscanf(parameters,"%d",&scelta);
        //fscanf(parameters,"%d",&caso);
        exit_code = fun_life(tmax,M,N,scelta);
    }
    else
        exit_code = 1;
    fclose(parameters);
    return exit_code;
}
#pragma clang diagnostic pop
