//
// Created by danie on 24.06.2023.
//
#include <stdio.h>
int longestPath(int x, int y, int matrix[x][y]){

    int helper[x][y];
    int max = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            helper[i][j] = 1;
        }
    }

    for(int p = 0; p < x; p++){
        for(int q = 0; q < y; q++){
            if(q > 0){
                if(matrix[p][q] - matrix[p][q-1] >= -1 && matrix[p][q] - matrix[p][q-1] <= 1){
                    helper[p][q] = helper[p][q-1]+1;
                    if(max < helper[p][q])
                        max = helper[p][q];
                }
            }
            if(p > 0){
                if(matrix[p][q] - matrix[p-1][q] >= -1 && matrix[p][q] - matrix[p-1][q] <= 1){
                    helper[p][q] = helper[p-1][q]+1;
                    if(max < helper[p][q])
                        max = helper[p][q];
                }
            }
        }
    }
    return max;
}
int main(){
    int matrix[4][6] = {{1,7,3,2,6,1},{2,5,4,5,9,3},{6,3,2,6,6,6},{8,7,5,4,8,7}};

    printf("%d", longestPath(4,6, matrix));
}