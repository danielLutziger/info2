//
// Created by danie on 16.06.2023.
//

/**
* Explain how to implement a queue Q0 using two stacks. Analyze the running time of the enqueue
* and dequeue operations on Q0
 *
 * => create a stack with queue behaviour... cool. why. cool.
 * allowed to use 2 stacks
*/
#include "stdlib.h"
#include "stdio.h"
#define N 5
int stack1[N];
int stack2[N];
int stackpointer1 = -1;
int stackpointer2 = -1;

// O(1)
void push(int value){
    // STACK: lifo
    // QUEUE: fifo
    // no difference in pushing
    if(N-stackpointer1 <= 1){
        printf("stackoverflow\n");
        return;
    }
    stackpointer1+=1;
    stack1[stackpointer1] = value;
}

// O(n) if stack 1 & 2 is empty, else O(1)
int pop(){
    if(stackpointer2 == -1){
        while(stackpointer1 != -1){
            stackpointer2 += 1;
            stack2[stackpointer2]  = stack1[stackpointer1];
            stackpointer1 -= 1;
        }
    }
    if(stackpointer2 == -1){
        printf("stack underflow");
        return -1;
    } else {
        int val = stack2[stackpointer2];
        stackpointer2 -= 1;
        return val;
    }
}

void printQueue(){
    // Print elements from stack2 from top to bottom
    for(int i = stackpointer2; i >= 0; i--){
        printf("%d ", stack2[i]);
    }

    // Print elements from stack1 from bottom to top
    for(int i = 0; i <= stackpointer1; i++){
        printf("%d ", stack1[i]);
    }

    printf("\n");
}


// O(n)
int main(){
    push(5);
    push(4);
    push(2);
    push(8);
    push(8);
    push(8);
    printQueue();
    pop();
    pop();
    pop();
    pop();
    printQueue();
    pop();
    pop();
    printQueue();
    push(3);
    push(5);
    printQueue();
    push(3);
    push(7);
    printQueue();
    pop();
    printQueue();
    pop();
    printQueue();
    push(1);
    push(9);
    printQueue();
    pop();
    printQueue();
}