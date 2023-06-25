//
// Created by danie on 25.06.2023.
//
#include "stdio.h"


// recursive
// O(2^n)
int recursive(int coins[], int numCoins, int amount){
    if(amount == 0) return 0;
    if(amount < 0) return -1;
    int min = -1;
    for(int i = 0; i < numCoins; i++){
        if(coins[i] <= amount){
            int subResult = recursive(coins, numCoins, amount-coins[i]);
            if(min == -1){
                min = subResult+1;
            }
            if(subResult+1 < min){
                min = subResult+1;
            }
        }
    }
    return min;
}


// memoization
// O(n)
int memoResults[100];
int memoization(int coins[], int numCoins, int amount){
    if(amount == 0) return 0;
    if(amount < 0) return -1;
    //memo
    if(memoResults[amount] != -1){
        return memoResults[amount];
    }

    int min = -1;
    for(int i = 0; i < numCoins; i++){
        if(coins[i] <= amount){
            int subResult = memoization(coins, numCoins, amount-coins[i]);
            if(subResult+1 <= min || min == -1){
                min = subResult+1;
                memoResults[amount] = min;
            }
        }
    }
    return min;
}


// dynamic programming
// complexity O(n^2)
int dynamic(int coins[], int numCoins, int amount){
    // helper table to store the min number of coins
    int table[amount + 1];
    for(int i = 0; i <= amount; i++){
        table[i] = -1;
    }

    //best case no swaps needed
    table[0] = 0;

    for(int i = 1; i <= amount; i++){
        for(int j = 0; j < numCoins; j++){
            if(coins[j] <= i){ // 1 <= 1 //1-1 table[0]
                int subResult = table[i - coins[j]];
                //if the subproblem is valid and smaller update
                if(subResult != -1 && (table[i] == -1 || subResult + 1 < table[i])){
                    table[i] = subResult + 1;
                }
            }
        }
    }
    return table[amount];
}


int main(){
    // example coins
    int coins[] = {1,5,20,50};
    int numCoins = sizeof (coins) / sizeof (coins[5]);
    int amount = 45;
    int minCoins = recursive(coins, numCoins, amount);
    printf("Minimum number of coins needed: %d\n", minCoins);

    for(int i = 0; i < 100; i++){
        memoResults[i] = -1;
    }
    int minCoinsMemo = memoization(coins, numCoins, amount);
    printf("Minimum number of coins needed: %d\n", minCoinsMemo);

    int minCoinsDyn = dynamic(coins, numCoins, amount);
    printf("Minimum number of coins needed: %d\n", minCoinsDyn);

}