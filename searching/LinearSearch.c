//
// Created by danie on 05.06.2023.
//

// regular linear search with complexity O(n)
#include <stdio.h>

#define n 7
int i, v;
int a[] = {11, 4, -2, 36, 12, 19, -2};

void LinearSearch(int i, int v) {
    while (i < n && a[i] != v) { i++; }
    if (i < n) printf("Found at: %d\n", i);
    else printf("NIL\n");
}

int main() {
    LinearSearch(0, -64);
    LinearSearch(0, -2);
    LinearSearch(0, -12);
    LinearSearch(0, 12);
}
