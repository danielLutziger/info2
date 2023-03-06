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

int straightForwardFunction(int arr[], int n){
    int largest = arr[0];
    int secondLargest = arr[1];
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
    }
    return secondLargest;
}

int main()
{
    int arr[] = { 6,5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]); // will return the array size, subtract 1 from it to use it
    bubbleSort(arr, n);
    printf("%d\n", returnSecondLargest(arr, n));
    printf("%d", straightForwardFunction(arr, n));
    return 0;
}