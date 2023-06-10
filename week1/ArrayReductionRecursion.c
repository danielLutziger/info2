//
// Created by danie on 10.06.2023.
//

#include <stdio.h>

/**
* exercise 2.4
*/

int* recursivlyReduceArray(int* A, int n){
    if(n == 0) return A;

    for(int i = 1; i < n; i++){
        A[i-1] = A[i-1] + A[i];
        printf("%d, ", A[i-1]);
    }
    A[n-1] = 0;
    printf("\n");
    recursivlyReduceArray(A, n-1);
    return A;
}

int main(){
    int A[] = {5,4,6,1,3};
    recursivlyReduceArray(A, 5);
}