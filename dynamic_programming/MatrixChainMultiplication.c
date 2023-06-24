//
// Created by danie on 24.06.2023.
//


#include <limits.h>

// minimum cost for multiplying a sequence of matrices
int MatrixRec(int i, int j, int *d) {
    if (i == j) return 0;
    int min = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = MatrixRec(i, k, d) + MatrixRec(k + 1, j, d) + d[i - 1] * d[k] * d[j];
        if(cost < min) min = cost;
    }
    return min;
}