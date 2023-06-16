//
// Created by danie on 16.06.2023.
//
/**
* basically a linked list or an array with the following methods:
 * - enqueue
 * - dequeue
 *
 * -> FIFO
*/

#include "stdio.h"
#define N 100
int queue[N];
int currentValue = -1;

void enqueue(int value){
    if(N-currentValue == 1){
        printf("queue is full, cannot add element");
        return;
    }
    currentValue+=1;
    queue[currentValue] = value;
}

int dequeue(){
    if(currentValue == -1){
        printf("cannot dequeue from an empty queue\n");
        return -1;
    }
    int rv = queue[0];
    for(int i = 1; i <= currentValue; i++){
        queue[i-1] = queue[i];
    }
    --currentValue;
    return rv;
}

int isEmpty(){
    return currentValue == -1 ? 1 : 0;
}

int isFull(){
    return N-currentValue == 1 ? 1 : 0;
}

void print(int A[]){
    for(int i = 0; i < N; i++){
        printf("%d, ", A[i]);
    }
    printf("\n");
}

int main(){
    enqueue(25);
    enqueue(15);
    enqueue(17);
    enqueue(12);
    print(queue);
    dequeue();
    print(queue);
    dequeue();
    dequeue();
    print(queue);
    enqueue(1);
    print(queue);
    enqueue(15);
    enqueue(11);
    enqueue(157);
    print(queue);
}