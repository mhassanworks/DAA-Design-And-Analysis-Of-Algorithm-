#include <iostream>
#include <vector>
using namespace std;

// Function to solve the Knapsack problem using dynamic programming
int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Build table dp[][] in a bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Base case: no items or weight = 0
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Return the maximum value that can be obtained
    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    cout << "Maximum value in Knapsack: " << knapsack(W, wt, val, n) << endl;

    return 0;
}
