//
// Created by danie on 15.06.2023.
//

#include "stdio.h"
#include "stdlib.h"
#define N 10

struct node {
    int key;
    struct node* next;
};

struct node* convertArrayToLinkedList(int *arr, int n){
    // create a root element
    struct node* root = malloc(sizeof (struct node));
    root->key = arr[0];
    root->next = malloc(sizeof (struct node)); // allocate empty storage to root
    struct node* node = root->next; // assign next value to this empty storage
    for(int i = 1; i < n; i++){  //iterate through the objects
        node->key = arr[i];
        node->next = malloc(sizeof (struct node));
        if(i+1 == n){
            node->next = NULL;
        } else {
            node = node->next;
        }
    }
    return root;
}

void print(struct node* curr){
    while(curr != NULL){
        printf("%d, ", curr->key);
        curr = curr->next;
    }
}

struct node* reverseLinkedList(struct node* head){
    //create array of linked list
    //swap array places
    //convert to linked list
    /*
    int a[N];
    int i = 0;
    while(head->next != NULL){
        a[i] = head->key;
        i++;
        head = head->next;
    }
    for(int j = 0; j <= N/2; j++){
        int t = a[j];
        a[j] = a[N-1-j];
        a[N-1-j] = t;
    }
    return convertArrayToLinkedList(a, N);
    */
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    return prev;
}

int getOccurrencesOfElement(struct node* linkedList, int searchValue){
    int occurrences = 0;
    while(linkedList != NULL){
        if(searchValue == linkedList->key){
            occurrences++;
        }
        linkedList = linkedList->next;
    }
    return occurrences;
}

struct node* insertIntoLinkedListAtPosition(struct node* linkedList, int value, int position){
    struct node* newNode = malloc(sizeof (struct node));
    newNode->key = value;
    if(linkedList == NULL || position == 0){
        newNode->next = linkedList;
        linkedList = newNode;
    } else{
        struct node* nodes = linkedList;
        int i = 0;
        while(nodes->next != NULL && i < position){
            nodes = nodes->next;
            i++;
        }
        newNode->next = nodes->next;
        nodes->next = newNode;
    }

    return linkedList;
}

/*
 * could be used to append a list as well
 * */
struct node* appendElementToLinkedList(struct node* list1, struct node* list2){
    // save root node else it will be lost
    struct node* rootNode = list1;
    while(list1->next != NULL){
        list1 = list1->next;
    }
    list1->next = list2;
    return rootNode;
}

struct node* deleteElementFromLinkedListByValue(struct node* node, int value){
    struct node* root = node;
    if(root->key == value && root->next != NULL){
        root = node->next;
        free(node);
    } else{
        while(node != NULL){
            if(node->next->key == value){
                struct node* todel = node->next;
                node->next = todel->next;
                free(todel);
                return root;
            }
            node = node->next;
        }
    }
    return root;
}
struct node* deleteElementFromLinkedListByIndex(struct node* node, int position){
    int i = 0;
    struct node* root = node;
    while(i < position){
        if(node == NULL){return root;}
        node = node->next;
        i++;
    }
    struct node* freeNode = node->next;
    node->next = node->next->next;
    free(freeNode);
    return root;
}

void freeLinkedListAndReturnMemory(struct node* ll){

    while(ll != NULL){
        struct node* prev = ll;
        ll = ll->next;
        free(prev);
    }
}

int main(){
    int *arr;
    arr = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        *(arr+i) = i;//rand();
    }
    struct node *list2 = convertArrayToLinkedList(arr, N);
    struct node *head = convertArrayToLinkedList(arr, N);
    printf("\nThe og.\n");
    print(head);

    struct node *newHead = reverseLinkedList(head);

    printf("\nUNo reverse\n");
    print(newHead);

    struct node *bigList = appendElementToLinkedList(newHead, list2);

    printf("\nChonk\n");
    print(bigList);

    printf("\nOccurrences: %d\n", getOccurrencesOfElement(bigList, 9));

    printf("\nInsert at position\n");
    bigList = insertIntoLinkedListAtPosition(bigList, 53, 15);
    print(bigList);printf("\n");
    bigList = insertIntoLinkedListAtPosition(bigList, 69, 1);
    print(bigList);printf("\n");
    bigList = insertIntoLinkedListAtPosition(bigList, 5335, 400);
    print(bigList);printf("\n");
    bigList = insertIntoLinkedListAtPosition(bigList, 5235, 400);
    print(bigList);printf("\n");
    bigList = insertIntoLinkedListAtPosition(bigList, 82, 0);
    bigList = insertIntoLinkedListAtPosition(bigList, 9, 0);
    bigList = insertIntoLinkedListAtPosition(bigList, 9, 10);
    bigList = insertIntoLinkedListAtPosition(bigList, 9, 22);
    print(bigList);printf("\n");
    printf("\nOccurrences: %d\n", getOccurrencesOfElement(bigList, 9));

    bigList = deleteElementFromLinkedListByValue(bigList, 9);
    print(bigList);printf("\n");

    printf("\nOccurrences: %d\n", getOccurrencesOfElement(bigList, 9));
    bigList = deleteElementFromLinkedListByIndex(bigList, 16);
    print(bigList);printf("\n");

    freeLinkedListAndReturnMemory(bigList);


    return 0;
}