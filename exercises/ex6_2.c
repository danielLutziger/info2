//
// Created by danie on 15.06.2023.
//
#include "malloc.h"
#include "stdio.h"
#define N 5
void print(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("value %d: %d\n", i, arr[i]);
    }
}

int* reverse(int *arr, int n){
    // creating a new pointer in the function because of the free from the main
    // else arr and reversed would point onto the same array
    int *q = malloc(n*sizeof(int));
    int size = n-1;
    for(int i = 0; i <= n; i++){
        q[i] = arr[size-i];
    }
    return q;
}

int* prepend(int *arr, int v){
    int *q = malloc((N+1) * sizeof (int));
    q[0] = v;
    for(int i = 0; i < N; i++){
        q[i+1] = arr[i];
    }
    return q;
}

int main(){
    int *arr;
    arr = malloc(N*sizeof(int));
    for(int i = 0; i < N; i++){
        arr[i] = i;
    }
    printf("The og\n");
    print(arr, N);

    int *reversed = reverse(arr, N);

    // this will deallocate reversed, if arr is passed as function return and not a new
    // pointer is created in the function.
    free(arr);

    printf("The switcheroo\n");
    print(reversed, N);

    int *prepended = prepend(reversed, N);

    free(reversed);

    printf("the prepended\n");
    print(prepended, N+1);
}