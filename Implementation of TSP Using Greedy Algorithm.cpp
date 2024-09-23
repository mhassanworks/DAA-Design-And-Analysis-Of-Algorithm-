#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define N 5  // Number of cities

// Function to find the minimum cost for the TSP using a Greedy approach
int tspGreedy(int graph[N][N], int start) {
    vector<bool> visited(N, false);  // Track visited cities
    visited[start] = true;  // Mark the starting city as visited

    int currentCity = start;
    int totalCost = 0;

    for (int i = 1; i < N; ++i) {
        int nearestCity = -1;
        int minDistance = INT_MAX;

        // Find the nearest unvisited city
        for (int j = 0; j < N; ++j) {
            if (!visited[j] && graph[currentCity][j] < minDistance) {
                minDistance = graph[currentCity][j];
                nearestCity = j;
            }
        }

        // Move to the nearest city
        totalCost += minDistance;
        currentCity = nearestCity;
        visited[currentCity] = true;
    }

    // Return to the starting city to complete the tour
    totalCost += graph[currentCity][start];

    return totalCost;
}

int main() {
    // Adjacency matrix representing the graph (distances between cities)
    int graph[N][N] = {
        {0, 10, 15, 20, 25},
        {10, 0, 35, 25, 30},
        {15, 35, 0, 30, 20},
        {20, 25, 30, 0, 18},
        {25, 30, 20, 18, 0}
    };

    int startCity = 0;  // Starting from city 0
    cout << "Total cost of TSP (using Greedy Algorithm): " << tspGreedy(graph, startCity) << endl;

    return 0;
}
