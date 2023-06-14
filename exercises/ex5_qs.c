//
// Created by danie on 14.06.2023.
//

#include <stdio.h>

int partition(int A[], int low, int high, int partition){
    int pivot = A[low];
    int i = low-1;
    int j = high/3*partition;
    int k = high/3*2;
    int l = high+1;

    do{

        if(i < j){

        }
    }while()
    return 0;
}

void partitionQuickSort(int A[], int low, int high){
    if(low < high){
        int j = partition(A, low, high, );

        partitionQuickSort(A, low, j);
        partitionQuickSort(A, j+1, k);
        partitionQuickSort(A, k+1, high);
    }
}

int main(){
    int A[] = {10, 7, 3, 15, 6, 2, 5, 1, 17, 8};
    int n = 10;

    printf("Array before sorting: ");
    for(int i = 0; i < n; i++){
        printf("%d, ", A[i]);
    }

    partitionQuickSort(A, 0, n);

    printf("\nArray after sorting: ");
    for(int i = 0; i < n; i++){
        printf("%d, ", A[i]);
    }
}