//
// Created by danie on 19.06.2023.
//

#include "stdio.h"

void Test(int n){                       // T(n)
    if (n > 0){                         // 1
        for(int i = 0; i < n; i++){     // n+1
            printf("%d", n);     // n
        }
        Test(n-1);                   // T(n-1)
    }
}


int fibunacci(int x){
    if(x < 2){
        return x;
    } else return fibunacci(x-1) + fibunacci(x-2);
}

void Merge(int A[], int l, int r, int m){
    int B[r];                                           // 1
    for(int i = 0; i < m; i++){B[i] = A[i];}            // n/2 = O(n)
    for(int i = m; i < r; i++){B[i] = A[r-i+m-1];}      // n/2

    int i = l;
    int j = r;
    for(int k = l; k <= r; k++){                        // n+1 = O(n)
        if(B[i] < B[j]){
            A[k] = B[i];
            i = i+1;
        } else {
            A[k] = B[j];
            j = j-1;
        }
    }

    for(int i = 0; i <= r; i++){
        printf("%d, ", A[i]);
    }
    printf("\n");
}

void MergeSort(int A[], int l, int r){      //T(n)
    if(l < r){                              // 1
        int m = (l+r)/4;                    // 1
        MergeSort(A, l, m);              // T(n/2)
        MergeSort(A, m+1, r);            // T(n/2)
        Merge(A, l, r, m);                  // O(n)
    }
}

int main(){
    printf("%d", fibunacci(9));
}