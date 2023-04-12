//
// Created by danie on 20.03.2023.
//


#include <stdio.h>
#include <minmax.h>

/**
* te
 * 1.1 Tree
 *                 [-2, -5, 6,-2, -3, 1 , 5]
 *             [-2, -5, 6, -2]       [-3, 1, 5]
 *          [-2, -5]    [6, -2]   [-3, 1]     [5]
 *        [-2]   [-5]  [6]  [-2] [-3]   [1]
 *
 *      left                right           overlap
 *      [-2, -5, 6,-2] -3   [-3, 1 , 5] 3   [-2, -5, 6,-2, -3, 1 , 5] 0
 *      [-2, -5] -7         [6,-2] 4        [-2, -5, 6,-2] -3
 *      -2                  -5              -7
 *      6                   -2              4
 *
 *      [-3, 1]             5               3
 *
 *
 *
 *
 *                     [-1, 2, -4, 1, 9, -6, 7, -3, 5]
 *                  [-1, 2, -4, 1, 9]      [-6, 7, -3, 5]
 *                [-1, 2, -4]    [1, 9]   [-6, 7]    [-3, 5]
 *              [-1, 2]
 *
 *
 *     merge
 *          [1, 9, -6, 7, -3, 5]
 *
 *
 * 1.3 => recurrence relation
 *
 * asymptotic tight bound: O(log2(n)) (Theta)
*/

int merge(int A[], int l, int r, int m){
    int B[r];
    for(int i = 0; i < m; i++){
        B[i] = A[i];
    }
    for(int i = m; i < r; i++){
        B[r-1+m-i] = A[i];
    }
    int i = l;
    int j = r;
    for(int k = l; k < r; k++){
        if (B[i] < B[j]){A[k] = B[i]; i++;}
        else {A[k] = B[j]; j--;}
    }
}

int mergeSort(int A[], int l, int r){
    if (l < r){
        int m = (l+r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        merge(A, l, r, m);
    }
}

int substitutionMethod(int n){
    if (n <= 1){
        printf("%f", n);
        return 1;
    }
    int c = 10;
    int calculatedN = 2*(n/2) + c;
    printf("%i\n", calculatedN);
    substitutionMethod(calculatedN);
}

void recursiveAlgo(int n){
    printf("%i\n", n);
    if (n <= 1) return;
    int t = 0;
    for(int i = 0; i < max(n, 1); i++){
        t = t+i;
    }
    recursiveAlgo(n/10);
    recursiveAlgo(9*n/10);
    return;
}


int main(){
    int A[] = {-2, -5, 6,-2, -3, 1 , 5};
    int size = 7-1;
    int left = 0;
    //mergeSort(A, left, size);
    for(int i = 0; i < size; i++){
        //printf("%i, ", A[i]);
    }
    //substitutionMethod(10);
    recursiveAlgo(100);
}