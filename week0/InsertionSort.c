//
// Created by danie on 05.06.2023.
//

#include "stdio.h"

#define n 10

int a[] = {1,423,32,13,5,1,3,5,8,2};

int* InsertionSort(int *A){
    for(int i = 1; i < n; i++){
        int j = i-1;
        int t = A[i];
        while (j >= 0 && t < A[j]){
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = t;
    }
    return A;
}

int main(){
    InsertionSort(a);
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}