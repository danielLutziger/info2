//
// Created by danie on 16.06.2023.
//

/**
 *
 * explain how to implement two stacks in one array A[] in such a way
 * that neither stack overflows unless the total number in both stacks together is n
 *
 * push and pop have ot be in O(1)
 *
 * => start filling the array from left and right
 */

#include "stdio.h"
#include "stdlib.h"
#define N 10
int A[N];
int topLeft = -1;
int topRight = N;

void push(int value, char option){
    if(topRight-topLeft <= 1){
        printf("Stack is full, adding leads to overflow \n");
        return;
    }
    if(option == 'l'){
        topLeft+=1;
        A[topLeft] = value;
    } else{
        topRight -=1;
        A[topRight] = value;
    }
}

int pop(char option){
    if(option == 'l'){
        if(topLeft > -1){
            topLeft -=1;
            return A[topLeft];
        }
    }else{
        if(topRight == N){
            topRight +=1;
            return A[topRight];
        }
    }
    printf("stack underflow bre\n");
    return -1;
}

int main(){
    push(14, 'r');
    push(4, 'l');
    push(5, 'l');
    push(56, 'l');
    push(24, 'r');
    push(24, 'r');
    push(24, 'r');
    push(24, 'r');
    push(24, 'r');
    push(24, 'r');
    push(24, 'r');
    push(24, 'l');
    pop('l');
    pop('l');
    pop('l');
    pop('l');
    pop('r');
    pop('r');
    pop('r');
    pop('r');
    push(24, 'l');

}