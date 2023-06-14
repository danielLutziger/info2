//
// Created by danie on 06.06.2023.
//


/**
 * recursive pattern:
 *  A
 *   => A
 *
 *  B
 *
 *
 *  C
 *
 *
 *  D
 *
 */

void A(int); void B(int); void C(int); void D(int);
void line(int i){}
void A(int i){
    if (i > 0){
        D(i-1);
        A(i-1);
        B(i-1);
        line(i-1);
    }
}
void B(int i){
    if (i > 0){
        A(i-1);
        B(i-1);
        C(i-1);
        line(i-1);
    }
}
void C(int i){
    if (i > 0){
        B(i-1);
        C(i-1);
        D(i-1);
        line(i-1);
    }
}
void D(int i){
    if (i > 0){
        C(i-1);
        D(i-1);
        A(i-1);
        line(i-1);
    }
}