//
// Created by danie on 11.06.2023.
//
#include "stdio.h"

int BinarySearch(int A[], int n, int s){
    int l, r, m;
    l = 0;
    r = n-1;
    m = (l+r)/2;
    while (l <= r && A[m] != s){
        if(A[m] == s ){
          return m;
        } else if(s < A[m]){
            r = m-1;
            m = (l+r)/2;
        } else {
            l = m+1;
            m = (l+r)/2;
        }
    }
    if(l > r) return -1;
   return m;
}

int cntOcc(int A1[], int A2[], int n1, int n2){
    int cnt = 0;
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(A1[i] == A2[j]) cnt++;
        }
    }
    return cnt;
}

int cntOccPerformance(int A1[], int A2[], int n1, int n2){
    int cnt = 0;
    for(int i = 0; i < n1; i++){
        if(BinarySearch(A2, n2, A1[i]) != -1){
            cnt++;
        }
    }
    return cnt;
}

int* bubbleSort(int A[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(A[i] > A[j]){
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }
    return A;
}

int select_kth_smallest(int A[], int n, int kth){
    //sort and return pos kth
    A = bubbleSort(A, n);
    return A[kth-1];
}

int main(){
    int A1[] = {12, 4, 10, 8, 9, 33, 2, 18};
    int A2[] = {1,4,5,7,9,22,44,55};
    int n1 = sizeof(A1) / sizeof(A1[0]);
    int n2 = sizeof(A2) / sizeof(A2[0]);

    printf("%d", cntOcc(A1, A2, n1, n2));
    printf("\n%d", cntOccPerformance(A1, A2, n1, n2));
    printf("\n%d", select_kth_smallest(A1, n1, 3));


    return 0;
}