//
// Created by danie on 08.06.2023.
//
#include <stdio.h>

/**
 * minimum time O(1)
 * maximum time O(n)
 */
int gcd(int m, int n){
    while(m != n){
        if(m > n){
            m = m-n;
        }
        else n = n-m;
    }
    return m;
}

int main(){
    printf("%d", gcd(9,3));
}