//
// Created by danie on 13.06.2023.
//

#include "stdio.h"

/**
 * @param H: heap array
 * @param n: index of element to insert into the heap
 */
void insert(int H[], int n){
    int i = n, temp;
    temp = H[i];
                  // compare with parent
    while(i > 1 && temp > H[i/2]){
        H[i] = H[i/2];
        i = i/2;
    }
    H[i] = temp;
}

/**
 *
 * @param H : heap
 * @param n : exact size of heap
 */
int delete(int H[], int n){
    int i,j,val;
    // replace first element with the last element
    val=H[1];
    H[1]=H[n];
    H[n] = val;
    i = 1;
    j = i*2;
    // heap is reduced by 1 (from replacement above)
    while(j < n-1){
        if(H[j+1] > H[j])
            j = j+1;
        if(H[i] < H[j]){
            int temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j;
            j = 2*j;
        } else{
            break;
        }
    }
    return val;
}

int main(){
    // location 0 will be ignored
    int H[] = {0,10,20,30,25,5,40,35};
    // expected structure:
    //40,25,35,10,5,20,30 (based on how the insert works for heaps)

    for(int i = 1; i <=7; i++){
        insert(H, i);
    }

    for(int i = 1; i <=7; i++){
        printf("%d, ", H[i]);
    }
    for(int i = 7; i >= 1; i--){
        printf("\nDeleted %d, \n", delete(H, i));
    }
    for(int i = 1; i <=7; i++){
        printf("%d, ", H[i]);
    }
    //insert(H, 2);
    //insert(H, 3);
    //insert(H, 4);
    //insert(H, 5);
    // inserting 5,8,9,4

    return 0;
}