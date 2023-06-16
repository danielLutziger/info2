//
// Created by danie on 16.06.2023.
//

/**
* basically a linked list or an array with the following methods:
 * - push
 * - pop
 *
 * -> LIFO
*/

#include "stdlib.h"
#include "stdio.h"
#define N 100

int stack[N];
int currentElement = -1;

void push(int value){
    if(N-currentElement == 1){
        printf("stackoverflow");
        return;
    }
    stack[currentElement++] = value;
}

int pop(){
    if(currentElement == -1){
        printf("cannot delete from an empty stack");
        return -1;
    }
    return stack[currentElement--];
}

void print(int A[]){
    for(int i = 0; i < N; i++){
        printf("%d, ", A[i]);
    }
    printf("\n");
}

int main(){
    push(15);
    push(25);
    push(22);
    push(21);
    push(28);
    print(stack);
    pop();
    push(14);
    print(stack);
}