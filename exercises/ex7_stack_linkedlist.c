//
// Created by danie on 16.06.2023.
//
#include "stdio.h"
#include "stdlib.h"

struct node {
    int value;
    struct node* next;
    struct node* prev;
};
struct node* header;
void push(int i){
    if(header->next == NULL){
        struct node* newNode = malloc(sizeof (struct node));
        newNode->next = newNode;
        newNode->prev = newNode;
        newNode->value = i;
        header->next = newNode;
    } else {
        struct node* rootNode = header->next;
        struct node* newNode = malloc(sizeof (struct node));
        newNode->value = i;
        newNode->next = rootNode;
        newNode->prev = rootNode->prev;
        rootNode->prev->next = newNode;
        rootNode->prev = newNode;
    }
}

int pop(){
    if(header->next == NULL){
        printf("Stack underflow\n");
        return -1;
    } else {
        struct node* rootNode = header->next;
        struct node* freeNode = rootNode->prev;
        if(rootNode == freeNode) header->next = NULL;
        rootNode->prev = freeNode->prev;
        freeNode->prev->next = rootNode;
        int value = freeNode-> value;
        free(freeNode);
        return value;
    }
}

int main(){
    // sentinel element
    header = malloc(sizeof (struct node));
    header->next = NULL;
    header->prev = NULL;
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