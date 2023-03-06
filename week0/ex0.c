//
// Created by Daniel Lutziger on 20.02.23.
//
#include "stdio.h"

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                int replace = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = replace;
            }
}
int returnSecondLargest(int arr[], int n){

    for(int i = n-1; i >= 0; i--){
        if(arr[i] < arr[n-1]) return arr[i];
    }
    return arr[n-1];
}

int task2(int a, int b, int c, int d){
    //sscanf(argv[1], "%d", &m[0][0]);
    //sscanf(argv[2], "%d", &m[0][1]);
    //sscanf(argv[3], "%d", &m[1][0]);
    //sscanf(argv[4], "%d", &m[1][1]);

    int size = 2;
    int m[size][size];
    int o[size][size];

    m[0][0] = a;
    m[0][1] = b;
    m[1][0] = c;
    m[1][1] = d;

    for(int i= 0; i < size; i++){
        for(int j = 0;j < size; j++){
            o[i][j] = 0;
            for(int k = 0; k < size; k++){
                o[i][j] = o[i][j] + m[i][k] * m[k][j];
            }
        }
    }

    for(int i=0; i<size;i++){
        for(int j = 0; j<size; j++){
            printf("%5d", m[i][j]);
        }
        for(int j = 0; j<size; j++){
            printf("%5d", o[i][j]);
        }
        printf("\n");
    }
}

int pairSum(int A[], int c, int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1 ; j<size;j++){
            if(A[i] + A[j] == c){return 1;}
        }
    }
    return 0;
}

int pairSumSorted(int A[], int c, int size){
    int i = 0;
    int j = size-1;
    while(i < j){
        if(A[i] + A[j] == c) return 1;
        else if(A[i] + A[j] > c){
            j--;
        } else {
            i++;
        }
    }
    return 0;
}

// Driver program to test above functions
int main()
{
    task2(4,1,5,2);
    int a[] = {4,3,2,6,6,7,1};
    printf("%d\n", pairSum(a, 12, 7));
    printf("%d\n", pairSum(a, 19, 7));

    bubbleSort(a, 7);
    printf("%d\n", pairSumSorted(a, 19, 7));
    printf("%d\n", pairSumSorted(a, 12, 7));

    int arr[] = { 5, 1, 4, 2, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    int x = returnSecondLargest(arr, n);
    printf("%d", x);
    return 0;
}