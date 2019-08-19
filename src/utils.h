#ifndef CELLULAR_AUTOMATA_UTILS_H
#define CELLULAR_AUTOMATA_UTILS_H

#define N_FIGURE 2
#define MAX_POINTS 10

typedef struct point{
    int x,y;
}point;

int N_POINTS[N_FIGURE] = {
        5, // numero punti figura 1
        5 // numero punti figura 2
};
point FIGURES[N_FIGURE][MAX_POINTS] = {
        { // Pentomino R (scelta = 0)
                {0, 0 },
                {0, 1 },
                {1, 1 },
                {-1, 0 },
                {0, -1 }
        },
        { // Pentomino R (scelta = 1)
                {0, 0 },
                {0, 1 },
                {1, 1 },
                {-1, 0 },
                {0, -1 }
        },
};

int** def_matrix(int M,int N);

void free_matrix(int **matrix,int M);

#endif //CELLULAR_AUTOMATA_UTILS_H
