#include <stdio.h>

//
// Created by danie on 11.06.2023.
//
int Merge(int A[], int l, int r, int m){
    //copy array into local array storage
    int B[r];
    for(int i = l; i <= m; i++){
        B[i] = A[i];
    }
    for(int i = m+1; i <= r; i++){B[r+m-i+1] = A[i];}

    int i = l;
    int j = r;
    for(int k = l; k <= r; k++){
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

int MergeSort(int A[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        MergeSort(A, l, m);
        MergeSort(A, m+1, r);
        Merge(A, l, r, m);
    }
}


int main(){
    int A[] = {5,4,2,6,1,8,9,8,6,5,3,11,12};
    MergeSort(A, 0, 12);
}