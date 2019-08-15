#ifndef CELLULAR_AUTOMATA_UTILS_H
#define CELLULAR_AUTOMATA_UTILS_H

typedef struct point{
    int x,y;
}point;

int** def_matrix(int M,int N);

void free_matrix(int **matrix,int M);

#endif //CELLULAR_AUTOMATA_UTILS_H
