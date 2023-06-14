//
// Created by danie on 13.06.2023.
//

#include "stdio.h"

int Parent(int n){ return (n-1)/2; } // n-1 due to indexing
int Left(int n){ return 2*n+1; } // 2*n (+1) due to indexing
int Right(int n){ return 2*n+2; } // 2*n+1 (+1) due to indexing


void Heapify(int A[], int n, int s) {
    int m = n;
    int l = Left(n);
    int r = Right(n);

    if (l < s && A[l] > A[m])   // building max heap
  //if (l < s && A[l] < A[m])   // building min heap
        m = l;
    if (r < s && A[r] > A[m])   // building max heap
  //if (r < s && A[r] < A[m])   // building min heap
        m = r;
    if (n != m) {
        int t = A[n];
        A[n] = A[m];
        A[m] = t;
        Heapify(A, m, s);
    }
}

void BuildHeap(int A[], int n) {
    for (int i = Parent(n - 1); i >= 0; i--) {
        Heapify(A, i, n);
    }
}

void HeapSort(int A[], int n) {
    int s = n;
    BuildHeap(A, n);
    for (int i = n - 1; i >= 1; i--) {
        // swap
        int t = A[0];
        A[0] = A[i];
        A[i] = t;
        s = s - 1;
        Heapify(A, 0, s);
    }
}

void printHeap(int heap[], int n) {
    printf("Heap array representation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {9, 55, 8, 7, 6, 5, 4, 3, 1};
    HeapSort(A, 9);
    printHeap(A, 9);
}
