//
// Created by danie on 05.06.2023.
//

#include <stdio.h>

#define n 10

int a[] = {15, 16, 12, 29, 52, 243, 234, 43, 12, 1};

// right implementation of the bubble sort, the last item is sorted first
int* BubbleSortRight(int *arr){
    for(int i = n; i > 1; i--){
        for(int j = 1; j < i; j++){
            if(arr[j] < arr[j-1]){
                // swap
                int t = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = t;
            }
        }
    }
    return arr;
}

// left implementation of the bubble sort, the first item is sorted first
int* BubbleSortLeft(int *arr){
    for(int i = 0; i < n-1; i++){ // i smaller n-1 to pass all elements
        for(int j = n-1; j > i; j--){ // n-1 => due to index
            if(arr[j] < arr[j-1]){
                // swap
                int t = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = t;
            }
        }
    }
    return arr;
}

int main() {
    BubbleSortRight(a);
    BubbleSortLeft(a);
    for(int i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
}