//
// Created by danie on 27.06.2023.
//

// required data structures
// - graph is required (adjacency matrix) : 2D array
// - 2D array to store the spanning tree
// - helper array (near array) to find out which nodes are closer to 1 or 6

#include <stdio.h>
#include <limits.h>

int near[7] = {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
int cost[][7] = {
        {INT_MAX, 25,      INT_MAX, INT_MAX, INT_MAX, 5,       INT_MAX},
        {25,      INT_MAX, 12,      INT_MAX, INT_MAX, INT_MAX, 10},
        {INT_MAX, 12,      INT_MAX, 8,       INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 8,       INT_MAX, 16,      INT_MAX, 14},
        {INT_MAX, INT_MAX, INT_MAX, 16,      INT_MAX, 20,      18},
        {5,       INT_MAX, INT_MAX, INT_MAX, 20,      INT_MAX, INT_MAX},
        {INT_MAX, 10,      INT_MAX, 14,      18,      INT_MAX, INT_MAX}
};
int mst[2][6];

// matrix is mirrored due to tree which is undirected
// search in matrix for the lowest value
//


/**
 * prims algorithm:
 * - selected the minimum edge
 * > select the next edge which is connected to the selected one and the min
 * > fill in the helper array with all the edges closer to 1 | 6
 * >> 1 = 0 already discovered
 * >> 6 = 0 already discovered
 * >> 1 to 2 is cloer than 1 to 6 so 1
 * >> 1 to 3 is max int == 6 to 3 also max_int as not already discovered = 6
 */

int main() {
    int i, j, k, u, v, n = 7, min = INT_MAX;
    // discover smallest edge
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                // save minimum cost edge in u and v
                u = i;
                v = j;
            }
        }
    }
    // store minimum edge in mst
    mst[0][0] = u;
    mst[1][0] = v;
    near[u] = near[v] = 0;
    for (i = 0; i < n; i++) {
        if (near[i] != 0 && cost[i][u] < cost[i][v]) {
            near[i] = u;
        } else {
            near[i] = v;
        }
    }
    // because the first one is already in the mst
    for (i = 1; i < n - 1; i++) {
        min = INT_MAX;
        for (j = 0; j < n; j++) {
            if (near[j] != 0 && cost[j][near[j]] < min) {
                k = j;
                min = cost[j][near[j]];
            }
        }
        mst[0][i] = k;
        mst[1][i] = near[k];
        near[k] = 0;

        //update near array to check whether other edges are closer
        for (j = 0; j < n; j++) {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]]) {
                near[j] = k;
            }
        }
    }

    //print solution
    for (i = 0; i < n - 1; i++) {
        printf("%d, %d\n", mst[0][i], mst[1][i]);
    }
    return 0;
}
