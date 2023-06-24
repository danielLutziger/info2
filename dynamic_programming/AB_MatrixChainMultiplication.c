//
// Created by danie on 24.06.2023.
//

#include <limits.h>

int main(){
    int n = 5;
    // array for dimensions (5x4 4x6 6x2 2x7)
    //                       0 1 1 2 2 3 3 4
    int P[] = {5, 4, 6, 2, 7};

    // matrix s and m are completely filled by 0
    int m[5][5] = {0};
    int s[5][5] = {0};

    /**

     |   | 1 | 2 | 3 | 4 |
     |---|---|---|---|---|
     | 1 | 0 | x | y | z |
     | 2 | 0 | 0 | x | y |
     | 3 | 0 |   | 0 | x |
     | 4 | 0 |   |   | 0 |
     *
     * Outer loop finds the values in x, y and z
     * as
     * d < 5-1 => d goes from 1-3 => range from 1-4 = 3
     * d = 1
     * d = 2
     * d = 3
     */
    int j, min, q;
    for(int d = 1; d < n-1; d++){           // going through diagonals
        for(int i = 1; i < n-d; i++){       // going through rows (rows will be reducing as the table above gets less columns per row
            j = i+d;
            min = INT_MAX;
            for(int k =1; k <= j-1; k++){   // finding minimum for formula (e.g m[1,3] = k1
                // this is the formula
                q = m[i][k] + m[k+1][j] + P[i-j] * P[k] * P[j];
                // e.g. k = 1
                // m[1][3] = m[1][1] + m[2][3] + P[0] * P[1] * P [3] = 88
                //           A1 + (A2  A3)
                // m[1][3] = 0 + 48 + 5 * 4 * 2

                // e.g. k = 2
                // m[1][3] = m[1][2] + m[3][3] + P[0] * P [2] * P[3] = 180
                //              120       0       5       6      2
                // k are the possibilities at this level
                // k = 1 => A1 * (A2 * A3)
                // k = 2 => (A1 * A2) * A3
                if(q < min){
                    // min is 88
                    min = q;
                    // fill s (helper table to make the cut)
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
}
