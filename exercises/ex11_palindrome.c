//
// Created by danie on 25.06.2023.
//
#include <minmax.h>
#include "stdio.h"

int isPalindrome(char x[], int i, int j) {
    // 0 1 => T
    if (j == 1) return 1; //size of char 1
    // 8 = 4
    // 9 = 4
    int middle = j / 2;
    //0,1,2,3,4,5,6
    // j = 6 = 3 = middle
    //0,1,2,3,4,5 = 2 = middle
    int isPalindrome = 1;
    if (j % 2 == 0) {
        //middle set correctly
        for (int y = 0; y <= middle; y++) {
            if (x[middle + y] != x[middle - y]) {
                isPalindrome = 0;
            }
        }
    } else {
        // middle consists of 2 letters
        for (int y = 0; y <= middle; y++) {
            if (x[middle + y] != x[middle]) {
                isPalindrome = 0;
            }
        }
    }
    return isPalindrome;
}

// ABBCDC = 2
// A BB CDC
int findMinCutsRecursive(char x[], int i, int j) {
    int min = 999999;
    int count = 999999;
    if (i == j || isPalindrome(x, i, j) == 1) {
        return 0;
    }
    for (int a = i; a < j; a++) {
        count = findMinCutsRecursive(x, i, a) + findMinCutsRecursive(x, a + 1, j) + 1;
        if (count < min) {
            min = count;
        }
    }
    return min;
}

// dynamic programming
int findMinCuts(char x[], int n){

    int helperMatrix[n][n];
    int helper_array[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            helperMatrix[i][j] = 0;
        }
        helper_array[i] = 9999;
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i == j){
                helperMatrix[i][j] = 1;
            } else if(x[i] == x[j]){
                if(j-i == 1){
                    helperMatrix[i][j] = 1;
                } else{
                    helperMatrix[i][j] = helperMatrix[i+1][j-1];
                }
            } else{
                helperMatrix[i][j] = 0;
            }
        }
    }

    for(int i = n-1; i>=0; i--){
        if(helperMatrix[i][n-1] == 1){
            helper_array[i] = 0;
        } else {
            for(int j = n-2; j > i-1; j--){
                if(helperMatrix[i][j] == 1){
                    helper_array[i] = min(helper_array[i], 1+helper_array[j+1]);
                }
            }
        }
    }
    return helper_array[0];
}

int main() {
    printf("%d, ", isPalindrome("AGGA", 0, 3));
    printf("%d, ", isPalindrome("AGTGA", 0, 4));
    printf("%d", isPalindrome("AGERGA", 0, 5));
    printf("%d", findMinCutsRecursive("ABBCDC", 0, 5));
    printf("%d", findMinCuts("ABBCDC", 6));
}