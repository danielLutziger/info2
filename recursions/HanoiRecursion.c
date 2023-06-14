//
// Created by danie on 10.06.2023.
//

#include <math.h>

int p[3]; //stacks
int N; //# of disks
int M; //# of move counter

void Hanoi(int n, int A, int B, int C){
    if(n == 0) return;
    Hanoi(n-1, A, C, B);
    p[B] = p[B] * 10 + p[A] % 10;
    p[A] = p[A] / 10;
    M++;
    Hanoi(n-1, C, B, A);
}



int main(){
    N = 8;

    int m = 1;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    for(int i = 0; i < N; i++){
        p[0] = p[0] + (i + 1) * m;
        m = m * 10;
    }
    M = 0;
    Hanoi(N, 0,1,2);
}