#include <stdio.h>

void move(int n, char from, char to, char aux, int *count) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        (*count)++;
    }
    else {
        move(n-1, from, aux, to, count);
        printf("Move disk %d from %c to %c\n", n, from, to);
        (*count)++;
        move(n-1, aux, to, from, count);
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

int main() {
    int n_disks = 8;
    int disks[n_disks];
    for (int i = 0; i < n_disks; i++) {
        disks[i] = i+1;
    }

    int count = 0;
    move(n_disks, 'A', 'C', 'B', &count);
    printf("Total moves: %d\n", count);

    if (count >= 213) {
        display_stacks(2*n_disks-1, disks, n_disks);
    }

    return 0;
}