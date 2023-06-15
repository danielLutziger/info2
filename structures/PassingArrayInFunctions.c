//
// Created by danie on 14.06.2023.
//


#include <malloc.h>
#include <stdio.h>

int* returnAnArray(int size){
    int *p = (int *)malloc(size*sizeof(int));
    return p;
}

int main(){

    int *A = returnAnArray(5);
    A[0] = 25;
    A[1] = 2;
    A[2] = 5;
    A[3] = 525;
    A[4] = 43;
    for(int i = 0; i < 5; i++)
        printf("%d\n", A[i]);

}