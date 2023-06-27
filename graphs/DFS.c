//
// Created by danie on 27.06.2023.
//

/**
* A graph traversal method, similar to preOrderTraversal
 * visited: when
 * explored: when all its adjacent nodes were visited

 Stack representation
 DFS: 1,2
 Stack: 1

 Go on 3, suspend 2 and push to stack
 DFS: 1,2,3
 Stack: 1,2

 => if 3 has adjacent nodes, go to them and push to stack
 DFS: 1,2,3,5
 Stack: 1,2,3

 DFS: 1,2,3,5,7
 Stack: 1,2,3,5

 => 7 cannot go deeper, completely explored
 Stack: pop out
 Stack: 1,2,3
 5->6
 Stack: push again to stack
 DFS: 1,2,3,5,6
 Stack: 1,2,3,5
 => 6 cannot go deeper, completely explored
 Stack: pop out
 5->4
 Stack: push 5 to stack again expore 4..
 DFS: 1,2,3,5,4
 Stack: 1,2,3,5
 => 4 cannot go deeper, completely explored
 Stack: pop 5
 All adjacent nodes are explored, 5 is completely explored
 Stack: pop 3
 ....
*/

#include <stdio.h>

#define N 100
int adjMatrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
};

int stack[N];
int currentElement = -1;

void push(int value) {
    if (N - currentElement == 1) {
        printf("stackoverflow");
        return;
    }
    stack[currentElement++] = value;
}

int pop() {
    if (currentElement == -1) {
        printf("cannot delete from an empty stack");
        return -1;
    }
    return stack[currentElement--];
}

int visited[7] = {0};

void DFS(int G[][7], int start, int n) {
    // check if visited;
    if (visited[start] == 0) {
        printf("%d ", start);
        // mark as visited
        visited[start] = 1;
        for (int v = 0; v < n; v++) {
            if (G[start][v] == 1 && visited[v] == 0) { // check if there is an edge
                DFS(G, v, n);
            }
        }
    }
}

int main(){
    DFS(adjMatrix, 6, 7);
}