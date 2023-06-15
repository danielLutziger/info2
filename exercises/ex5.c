//
// Created by danie on 13.06.2023.
//


// ascending order => max heap
// => l < s && A[l] > A[m]

#include <stdio.h>

void heapify(int A[], int n, int s, int dimensions){
    int m = n;
    int children[dimensions];
    for(int i = 0; i < dimensions; i++){
        children[i] = n * dimensions + i + 1;
        if(children[i] < s && A[children[i]] > A[m])
            m = children[i];
    }

    if(n != m){
        // swap
        int t = A[m];
        A[m] = A[n];
        A[n] = t;
        heapify(A, m, s, dimensions);
    }
}

void buildMaxHeap(int A[], int n, int d) {
    for(int i = (n-1)/d; i >= 0; i--){

        heapify(A, i, n, d);
    }
}

void heapSort(int A[], int n, int d) {
    int s = n;
    buildMaxHeap(A, n, d);
    for(int i = (n-1); i >= 0; i--){
        int t = A[0];
        A[0] = A[i];
        A[i] = t;
        s = s-1;
        heapify(A, 0, i, d);
    }
}

void printHeap(int A[], int n) {
    for(int i = n-1; i >= 0; i--){
        printf("%d, ", A[i]);
    }
}

int main() {
    int A[] = {6, 4, 3, 9, 5, 10, 15, 19, 11, 7, 8, 13};
    heapSort(A, 12, 2);
    printHeap(A, 12);
    return 0;
}