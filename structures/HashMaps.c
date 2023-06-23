//
// Created by danie on 23.06.2023.
//

/**
* uses double hashing to resolve conflicts
*/
#include "stdio.h"
#define m 7

#define OCC 0
#define EMP -1
#define DEL -2

struct HTElement {
    int value;
    int status; // occ emp del
};

void init(struct HTElement A[], int n){
    for(int i = 0; i < n; i++) {
        A[i].status = EMP;
    }
};

int h1(int k){
    return (k % m)+1;
}

int h2(int k){
    return (m-1)-(k % (m-1));
}


// hashing function
int h(int k, int i){
    return ((h1(k) + i*(h2(k))) % m);
}

int search(struct HTElement A[], int key){
    int iteration = 0;
    int i;
    do{
        i = h(key, iteration);
        iteration++;
    }while(A[i].value != key && A[i].status != EMP && iteration < m);

    if(A[i].value == key)
        return i;
    return -1;
}

void insert(struct HTElement A[], int key){
    int iteration = 0;
    int i;
    do{
        i = h(key, iteration);
        iteration++;
    }while((A[i].status == OCC) && iteration < m);
    if(A[i].status == EMP || A[i].status == DEL){
        A[i].value = key;
        A[i].status = OCC;
    }
    else
        printf("not hashable, slots occupied for %d\n", key);
}

// flagging value as del
void delete(struct HTElement A[], int key){
    int position = search(A, key);
    A[position].status = DEL;
}

void printHash(struct HTElement A[], int n){
    for(int i=0; i<n; i++){
        if(A[i].status != EMP)
            printf("Position: %d, Key: %d\n", i, A[i].value);
    }
}

int main(){
    struct HTElement A[m];
    init(A, m);

    insert(A, 1313);
    insert(A, 1314);
    insert(A, 1315);
    insert(A, 2000);
    insert(A, 2001);
    insert(A, 2002);
    delete(A, 1313);
    printHash(A, m);
    insert(A, 4);
    printHash(A, m);
    printf("%d\n", search(A, 2000));
    printf("%d\n", search(A, 10));
    printf("%d\n", search(A, 1314));
    printf("%d\n", search(A, 1313));
    printf("%d\n", search(A, 337));
}