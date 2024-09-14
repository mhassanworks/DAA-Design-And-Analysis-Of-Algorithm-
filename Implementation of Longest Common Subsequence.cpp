#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the longest common subsequence
int LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D vector to store the length of LCS for different substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The last cell of the dp array contains the length of LCS
    return dp[m][n];
}

// Main function
int main() {
    string X, Y;
    
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int lcs_length = LCS(X, Y);
    cout << "Length of Longest Common Subsequence: " << lcs_length << endl;

    return 0;
}
