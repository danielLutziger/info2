//
// Created by danie on 05.06.2023.
//

#include <stdio.h>

#define n 10

int a[] = {1, 3, 1, 553, 12, 43, 23, 32, 42, 5};

// default Selection Sort (swap first element)
int *SelectionSort(int *A) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[k]) k = j;
        }
        int t = A[i];
        A[i] = A[k];
        A[k] = t;
    }
}

// Selection Sort (swap last element) => from the back
int *SelectionSortLastSwap(int *A) {
    for (int i = n-1; i > 0; i--) {
        int k = i;
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] > A[k]) k = j;
        }
        int t = A[i];
        A[i] = A[k];
        A[k] = t;
    }
}


int main() {
    SelectionSort(a);
    SelectionSortLastSwap(a);
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}