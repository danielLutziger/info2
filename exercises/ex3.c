#include <stdio.h>
#include <time.h> // measuring run time

int n, t;
int A[100000000];

int linear_search(int A[], int n, int t) {
    // write you code
    for(int x = 0; x < n; x++){
        if(A[x] == t){
            return 1;
        }
    }
    return 0; // not found
}

int binary_search(int A[], int n, int t) {
    // write your code
    int l, r, m;
    l = 0;
    r = n-1;
    m = (l+r) / 2; //floor
    while (l <= r && t != A[m]){
        if (t<A[m]) r = m-1; else l = m+1;
        m = (l+r) / 2; //floor
    }
    if (l <= r) return 1; // found
    else return 0; // not found
}

int main() {
    clock_t start, end;
    printf("Enter an integer for n: ");
    scanf("%d", &n); 
    printf("Generate an array with %d distinct integers from 1 to %d.\n", n, n);
    for(int i = 0; i < n; i++) A[i] = i + 1;
    printf("Enter an integer for t: \n");
    scanf("%d", &t); 
    start = clock();
    linear_search(A, n, t); // your implementation
    end = clock();
    double run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Linear search takes : %f millseconds\n", run_time); 

    start = clock();
    binary_search(A, n, t); // your implementation
    end = clock();
    run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Binary search takes : %f millseconds\n", run_time); 
}

/**
 * asymptotic complexity for
 * - linear search:
 *      c1 | n
 *      c2 | sum of n
 *      => 2n + 1
 *      => n
 *
 * - binary search
 *      c1 | 1
 *      c2 | 1
 *      c3 | 1
 *      c4 | 1
 *      c5 | log(n)
 *      c6 | 1
 *      c7 | 1
 *      c8 | 1
 *
 *      => log(n) + 7
 *      => log(n)
 *
 * run time:
 * - linear 1, 8, 86
 * - binary: 0, 0, 0
 *
 *
 * ex 2:
 * a) exact analysis fo the running time:
 *      c1 | 1
 *      c2 | n
 *      c3 | 1
 *      c4 | n-i/k
 *      c5 | 1
 *      c6 | 1
 *      c7 | 1
 *      c8 | 1
 *      => n^2-ni/nk + 6
 * b) asymptotic complexity: n^2
 *
 *
 * ex 3:
 * f8(n) = 14400 => O(1)
 * f7(n) = O(poly(n)) => O(n*log^2(n))
 * f3(n) = O(poly(n)) => O(n^2 + n)
 * f4(n) = O(4^poly(n))
 * f2(n) = O(poly(n)) => 6^log(n^2)
 * f5(n) = O(n^4)
 * f1(n) = (2n + 3)! => O(n!)
 *
 * -----
 *
 * f6(n) = O()
 *
 * ex 4:
 * a
 * - pre:
 *  integer array A[1...n], n > 0
 *  n <= k

 * - post
 * n1 <= n2 <= n3 ....
 * Vi € [1...n] : n1 <= A[i]
 * Vi € [1...n] : A[i] != n1 then m2 <= A[i]
 *
 * b
 * i: uploop, sorting the first element first, then second...
 * ii:
 *
 * c
 * - array with the same numbers
 * - all negative numbers
 * - empty array
 * - array of different type
 * - array with 2^32 size
 *
 * d
 * N log(n)
 *
 * e
 * worst case: O(n^2)
 *            xxxx (running time)
 * best case: O(n) (asymptotic)
 *            xxxx (running time)
 *
 * exam: false => n^2
 */