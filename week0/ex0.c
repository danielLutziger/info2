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

// Driver program to test above functions
int main()
{
    int arr[] = { 5, 1, 4, 2, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    int x = returnSecondLargest(arr, n);
    printf("%d", x);
    return 0;
}