//
// Created by danie on 05.06.2023.
//
#include <stdio.h>

int fact(int n) {
    if (n == 0) return 1;
    else return n * fact(n - 1);
}

int main() {
    printf("%d", fact(3));
}