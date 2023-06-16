//
// Created by danie on 16.06.2023.
//

#include "stdlib.h"
#include "stdio.h"

struct node{
    int value;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* back;
};

struct queue* queue;

void enqueue(int value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    if(queue->front == NULL && queue->back == NULL){
        queue->front = newNode;
        queue->back = newNode;
    } else{
        queue->back->next = newNode;
        queue->back = newNode;
    }
}
int dequeue(){
    if(queue->front == NULL){
        printf("cannot dequeue from empty queue");
        return -1;
    }
    struct node* front = queue->front;
    queue->front = queue->front->next;
    int val = front->value;
    free(front);
    return val;
}

int main(){
    queue = malloc(sizeof (struct queue));
    queue->front = NULL;
    queue->back = NULL;

    enqueue(15);
    enqueue(13);
    enqueue(11);
    enqueue(12);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(11);
    enqueue(12);
    dequeue();
    enqueue(62);
    enqueue(442);
}