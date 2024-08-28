#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

// A utility function to find the vertex with the minimum key value, from
// the set of vertices not yet included in the MST
int minKey(vector<int>& key, vector<bool>& inMST, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!inMST[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(vector<int>& parent, vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

// Function to construct and print the MST for a graph represented using adjacency matrix representation
void primMST(vector<vector<int>>& graph, int V) {
    // Array to store constructed MST
    vector<int> parent(V);

    // Key values used to pick minimum weight edge in cut
    vector<int> key(V, INT_MAX);

    // To represent set of vertices included in MST
    vector<bool> inMST(V, false);

    // Initialize the key of the first vertex to 0 so that it is picked as the first vertex
    key[0] = 0;
    parent[0] = -1; // First node is always the root of the MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, inMST, V);

        // Add the picked vertex to the MST set
        inMST[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)
            // graph[u][v] is non-zero only for adjacent vertices of u
            // inMST[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    printMST(parent, graph, V);
}

int main() {
    // Number of vertices in the graph
    int V = 5;

    // Graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    // Call the function to construct and print the MST using Prim's algorithm
    primMST(graph, V);

    return 0;
}
