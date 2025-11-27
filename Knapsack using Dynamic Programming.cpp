#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int> &weights, vector<int> &profits, int capacity) {
    int n = weights.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {

                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]],
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> profits = {80, 140, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    int max_profit = knapsack(weights, profits, capacity);
    cout << "Maximum Profit: " << max_profit << endl;

    return 0;
}
