#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

const int INF = INT_MAX; // Infinity to represent unvisited cities

// Function to calculate the TSP using dynamic programming and bitmasking
int tsp(int mask, int pos, const vector<vector<int>>& dist, vector<vector<int>>& dp, int n) {
    if (mask == (1 << n) - 1) {
        // All cities have been visited, return to the starting city
        return dist[pos][0];
    }

    // If the subproblem has already been solved, return the stored result
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    // Try to visit all cities that have not been visited yet
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            // City has not been visited, so visit it
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp, n);
            ans = min(ans, newAns);
        }
    }

    // Store the result in the dp table
    dp[mask][pos] = ans;
    return ans;
}

int main() {
    int n;

    // Input number of cities
    cout << "Enter the number of cities: ";
    cin >> n;

    // Distance matrix
    vector<vector<int>> dist(n, vector<int>(n));

    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // DP table to store intermediate results
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    // Start the TSP from city 0 and initial mask (only city 0 visited)
    int result = tsp(1, 0, dist, dp, n);

    // Output the result
    cout << "The minimum cost of the TSP tour is: " << result << endl;

    return 0;
}
