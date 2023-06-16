//
// Created by danie on 16.06.2023.
//

#include <malloc.h>
#include <stdio.h>

struct node {
    int value;
    struct node* next;
};
struct node* stack;

void push(int value){
    if(stack == NULL){
        stack = malloc(sizeof (struct node));
        stack->next = NULL;
        stack->value = value;
    }else{
        struct node* newNode = malloc(sizeof (struct node));
        newNode->value = value;
        newNode->next = stack;
        stack = newNode;
    }
}

int pop(){
    if(stack == NULL){
        printf("stack underflow man, cannot delete from empty stack\n");
        return -1;
    }
    int value = stack->value;
    struct node* freeStack = stack;
    stack = stack->next;
    free(freeStack);
    return value;
}

void print(){
    struct node* root = stack;
    while(root != NULL){
        printf("%d, ", root->value);
        root = root-> next;
    }
    printf("\n");
}

int main(){
    push(25);
    push(35);
    push(15);
    push(95);
    push(75);
    push(65);
    print();
    pop();
    pop();
    print();
    push(16);
    print();
}