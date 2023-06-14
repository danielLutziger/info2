//
// Created by danie on 14.06.2023.
//

#include <stdio.h>
#include <stdlib.h>

/**
* Pointer:
 * - used for access resources
 * - parameter passing
 * -> pointer stores a memory address
*/

int main() {

    // data variable
    int a = 25;

    // pointer variable declaration
    int *p;

    p = &a; // pointer now has address of a => pointing to the same value

    printf("%d \n", a);
    printf("%p\n", p); // print the pointer address
    printf("%d\n", *p); // to follow the pointer, dereferencing

    int A[] = {2,4,6,8,1};
    int *r = A;  // pointing to the array

    int *s = &A[1]; // pointing to a specific element
    printf("%d\n", *s);
    for(int i = 0; i < 5; i++){
        printf("%d\n", A[i]);
        printf("%d\n", r[i]);
    }


    // allocate an empty array to a pointer, the array is created in the heap not stack
    int *q;
    int arraySize = 5;
    q = malloc(arraySize * sizeof(int)); // allocate memory in the heap for an array
    q[0] = 5;
    q[1] = 6;
    q[2] = 42;
    q[3] = 21;
    q[4] = 32;
    for(int i = 0; i < 5; i++){
        printf("%d\n", q[i]);
    }

    // deallocation and free memory in the heap
    free(q);

    /*
     * every pointer takes the same amount of memory (8 bites)
     * */
}