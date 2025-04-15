#include <iostream>
using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n+1][capacity+1];

    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int weights[] = {1, 3, 4, 5};
    int values[]  = {10, 40, 50, 70};
    int capacity = 7;
    int n = sizeof(weights) / sizeof(weights[0]);

    int maxProfit = knapsack(weights, values, n, capacity);
    cout << "Maximum value in knapsack = " << maxProfit << endl;

    return 0;
}
