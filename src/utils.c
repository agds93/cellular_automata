#include <stdio.h>
#include <stdlib.h>

int** def_matrix(int M,int N) /*assegna la memoria per una matrice*/
{
    int i;
    int **matrix;
    matrix=(int **)calloc(M,sizeof(int *));
    for(i=0;i<M;i++) matrix[i]=(int *)calloc(N,sizeof(int));
    return matrix;
}

void free_matrix(int **matrix,int M)
{
    int i;
    for(i=0;i<M;i++) free(matrix[i]);
    free(matrix);
}
