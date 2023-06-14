//
// Created by danie on 06.06.2023.
//
#include "stdio.h"
#include "math.h"

/**
 * --------
 * |      |
 * |      |
 *
 * |-------
 * |
 * |-------
 *
 * -------|
 *        |
 * -------|
 *
 * |      |
 * |      |
 * --------
 */

void A(int); void B(int); void C(int); void D(int);

void A(int i){
    if(i > 0){
        D(i-1);
        //line(-u, 0); //right-left
        A(i-1);
        //line(0, -u); //down
        A(i-1);
        //line(u, 0); //left-right
        B(i-1);
    }
}
void B(int i){
    if(i > 0){
        C(i-1);
        //line(0,u) // up
        B(i-1);
        //line(u,0)
        B(i-1);
        //line(0, -u)
        A(i-1);
    }
}
void C(int i){
    if(i > 0){
        B(i-1);
        //line(u,0)
        C(i-1);
        //line(0,u)
        C(i-1);
        //line(-u,0)
        D(i-1);
    }
}
void D(int i){
    if(i > 0){
        C(i-1);
        //line(-u,0)
        D(i-1);
        //line(0,-u)
        D(i-1);
        //line(u,0)
        A(i-1);
    }
}

int main(int argc, char **argv){
    //glutInit(&argc, argv);
    //glutCreateWindow("glut");
    return 0;
}