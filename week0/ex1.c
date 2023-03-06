//
// Created by Daniel Lutziger on 21.02.23.
//
#include <math.h>
#include "stdio.h"
int linearSearch1(int arr[], int search){
    int p;
    int n = sizeof(arr);
    for(int i = 0; i < n; i++){
        if (arr[i] == search) p = i;
    }
    return p;
}

int linearSearch2(int arr[], int search){
    int p;
    int n = sizeof(arr);
    for(int i = 0; i < n; i++){
        if (arr[i] == search) return i;
    }
    return p;
}

int linearSearch3(int arr[], int search){
    int i = 1;
    int n = sizeof(arr);
    // due to the OR in this function this is trash
    while(i <= n || arr[i] != search){
        if(i > n) break;
        else i++;
    }
    if(i <= n) return i;
    else return 0;

}


int task2(){
    /**
    // some array = {0,1,2,3,4,5,6,7,8,9};
    // some array in booleans = {F,F,T,T,T,T,T,T,T,T};
    // after first iteration (division by 2) = {F,F,T,T,F,T,F,T,F,T};
    // after second iteration (division by 3) = {F,F,T,T,F,T,F,T,F,F};
    */
    int values[4];
    for(int i = 0; i < 4; i++){
        printf("Enter value number: %d\n", i+1);
        scanf("%d", &values[i]);
    }

    for(int i = 0; i < 4; i+=2){
        printf("%d", values[i]);
        printf("  ");
        printf("%d", values[i+1]);
        printf("      ");
        printf("%f", pow(values[i], 2));
        printf("  ");
        printf("%f\n", pow(values[i+1], 2));
    }

}

int pairSum(){
    int A[] = {3,4,5,1,3,6,6,4};
    int N = 8;

    int c = 8;

    int value1;
    int value2;

    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(A[i] + A[j] == c){
                value1 = i;
                value2 = j;
                break;
            }
        }
    }
    printf("Position 1: %d\n", value1);
    printf("Position 2: %d\n", value2);
}

int pairSumSorted(){
    int A[] = {1,3,3,4,4,5,6,6};
    int N = 8;
    int c = 8;

    int i = 0;
    int j = N-1;
    while (i < j){
        if (A[i] + A[j] == c){
            return 1;
        } else if (A[i] + A[j] < c){
            i++;
        }
        else {
            j--;
        }
    }
}


int main(){
    //task2();
    pairSum();
    pairSumSorted();


    int a[] = {31,41,41, 59,41,26,58};
    printf("%d\n", linearSearch1(a, 41));
    printf("%d\n", linearSearch2(a, 41));
    printf("%d\n", linearSearch3(a, 41));
}


