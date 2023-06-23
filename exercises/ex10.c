//
// Created by danie on 23.06.2023.
//

// fs exam 21
#include <stdio.h>

#define m 5
struct elem{
    int key;
    int status; // 0 occupied -1 empty
};

struct elem HT[m];

void init(){
    for(int i = 0; i < m; i++){
        HT[i].status = -1;
        HT[i].key = -1;
    }
}

// returns hash for k
int hash(int k, int i){
    return (k%m+i);
}

// returns k position
int HTInsert(int k){
    int iteration = 0;
    int hashValue;
    do{
        hashValue = hash(k, iteration);
        iteration++;
    }while(HT[hashValue].status == 0);
    HT[hashValue].key = k;
    HT[hashValue].status = 0;
    return hashValue;
}

int HTDelete(int k){
    int iterations = 0;
    int hash = k%m;
    while(HT[hash].key != k && iterations < m){
        hash = (hash+1) % m; // 2-3->4->0->1...
        iterations++;
    }
    if(HT[hash].key == k){
        HT[hash].status = -1;
        HT[hash].key = -1;
        // reorder
        iterations = 0;
        int position = hash;
        for(int i = position+1; i < m; i++){
            // reorder elements after deleted one
            if((HT[i].key%m) == position){
                HT[position] = HT[i];
                HT[i].key = -1;
                HT[i].status = -1;
                position = i;
            }
        }

        // reorder probing values
        int reorderPosition = position+1;
        while(reorderPosition < m){
            // check if position is correct
            if((HT[reorderPosition].key%m)!=reorderPosition){
                // move to position
                HT[position].key = HT[reorderPosition].key;
                HT[position].status = HT[reorderPosition].status;
                HT[reorderPosition].key = -1;
                HT[reorderPosition].status = -1;
                position = reorderPosition;
            }
            reorderPosition++;
        }
        return position;
    } else {
        return -1;
    }
}

void printHash(){
    for(int i=0; i<m; i++){
        printf("Position: %d, Key: %d\n", i, HT[i].key);
    }
}

int main(){
    init();
    HTInsert(11);
    HTInsert(22);
    HTInsert(31);
    HTInsert(2);
    printHash();
    HTDelete(11);
    printHash();
}