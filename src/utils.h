#ifndef CELLULAR_AUTOMATA_UTILS_H
#define CELLULAR_AUTOMATA_UTILS_H 1

#define N_FIGURE 2
#define MAX_POINTS 10



int** def_matrix(int M,int N);

void free_matrix(int **matrix,int M);

int cas_int(int min,int max);

#endif //CELLULAR_AUTOMATA_UTILS_H
