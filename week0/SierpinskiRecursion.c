//
// Created by danie on 05.06.2023.
//
#include "stdio.h"

int Sierpinski(double x, double y, double h, int d, char pos){
    printf("Sierpinski(%f, %f, %f, %d, %c)\n", x, y, h, d, pos);
    if(d > 0){
        // if depth > 0 then draw 3 triangles
        // triangle 1: (x-h/2, y) // left
        // triangle 2: (x+h/2, y) // right
        // triangle 3: (x, y+h) // up
        Sierpinski(x-(h/2), y+(h/2), (h/2), d-1, 'u'); // left
        Sierpinski(x+(h/2), y+(h/2), (h/2), d-1, 'r'); // right
        Sierpinski(x, y+(h/2), (h/2), d-1, 'l'); // up

    }
}

int main(){
    Sierpinski(0,0,3,4, 'f');
    return 0;
}