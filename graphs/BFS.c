//
// Created by danie on 27.06.2023.
//

/**
 *
         *  Adjacency matrix
            1   2   3   4   5   6   7
     1  0   1   1   1   0   0   0
         2  1   0   1   0   0   0   0
         3  1   1   0   1   0   0   0
         4  1   0   1   0   1   0   0
         5  0   0   1   1   0   1   1
         6  0   0   0   0   1   0   0
         7  0   0   0   0   1   0   0

 */

// required data strucure: queue
// required array: visited

/**
 * BFS  is for visiting and exploring a graph
 */

#include <stdio.h>
#define N 100
int queue[N];
int currentValue = -1;
int adjMatrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
};
void enqueue(int value){
    if(N-currentValue == 1){
        printf("queue is full, cannot add element");
        return;
    }
    currentValue+=1;
    queue[currentValue] = value;
}

int dequeue(){
    if(currentValue == -1){
        printf("cannot dequeue from an empty queue\n");
        return -1;
    }
    int rv = queue[0];
    for(int i = 1; i <= currentValue; i++){
        queue[i-1] = queue[i];
    }
    --currentValue;
    return rv;
}

int isEmpty(){
    return currentValue == -1 ? 1 : 0;
}

int visited[7] = {0}; // init as not visited

// pass the starting vertex
void BFS(int i){
    printf("%d ", i);

    // mark vertex as visited
    visited[i] = 1;
    enqueue(i);
    while(isEmpty() != 1){
        // u will be explored
        int u = dequeue();
        for(int v = 0; v < 7; v++){
            if(adjMatrix[u][v] == 1 && visited[v] == 0) {// if there is an edge and not yet visited
                printf("%d ", v);
                visited[v] = 1;         // mark as visited
                enqueue(v);       // drop into queue to be visited as next
            }
        }
    }
}

int main(){
    BFS(5);
}