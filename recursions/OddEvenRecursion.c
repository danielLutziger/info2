//
// Created by danie on 05.06.2023.
//
#include <stdio.h>

// function prototype
int even(int n);

int odd(int n){
    if(n == 0) return 0;
    else even(n-1);
}

int even(int n){
    if(n == 0) return 1;
    else odd(n-1);
}

int main(){
    printf("%d\n", odd(16));
    printf("%d\n", odd(15));
    printf("%d\n", even(16));
    printf("%d\n", even(17));
    return 0;
}