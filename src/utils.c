#include <stdio.h>
#include <stdlib.h>

int** def_matrix(int M,int N) /*assegna la memoria per una matrice*/
{
    int i;
    int **matrix;
    matrix=calloc(M,sizeof(int *));
    for(i=0;i<M;i++) matrix[i]=calloc(N,sizeof(int));
    return matrix;
}


