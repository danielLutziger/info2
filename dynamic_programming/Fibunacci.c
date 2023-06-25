//
// Created by danie on 24.06.2023.
//

// 2^n complexity
// same problem is calculated multiple times
int fib1(int n){
    if(n<2) return n;
    return fib1(n-2)+ fib1(n-1);
}

// bottom up approach
// trade space for time
// complexity is now linear
int fib2(int n){
    int f[n+1];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= n; i++){
        f[i] = f[i-2]+f[i-1];
    }
    return f[n];
}

// optimized bottom up, saving space
// space complexity is now O(1)
int fib3(int n){
    int s = 0;
    int t = 1;
    for(int i = 0; i < n; i++){
        int r = t;
        t = t+s;
        s = r;
    }
    return s;
}
int A[20] = {0};
int fibMemo(int n){
    if(n < 2) return n;
    if(A[n] != 0) return A[n];
    else return fibMemo(n-1) + fibMemo(n-2);
}

#include "stdio.h"
int main(){
    printf("%d", fib1(15));
    printf("%d", fib2(15));
    printf("%d", fib3(15));
    printf("%d", fibMemo(15));
}
