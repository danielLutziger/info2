//
// Created by danie on 25.06.2023.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int** LCS(char word1[], char word2[]){
    int word1_length = strlen(word1)+1;
    int word2_length = strlen(word2)+1;
    int** helper = (int**)malloc(word1_length * sizeof(int));
    for(int i = 0; i < word1_length; i++){
        helper[i] = (int*)malloc(word2_length * sizeof(int));
    }

    // init helper table
    for(int i = 0; i < word1_length; i++){
        for(int j = 0; j < word2_length; j++){
            helper[i][j] = -1;
        }
    }

    // set first row & first col to 0
    for(int i = 0; i < word1_length; i++){
        helper[i][0] = 0;
    }
    for(int i = 0; i < word2_length; i++){
        helper[0][i] = 0;
    }

    for(int i = 1; i < word1_length; i++){
        for(int j = 1; j < word2_length; j++){
            if(word1[i] == word2[j]){
                helper[i][j] = helper[i-1][j-1] + 1;
            } else {
                if(helper[i-1][j] > helper[i][j-1]){
                    helper[i][j] = helper[i-1][j];
                } else {
                    helper[i][j] = helper[i][j-1];
                }
            }
        }
    }

    return helper;
}

void printLCS(int** helper, char x[], char y[], int i, int j){
    if(i == 0 || j == 0){
        return;
    }
    if(helper[i][j] > helper[i-1][j] && helper[i][j] > helper[i][j-1]){ //come from upper left
        printLCS(helper, x, y, i-1, j-1);
        printf("%c", x[i]);
    } else if(helper[i][j] == helper[i-1][j]){//come from above
        printLCS(helper, x, y, i-1, j);
    } else {
        printLCS(helper, x, y, i, j-1);
    }
}

int main(){
    int** helper = LCS("GTATCT", "GGTTCAT");
    printLCS(helper, "GTATCT", "GGTTCAT", 6, 7);
}