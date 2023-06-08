//
// Created by danie on 08.06.2023.
//

int sum(int A[], int n){
    int s = 0; // execute 1 time
    /**
     * number of executions:
     * i = 0 : 1
     * i < n: n + 1; => because it has to be false (+1)
     * i++: n
     */
    for(int i = 0; i < n; i++){ // executes n + 1 times
        /**
         * content execution: n times
         */
        s = s + A[i];
    }
    return s; // execute 1 time
}

// get time complexity
/**
 * f(n) = n*n + n(n+1) + n+1 + 1 + 1 =  n^2 + n^2 + n + n + 3 = 2n^2 + 2n + 3
 * => O(n^2)
 * Space complexity:
 * A => n^2
 * B => n^2
 * C => n^2
 * n => 1
 * i => 1
 * j => 1
 * => S(n) = 3n^2 + 3 => O(n^2)
 */
int** addMatrix(int** A, int** B, int n){
    int C[n][n];                            // 1
    for(int i = 0; i < n; i++){             // n+1
        for(int j = 0; j < n; j++){         // n(n+1)
            C[i][j] = A[i][j] + B[i][j];    // n*n
        }
    }
    return C;                               // 1
}

// time complexity nested loop
/**
 * Time complexity
 * 1 + n + 1 + n^2 + n + n^2 + n^3 + n^2 + n^3 =>
 * f(n) = 2n^3 + 3n^2 + 2n + 2 => Time: O(n^3)
 *
 * Space complexity
 * S(n) =
 * A, B, C = n^2
 * n, i, j, k = 1
 * => S(n) = 3n^2 + 4 => Space: O(n^2)
 */
int** multiplyMatrix(int** A, int** B, int n){
    int C[n][n];                            // 1
    for(int i = 0; i < n; i++){             // n + 1
        for(int j = 0; j < n; j++){         // n(n + 1)
            C[i][j] = 0;                    // n * n
            for(int k = 0; k < n; k++){     // n * n (n + 1)
                C[i][j] = C[i][j]+A[i][k]*B[k][j];  //n^3
            }
        }
    }
}

int main(){
    /**
     * time function: add all things above together
     *
     * 1 + n + 1 + n + 1 = f(n) = 2n+3 => O(n)
     *
     * Space complexity: A[n], n = 1, s = 1, i = 1 (1 = contains only one value)
     * S(n) = n + 3 => O(n)
     */
}