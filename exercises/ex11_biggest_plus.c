#include <stdio.h>
#include <minmax.h>

//
// Created by danie on 25.06.2023.
//
void makeHelper(int x, int y, int M[x][y], int top[x][y], int bottom[x][y], int left[x][y], int right[x][y]) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            top[i][j] = 0;
            bottom[i][j] = 0;
            left[i][j] = 0;
            right[i][j] = 0;
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (M[i][j] != 0) {
                // left
                if (j > 0) {
                    left[i][j] = left[i][j - 1] + 1;
                } else {
                    left[i][j] = 1;
                }
                // top
                if (i > 0) {
                    top[i][j] = top[i - 1][j] + 1;
                } else {
                    top[i][j] = 1;
                }
            }
        }
    }
    //right

    // bottom

    for (int i = x - 1; i >= 0; i--) {
        for (int j = y - 1; j >= 0; j--) {
            if (M[i][j] != 0) {
                if (j < y - 1) {
                    right[i][j] = right[i][j + 1] + 1;
                } else {
                    right[i][j] = 1;
                }
                if (i < x - 1) {
                    bottom[i][j] = bottom[i + 1][j] + 1;
                } else {
                    bottom[i][j] = 1;
                }
            }
        }
    }

    printf("\nTOP\n");

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d", top[i][j]);
        }
        printf("\n");
    }

    printf("\nBOT\n");


    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d", bottom[i][j]);
        }
        printf("\n");
    }
    printf("\nLEFT\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d", left[i][j]);
        }
        printf("\n");
    }
    printf("\nRIGHT\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d", right[i][j]);
        }
        printf("\n");
    }
}

int biggestPlus(int x, int y, int M[x][y]) {

    int left[x][y];
    int right[x][y];
    int top[x][y];
    int bottom[x][y];
    makeHelper(x, y, M, top, bottom, left, right);

    int max = 0;
    int newValue;
    int helperMatrix[x][y];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            newValue = min(bottom[i][j], top[i][j]);
            newValue = min(newValue, left[i][j]);
            newValue = min(newValue, right[i][j]);
            if(newValue < 1){
                newValue = 0;
            } else{
                newValue = (newValue - 1) * 4 + 1;
            }
            helperMatrix[i][j] = newValue;
            if(newValue > max){
                max = newValue;
            }
        }
    }
    return max;
}

int main() {
    int x = 5;
    int y = 6;
    int matrix[5][6] = {
            {0, 0, 0, 1, 0, 0},
            {0, 1, 0, 1, 0, 0},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 0, 1, 0, 1},
            {1, 0, 0, 1, 1, 0}
    };

    int left[x][y];
    int right[x][y];
    int top[x][y];
    int bottom[x][y];

    makeHelper(x, y, matrix, top, bottom, left, right);
    biggestPlus(x, y, matrix);
}