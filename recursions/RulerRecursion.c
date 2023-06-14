//
// Created by danie on 05.06.2023.
//
#include "stdio.h"

int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int n = 10;

void Mark(int m, int h) {
    printf("Mark(%d, %d)\n", m, h);
    a[m] = h;
}

void Ruler(int l, int r, int h) {
    printf("Ruler(%d, %d, %d)\n", l, r, h);
    int m = (r + l) / 2;
    if (h > 0) {
        Mark(m, h);
        Ruler(l, m, h - 1);
        Ruler(m, r, h - 1);
    }
}

int main() {
    Ruler(0, 9, 3);
    for (int x = 0; x < 9; x++)
        printf("%d ", a[x]);
}