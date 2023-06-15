//
// Created by danie on 14.06.2023.
//
#include "stdio.h"

int partitioning(int A[], int l, int h) {
    // pivot
    int pivot = A[l];

    // array index
    int left = l+1;
    int right = h;
    do {
        do{left=left+1;}while(pivot >= A[left]);
        do{right=right-1;}while(pivot < A[right]);
        if(left < right){
            int t = A[left];
            A[left] = A[right];
            A[right] = t;
        }
    }while(left < right);
    int t = A[right];
    A[right] = pivot;
    A[l] = t;
    return right;
}

int quicksort(int A[], int l, int h) {
    if (l < h) {
        int qs = partitioning(A, l, h);
        quicksort(A, l, qs-1);
        quicksort(A, qs+1, h);
    }
}

int main() {
    int A[] = {10,7,8,9,1,5};
    int n = 5;
    quicksort(A, 0, n);

    quicksort(A, 0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d, ", A[i]);
    }

    return 0;
}