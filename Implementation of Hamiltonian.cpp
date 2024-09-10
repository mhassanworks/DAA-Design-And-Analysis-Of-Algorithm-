#include <iostream>
#include <vector>
using namespace std;

#define V 5  // Number of vertices in the graph

/* A utility function to check if the vertex v can be added at index 'pos'
   in the Hamiltonian Cycle constructed so far (stored in 'path[]') */
bool isSafe(int v, const vector<vector<int>>& graph, vector<int>& path, int pos) {
    // Check if the current vertex is adjacent to the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

/* A recursive utility function to solve the Hamiltonian Cycle problem */
bool hamCycleUtil(const vector<vector<int>>& graph, vector<int>& path, int pos) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
        // And if there is an edge from the last vertex to the first vertex
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Try different vertices as the next candidate in the Hamiltonian Cycle.
    for (int v = 1; v < V; v++) {
        // Check if the vertex can be added to the path
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            // If adding vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }

    // If no vertex can be added, return false
    return false;
}

/* This function solves the Hamiltonian Cycle problem using Backtracking.
   It returns false if there is no Hamiltonian Cycle, otherwise, it returns true
   and prints the cycle. */
bool hamCycle(const vector<vector<int>>& graph) {
    vector<int> path(V, -1);  // Stores the Hamiltonian Cycle path
    path[0] = 0;              // Start from the first vertex

    // Use hamCycleUtil to solve the problem
    if (!hamCycleUtil(graph, path, 1)) {
        cout << "Solution does not exist\n";
        return false;
    }

    // If a solution exists, print the path
    cout << "Hamiltonian Cycle exists: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;  // To form a cycle
    return true;
}

int main() {
    /* Example graph represented as an adjacency matrix */
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamCycle(graph);
    return 0;
}
