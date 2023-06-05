//
// Created by danie on 05.06.2023.
//

// program that determines all prime numbers between 0 and n
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *primeChecker(int A[], int n) {
    int flags[n];
    for(int i = 0; i<n; i++){
        flags[i] = 1;
    }
    //less or equal the sqrt of the prime!
    for (int i = 0; i <= sqrt(n); i++) {
        if (A[i] > 1) {
            if (flags[i] == 1) {
                for (int j = A[i] * A[i]; j <= n; j = j + A[i]) {
                    flags[j - 1] = 0;
                }
            }
        }
    }
    int size = 0;
    for (int i = 0; i <= n; i++) {
        if (flags[i] == 1) {
            size++;
        }
    }

    // allocating a pointer
    int *B = (int *) malloc(size * sizeof(int));
    int c = 0;
    for (int i = 0; i <= n; i++) {
        if (flags[i] == 1) {
            B[c] = A[i];
            c++;
        }
    }
    return B;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
               29, 30, 31};
    // referencing the pointer
    int *res = primeChecker(a, 31);
    for (int i = 0; i < 12; i++) {
        printf("%d ", res[i]);
    }
    // free the space for the pointer
    free(res);
    return 0;
}