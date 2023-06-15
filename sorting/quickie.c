//
// Created by danie on 15.06.2023.
//

#include <limits.h>
#include <stdio.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partitioning(int A[], int l, int r){
    // pivots
    int pivot = A[l];

    // index
    int i = l, j = r;

    do{
        do {i++;}while(pivot >= A[i]);
        do {j--;}while(pivot < A[j]);
        if(i < j){
            swap(&A[j], &A[i]);
        }
    }while(i < j);
    swap(&A[l], &A[j]);
    return j;
}

void quicksort(int A[], int l, int r){
    if(l < r){
        int partition = partitioning(A, l, r);
        quicksort(A, l, partition);
        quicksort(A, partition+1, r);
    }
}


int main() {
    int A[] = {50,11, 13, 7, 12, 16, 9, 24, 5, 10, 3,50};
    int n = 11;
    quicksort(A, 0, n);
    for(int i = 0; i < n; i++){
        printf("%d, ", A[i]);
    }

    return 0;
}
