#include "stdio.h"
void swap(int* a, int* b){
    int t = *b;
    *b = *a;
    *a = t;
}

void partitioning(int A[], int low, int high, int* p1, int* p2){
    int l = low+1, k = l, g = high;
    while(k < g){
        if(A[k] < A[low]){ swap(&A[l++], &A[k++]);}
        else if(A[k] > A[high]){ swap(&A[k], &A[--g]);}
        else{k++;}
    }
    swap(&A[low], &A[l-1]);
    swap(&A[high], &A[k]);
    *p1 = l-1;
    *p2 = k;
}

void quicksort(int A[], int low, int high){
    if(high - low <= 0) return;
    if(A[low] > A[high]) swap(&A[low], &A[high]);
    int p1, p2;
    partitioning(A, low, high, &p1, &p2);
    quicksort(A, low, p1-1);
    quicksort(A, p1+1, p2-1);
    quicksort(A, p2+1, high);
}

int main(){
    int A[] = {5,3,2,7,1,9,53,16,4};
    int n = 9;
    quicksort(A, 0, n-1);

    for(int i = 0; i < n; i++){
        printf("%d, ", A[i]);
    }

    return 0;
}