#ifndef CELLULAR_AUTOMATA_UTILS_H
#define CELLULAR_AUTOMATA_UTILS_H 1

#define N_FIGURE 2
#define MAX_POINTS 10

typedef struct point{
    int x,y;
}point;

int N_POINTS[N_FIGURE];
point FIGURES[N_FIGURE][MAX_POINTS];

int** def_matrix(int M,int N);

void free_matrix(int **matrix,int M);

int cas_int(int min,int max);

#endif //CELLULAR_AUTOMATA_UTILS_H
