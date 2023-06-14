//
// Created by danie on 11.06.2023.
//
#include "stdio.h"

int BinarySearch(int A[], int n, int s){
    int l, r, m;
    l = 0;
    r = n-1;
    m = (l+r)/2;
    while (l <= r && A[m] != s){
        if(A[m] == s ){
          return m;
        } else if(s < A[m]){
            r = m-1;
            m = (l+r)/2;
        } else {
            l = m+1;
            m = (l+r)/2;
        }
    }
    if(l > r) return -1;
   return m;
}

int cntOcc(int A1[], int A2[], int n1, int n2){
    int cnt = 0;
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(A1[i] == A2[j]) cnt++;
        }
    }
    return cnt;
}

int cntOccPerformance(int A1[], int A2[], int n1, int n2){
    int cnt = 0;
    for(int i = 0; i < n1; i++){
        if(BinarySearch(A2, n2, A1[i]) != -1){
            cnt++;
        }
    }
    return cnt;
}

int* bubbleSort(int A[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(A[i] > A[j]){
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }
    return A;
}

int select_kth_smallest(int A[], int n, int kth){
    //sort and return pos kth
    A = bubbleSort(A, n);
    return A[kth-1];
}


/**
 * recurrence relation for maxSub:
 * 2n
 * => n
 * O(n)
 */

int maxSub(int A[], int l, int r, int m){
    int maxLeft = -999999;
    int sum = 0;
    for(int i = m; i >= l; i--){
        sum = sum+A[i];
        if(sum > maxLeft) {
            maxLeft = sum;
        }
    }
    int maxRight = -999999;
    sum = 0;
    for(int i = m+1; i <= r; i++){
        sum= sum+A[i];
        if(sum > maxRight) {
            maxRight = sum ;
        }
    }
    return maxLeft + maxRight;
}

/**
 * recurrence relation for max subarray:
 * T(n) = 2T(n/2) + merge
 * T(n) = 2T(n/2) + n
 *
 * => O(n*log2(n))
 */

int maximumSubarray(int A[], int l, int r){
    if (r == l) return A[l];

    int middle = (l+r)/2;
    int leftArraySum = maximumSubarray(A, l, middle);
    int rightArraySum = maximumSubarray(A, middle+1, r);
    int overlapArraySum = maxSub(A, l, r, middle);
    if(leftArraySum > rightArraySum && leftArraySum > overlapArraySum) return leftArraySum;
    else if(rightArraySum > leftArraySum && rightArraySum > overlapArraySum) return rightArraySum;
    else return overlapArraySum;
}
/**
 * substitution method to calculate the recurrence relation for
 * T(n) = 2T(n-1) + c
 *
 * => 2,4,8,16,32...
 * => good guess = 2^n
 */
int substitutionMethod(int n, int c){
    if(n <= 1) return 1;
    int t = 2*substitutionMethod(n-1, c) + c;
    printf("%d\n", t);
    return t;
}


/**
 * repeated backward substitution method to calculate the recurrence relation for
 * T(n) = 2T(n/2) + c
 *
 * => good guess = log(n)
 */
int backwardSubstitution(int n, int c){
    if(n == 1) return 1;
    int bwS = 2*backwardSubstitution(n/2, c)+c;
    printf("%d\n", bwS);
    return bwS;
}

int main(){
    int A1[] = {12, 4, 10, 8, 9, 33, 2, 18};
    int A2[] = {1,4,5,7,9,22,44,55};
    int n1 = sizeof(A1) / sizeof(A1[0]);

    int n2 = sizeof(A2) / sizeof(A2[0]);

    printf("%d", cntOcc(A1, A2, n1, n2));
    printf("\n%d", cntOccPerformance(A1, A2, n1, n2));
    printf("\n%d", select_kth_smallest(A1, n1, 3));

    int A[] = {-1, 2, -4, 1, 9, -6, 7, -3, 5};
    printf("\n%d", maximumSubarray(A, 0, 8));

    substitutionMethod(12, 0);
    backwardSubstitution(32,0);

    return 0;
}