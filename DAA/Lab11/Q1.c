#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Function to create a graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = 0; // Initialize E to 0
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Increment E outside the loop
    graph->edges[graph->E].src = src;
    graph->edges[graph->E].dest = dest;
    graph->edges[graph->E].weight = weight;
    graph->E++;
}

// Function to print the minimum spanning tree in adjacency matrix format
void printMST(int parent[], struct Graph* graph) {
    printf("Minimum Spanning Tree (Adjacency Matrix Format):\n");

    // Initialize an empty matrix with 0 values
    int adjacencyMatrix[graph->V][graph->V];
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    // Fill the matrix with the weights of edges in the MST
    for (int i = 1; i < graph->V; i++) {
        int src = parent[i];
        int dest = i;
        int weight = graph->edges[i - 1].weight; // Adjust index to get the correct weight

        // Update the matrix with the weight of the edge
        adjacencyMatrix[src][dest] = weight;
        adjacencyMatrix[dest][src] = weight;
    }

    // Print the adjacency matrix
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d\t", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to construct and find the minimum spanning tree
void findMinimumSpanningTree(struct Graph* graph) {
    int parent[graph->V];
    int key[graph->V];
    bool mstSet[graph->V];

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < graph->V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < graph->V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u;
        int min = INT_MAX;
        for (int v = 0; v < graph->V; v++) {
            if (!mstSet[v] && key[v] < min) {
                u = v;
                min = key[v];
            }
        }

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < graph->V; v++) {
            if (!mstSet[v] && graph->edges[u].weight < key[v]) {
                parent[v] = u;
                key[v] = graph->edges[u].weight;
            }
        }
    }

    // Print the constructed MST in adjacency matrix format
    printMST(parent, graph);
}

int main() {
    int V, E;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);

    // Create a graph
    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges in the format (src, dest, weight):\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    // Find the minimum spanning tree
    findMinimumSpanningTree(graph);
    free(graph->edges);
    free(graph);

    return 0;
}
