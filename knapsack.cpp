#include <bits/stdc++.h>
using namespace std;

// Function to solve 0/1 Knapsack
int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Filling the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W]; // Max value possible
}

int main() {
    int W = 50; // Maximum weight of knapsack
    vector<int> wt = {10, 20, 30}; // Weights of items
    vector<int> val = {60, 100, 120}; // Values of items
    int n = wt.size();

    cout << "Maximum Value in Knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;
}
