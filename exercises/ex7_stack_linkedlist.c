//
// Created by danie on 16.06.2023.
//
#include "stdio.h"
#include "stdlib.h"

struct node {
    int value;
    struct node* next;
};

struct node* sentinel = NULL;

void push(int i){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->value = i;
    if(sentinel->next == NULL){
        newNode->next = NULL;
        sentinel->next = newNode;
    } else{
        newNode->next = sentinel->next;
        sentinel->next = newNode;
    }
}

int pop(){
    if(sentinel->next == NULL){
        printf("stack underflow\n");
        return -1;
    }
    struct node* todel = sentinel->next;
    sentinel->next = todel->next;
    int value = todel->value;
    free(todel);
    return value;
}

int main(){
    // sentinel element
    sentinel = malloc(sizeof (struct node));
    sentinel->next = NULL;
    push(35);
    push(25);
    push(15);
    push(65);
    pop();
    pop();
    push(16);
    pop();
    pop();
    pop();
    pop();
    push(16);
    push(17);
}