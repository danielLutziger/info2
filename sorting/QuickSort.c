//
// Created by danie on 14.06.2023.
//

#include <limits.h>
#include <stdio.h>

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l;
    int j = h;
    do {
        do { i = i + 1; } while (A[i] <= pivot);
        do { j = j - 1; } while (A[j] > pivot);
        if (i < j){
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    } while (i < j);
    int t = A[l];
    A[l] = A[j];
    A[j] = t;
    return j;
}

void quicksort(int A[], int l, int h) {
    int j;
    if (l < h) {
        j = partition(A, l, h);
        quicksort(A, l, j);
        quicksort(A, j+1, h);
    }
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3,50, INT_MAX};
    int n = 11;
    int i;

    quicksort(A, 0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d, ", A[i]);
    }

    return 0;
}