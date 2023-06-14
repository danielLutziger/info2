//
// Created by danie on 01.03.2023.
//

#include <string.h>
#include "stdio.h"

/**
* RecursiveAlgo Algo:
 *
 * takes the initial string as parameter, together with the starting number and string length
 * => it checks whether s == e (meaning that currently indices are at the same position and the
 * word has an odd number of characters)
 *
 * => then it checks if the letters at the current positions (beginning and at the end) are the same
 *  (e.g. car => c != r => return false ||| racecar => r != r => continue)
 *
 *  => the next check is if the word is not yet finished and there are still some letters left
 *     if it is not yet finished, it calls itself again with updated indices, moving the index from the
 *     beginning to +1 and the one at the end to -1
 * => the return value of the function is true (1) if it is a palindrome and false (0) if it is not
 *
 *
 *  => solution: what the algo returns, it returns true / 1
 *  => uses recursion to check if a word is a palindrome (same spelled forward and backward)
 *
 *  Base cases: s == e || s != e || s < e+1 => conditions on which the algorithm ends
 *
 *  Complexity: linear time complexity => you go through the array once from left to right and right to left
 *  => O(n/2)
*/

int RecursiveAlgo(char c[], int s, int e){
    if (s == e) return 1;
    if (c[s] != c[e]) return 0;
    if (s < e+1) return RecursiveAlgo(c, s+1, e-1);
    return 1;
}

/**
 * printRec
 * 2.1 (20)
 * 00101
 *
 * 01010
 *
 * 2.2:
 * printRec(20)
 * printRec(10)
 * printRec(5)
 * printRec(2)
 * printRec(1)
 * printRec(0)
 *
 * 2.3
 *
 */

void printRec(int n){
    if (n == 0) return;
    printf("%d", n%4==0?n%4:n%4-1);
    printRec(n/2);
}

void hanoi(int n, char from, char to, char aux, int *count){
    if (n == 1){
        printf("Move Disk from %c to %c", from, to);
        (*count)++;
    } else {
        hanoi(n-1, from, aux, to, count);
        (*count)++;
        hanoi(n-1, aux, to, from, count);
    }
}

void display_stacks(int n, int disks[], int n_disks) {
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            int disk_size = 0;
            for (int k = 0; k < n_disks; k++) {
                if (disks[k] == j+1 && k >= n_disks-i-1) {
                    disk_size = k+1;
                    break;
                }
            }
            for (int k = 0; k < n_disks-disk_size; k++) {
                printf(" ");
            }
            for (int k = 0; k < 2*disk_size-1; k++) {
                printf("*");
            }
            for (int k = 0; k < n_disks-disk_size; k++) {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void drawPyramidScheme(int A[], int n, int drawingSize){

    drawingSize /= n+1;
    for(int i = 0; i < n; i++){
        printf("%*d", drawingSize, A[i]);
    }
    printf("\n");
/*
    for (int j = 0; j <= drawingSize; j++) {
        printf(" ");
    }
    for (int j = 0; j < n; j++) {
        if(A[j]<10){
            printf("%d  ", A[j]);
        }else{
            printf("%d ", A[j]);
        } }
    printf("\n");*/
}
void pyramidScheme(int A[], int n, int drawingSize){
    if (n == 0){
        return;
    }
    int a[n-1];
    for(int i = 0; i < n-1; i++){
        a[i] = A[i] + A[i+1];
    }
    pyramidScheme(a, n-1, drawingSize);
    drawPyramidScheme(A, n, drawingSize);
}

int main(){
    /**
     * recursive algo
     */
    char str[8] = "raceecar";
    int n = 8;
    int res = 0;
    if (n > 0) res = RecursiveAlgo(str, 0, n-1);
    printf("%s\n", res?"true":"false");
    printRec(20);
    printf("\n");
    /*int n_disks = 8;
    int disks[n_disks];
    for (int i = 0; i < n_disks; i++) {
        disks[i] = i+1;
    }

    int count = 0;
    hanoi(n_disks, 'A', 'C', 'B', &count);
    printf("Total moves: %d\n", count);

    if (count >= 213) {
        display_stacks(2*n_disks-1, disks, n_disks);
    }*/

    int A[5] = {5,4,6,1,3};
    pyramidScheme(A, 5, 25);

}
