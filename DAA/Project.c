#include <stdio.h>
#include <limits.h>

#define V 8

// Function to find the vertex with the minimum key value, which is not yet included in MST
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) { 
        // If the vertex is not yet included in MST and the key is smaller than the current min
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        // Print each edge in the MST along with its weight
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to print the path between two vertices in the MST
void printPath(int parent[], int src, int dest) {
    printf("Path between vertices %d and %d:\n", src, dest);
    while (dest != src) {
        printf("%d - ", dest);
        dest = parent[dest];
    }
    printf("%d\n", src);
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V]) {
    int parent[V];   // Array to store constructed MST
    int key[V];      // Key values used to pick minimum weight edge in cut
    int mstSet[V];   // To represent set of vertices included in MST

    // Initialize all keys as infinite and mstSet[] as 0
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;      // Start from vertex 0
    parent[0] = -1;  // First node is always the root of MST

    // The MST will have V-1 edges
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        mstSet[u] = 1;  // Include the picked vertex in MST

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update key[v] only if the graph[u][v] is smaller than key[v] and v is not yet in MST
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);

    // Find and print the path between vertices 0 and 5
    printPath(parent, 0, 5);
}

// Driver program
int main() {
    int graph[V][V] = {
        {0, 4, 10, 12, 15, 16, 26, 26},
        {4, 0, 11, 12, 14, 17, 26, 28},
        {10, 11, 0, 5, 6, 6, 16, 17},
        {12, 12, 5, 0, 2, 6, 13, 15},
        {15, 14, 6, 2, 0, 5, 11, 14},
        {16, 17, 6, 6, 5, 0, 10, 11},
        {26, 26, 16, 13, 11, 10, 0, 4},
        {26, 28, 17, 15, 14, 11, 4, 0}
    };

    // Function to find and print the MST
    primMST(graph);

    return 0;
}