#include <stdio.h>
#include <stdlib.h>

N_POINTS = {
        5, // numero punti figura 1
        4 // numero punti figura 2
};
FIGURES = {
        { // Pentomino R (scelta = 0)
                {0, 0 },
                {0, 1 },
                {1, 1 },
                {-1, 0 },
                {0, -1 }
        },
        { // Tetramino (scelta = 1)
                {0, 0 },
                {1, 0 },
                {-1, 0 },
                {0, -1 }
        },
};

int** def_matrix(int M, int N) /*assegna la memoria per una matrice*/
{
    int i;
    int **matrix;
    matrix=(int **)calloc(M, sizeof(int *));
    for(i=0;i<M;i++) matrix[i]=(int *)calloc(N,sizeof(int));
    return matrix;
}

void free_matrix(int **matrix, int M)
{
    int i;
    for(i=0;i<M;i++) free(matrix[i]);
    free(matrix);
}

int cas_int(int min,int max) //genera un numero casuale intero
{
    return min+rand()%(max-min+1);
}