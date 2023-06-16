//
// Created by danie on 16.06.2023.
//

/**
* queues but as lists instead of arrays
 *
*/
#include "stdlib.h"
#include "stdio.h"

struct node {
    int value;
    struct node* next;
    struct node* previous;
};

struct node* head;
struct node* queue;

void enqueue(int value){
    //append at end
    //using circular list
    if(head->next == NULL){
        queue = malloc(sizeof (struct node));
        queue->value = value;
        queue->next = queue;
        queue->previous = queue;
        head->next = queue;
    }else{
        struct node* currentLastNode = queue->previous;
        struct node* newLastNode =malloc(sizeof (struct node));
        newLastNode->value = value;
        newLastNode->next = queue;
        queue->previous = newLastNode;
        newLastNode->previous = currentLastNode;
        currentLastNode->next = newLastNode;
    }
}

void dequeue(){
    //remove first element
    if(head->next == NULL){
        printf("cannot dequeue empty queue!");
        return;
    }
    if(head->next == queue->previous){
        head->next = NULL;
    }
    //oldest element = root
    struct node* freeQueueElement = queue;
    queue->previous->next = queue->next;
    queue->next->previous = queue->previous;
    queue = queue->next;
    free(freeQueueElement);
}

int isEmpty(){
    return head->next == NULL ? 0 : 1;
}

int main(){
    // sentinel element
    head = malloc(sizeof(struct node));
    head->next = NULL;
    head->previous = NULL;

    enqueue(15);
    dequeue();
    dequeue();
    enqueue(4);
    enqueue(15);
    dequeue();
    enqueue(13);
    enqueue(17);
    enqueue(85);
    enqueue(25);
    dequeue();
    enqueue(45);
    enqueue(165);
    enqueue(78);
}