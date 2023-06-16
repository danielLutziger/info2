//
// Created by danie on 16.06.2023.
//

#include "stdlib.h"
#include "stdio.h"

struct node {
    int value;
    struct node* next;
    struct node* previous;
};

struct node* arrayToList(int A[], int n){
    if(n > 0){
        struct node* root = malloc(sizeof (struct node));
        root->value = A[0];
        root->next = malloc(sizeof (struct node));
        root->previous = NULL;
        struct node* nextNode = root->next;
        struct node* prevNode = root;
        for(int i = 1; i < n; i++){
            nextNode->value = A[i];
            nextNode->previous = prevNode;
            nextNode->next = malloc(sizeof (struct node));
            prevNode = nextNode;
            nextNode = nextNode->next;
        }
        nextNode = prevNode;
        nextNode->next = NULL;
        return root;
    }
    return NULL;
}

struct node* addToList(struct node* list, struct node* add){
    if(list == NULL){
        return add;
    }
    struct node* root = list;
    while(list->next != NULL){
        list = list->next;
    }
    list->next = add;
    add->previous = list;
    return root;
}

struct node* reverseLinkedList(struct node* ll){
    struct node* node; //root
    while(ll != NULL){ //while there is an element
        node = ll;   //assign element
        ll = ll->next;      //ll = root+1
        node->next = node->previous;    //ll was re
        node->previous = ll;
    }
    return node;
}

void printList(struct node* list, int order){
    printf("Print List\n");
    if(order == 0){
        while(list->next != NULL){
            list = list->next;
        }
        while(list != NULL){
            printf("%d, ", list->value);
            list = list->previous;
        }
    }else{
        while(list != NULL){
            printf("%d, ", list->value);
            list = list->next;
        }
    }
    printf("\n");
}


int main(){
    int a[] = {5,3,1,7,3,6,5,4,64,55,10};
    int n = 11;

    struct node* list = arrayToList(a, n);
    struct node* list2 = arrayToList(a, n);
    printList(list, 0);
    printList(list, 1);

    list = addToList(list, list2);
    printList(list, 0);

    list = reverseLinkedList(list);
    printList(list, 0);
    printList(list, 1);

    return 0;
}