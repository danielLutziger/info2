//
// Created by danie on 14.06.2023.
//

#include <stdio.h>
#include <malloc.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int* partition(int A[], int low, int high) {
    //pivots
    if (A[low] > A[high])
        swap(&A[low], &A[high]);

    int left_pivot = A[low];
    int right_pivot = A[high];

    // index (removing the pivots)
    int l = low+1, h = high-1, k = l;
    while(k <= h){
        if(A[k] < left_pivot){
            swap(&A[k], &A[l]);
            k++;
        } else if(A[k] >= right_pivot){
            while(A[h] > right_pivot && k < h){
                h--;
            }
            swap(&A[k], &A[h]);
            h--;
            if(A[k] < left_pivot){
                swap(&A[k], &A[l]);
                l++;
            }
        }
        k++;
    }
    l--;
    h++;
    swap(&A[low], &A[l]);
    swap(&A[high], &A[h]);

    int *p;
    p = malloc(2*sizeof(int));
    p[0] = l;
    p[1] = h;
    return p;
}

void partitionQuickSort(int A[], int low, int high) {
    if (low < high) {
        int *j = partition(A, low, high);
        partitionQuickSort(A, low, j[0]-1);
        partitionQuickSort(A, j[0] + 1, j[1]-1);
        partitionQuickSort(A, j[1]+1, high);
    }
}

int main() {
    int A[] = {10, 7, 3, 15, 6, 2, 5, 1, 17, 8};
    int n = 10;

    printf("Array before sorting: ");
    for (int i = 0; i <= n; i++) {
        printf("%d, ", A[i]);
    }

    partitionQuickSort(A, 0, n);

    printf("\nArray after sorting: ");
    for (int i = 0; i <= n; i++) {
        printf("%d, ", A[i]);
    }
}