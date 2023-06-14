//
// Created by danie on 14.06.2023.
//

#include <malloc.h>

struct rectangle {
    int length;
    int width;
};

int main(){

    struct rectangle rect = {3,5};

    // assign the reference to p
    struct rectangle *p = &rect;

    // set value with variable
    rect.width = 36;
    // set value with pointer
    p->length = 25;

    struct rectangle *q = malloc(sizeof(struct rectangle));
    q->width = 10;
    q->length  =25;

    return 0;
}