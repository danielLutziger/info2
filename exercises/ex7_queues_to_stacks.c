//
// Created by danie on 16.06.2023.
//

/**
* uno reverse card for queues to stacks
 * => create a queue which behaves like a stack
 *
 * => FIFO => LIFO
*/
#include "stdio.h"
#include "stdlib.h"

#define N 5
int queue1[N];
int queue2[N];
int queuepointer1 = -1;
int queuepointer2 = -1;

void enqueue(int value) {
    if (N - queuepointer1 <= 1) {
        printf("queueoverflow\n");
        return;
    }
    queuepointer1 += 1;
    queue1[queuepointer1] = value;
    // LIFO & FIFO behave the same => no diff
}

int dequeue() {
    // LIFO => pop last element => dequeue last element
    // FIFO => dequeue first element => shift right
    if (queuepointer2 == -1) {
        // dequeue from queue1 and enqueue to queue2
        while (queuepointer1 != -1) {
            queuepointer2 += 1;
            queue2[queuepointer2] = queue1[queuepointer1]; //queue2 will have a reverse order
            queuepointer1 -= 1;
        }
    }
    if (queuepointer2 == -1) {
        printf("stackunderflow\n");
        return -1;
    } else {
        //remove the last element from queue2
        int val =queue2[queuepointer2];
        queuepointer2 -= 1;
        return val;
    }
}

int main() {
    enqueue(5);
    enqueue(3);
    enqueue(1);
    enqueue(2);
    dequeue();
    dequeue();
    enqueue(7);
    enqueue(1);
    enqueue(5);
    enqueue(0);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}