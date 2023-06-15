//
// Created by danie on 15.06.2023.
//

#include <stdio.h>
#include "malloc.h"

int main(){
    int a = 1;
    int *p;
    p = &a;

    printf("%p\n", p);
    // points to the address of a
    // a contains the value 1

    int b = 1;
    int *q;
    q = malloc(sizeof(int));
    *q = 2;

    // prints value of q
    printf("%d\n", *q);
    // prints address of q
    printf("%p\n", q);
    b = *q; // overwriting a's value with q's value
    free(q); // deleting pointer

    printf("%d\n", b);

    int c[3] = {1,2,3};
    int *r;
    r = c;
    printf("Array address: %p\n", &c);
    printf("Pointer address: %p\n", r);
    printf("Pointer value: %d\n", *r);
    printf("--------\n");
    printf("Array address: value 1: %p\n", &c[0]);
    printf("Array address: value 2: %p\n", &c[1]);
    printf("Array address: value 3: %p\n", &c[2]);
    r++;
    printf("-----r++---\n");
    printf("Pointer ++ address: %p\n", r);
    printf("Pointer ++ value: %d\n", *r);
    r++;
    printf("-----r++---\n");
    printf("Pointer ++ address: %p\n", r);
    printf("Pointer ++ value: %d\n", *r);
    r++;
    printf("-----r++---\n");
    printf("Pointer ++ address: %p\n", r);
    printf("Pointer ++ value: %d\n", *r);
    r++;
    printf("-----r++---\n");
    printf("Pointer ++ address: %p\n", r);
    printf("Pointer ++ value: %d\n", *r);
    r++;
    printf("-----r++---\n");
    printf("Pointer ++ address: %p\n", r);
    printf("Pointer ++ value: %d\n", *r);
    r = r-4;
    printf("-----r-4---\n");
    printf("Pointer ++ address: %p\n", r);
    printf("Pointer ++ value: %d\n", *r);

    int *s;
    s = &c[0];
    printf("-----s---\n");
    printf("Pointer ++ address: %p\n", s);
    printf("Pointer ++ value: %d\n", *s);
    s++;
    printf("-----s---\n");
    printf("Pointer ++ address: %p\n", s);
    printf("Pointer ++ value: %d\n", *s);

    printf("-----d---\n");
    int d = *(c+1);
    printf("Value assignment of d : %d\n", d);

    for(int i = 0; i < 3; i++){
        printf("Array value %d : %d\n", i, c[i]);
    }

    int e[3] = c;

    return 0;
}