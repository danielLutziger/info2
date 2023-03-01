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
    printf("\n%d", 1%3);
    int n_disks = 8;
    int disks[n_disks];
    for (int i = 0; i < n_disks; i++) {
        disks[i] = i+1;
    }

    int count = 0;
    hanoi(n_disks, 'A', 'C', 'B', &count);
    printf("Total moves: %d\n", count);

    if (count >= 213) {
        display_stacks(2*n_disks-1, disks, n_disks);
    }


}
