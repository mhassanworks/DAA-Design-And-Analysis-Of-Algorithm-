#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INF INT_MAX  // Define a large value to represent infinity

// Function to print the solution matrix
void printSolution(const vector<vector<int>>& dist, int V) {
    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

// Floyd-Warshall Algorithm
void floydWarshall(vector<vector<int>>& graph, int V) {
    // Create a distance matrix and initialize it with the graph's adjacency matrix
    vector<vector<int>> dist = graph;

    // Update the distance matrix with the shortest paths
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j, then update dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the final shortest distance matrix
    printSolution(dist, V);
}

int main() {
    int V;  // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (use " << INF << " to represent infinity):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    // Run the Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}
