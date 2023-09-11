//Date :11-9-2023

// From a given vetex in the weighted connected graph, find shortest paths to other vertices using Dijkstra's algorithm.

#include <stdio.h> 
#include <limits.h>
#include <stdlib.h>

struct Graph {
    int V;     // number of vertices
    int E;    // number of edges
    int **Adj; // adjacency matrix
};

struct Graph *adjMatrixOfGraph();
void printAdjMatrix(struct Graph *G);   //print tjhe adjacency matrix of the graph
void dijkstra(struct Graph *G, int s); // find shortest paths from source s to all other vertices

int main() {
    struct Graph *G = adjMatrixOfGraph();
    printAdjMatrix(G);
    dijkstra(G, 0);
    return 0;
}

struct Graph *adjMatrixOfGraph() 
{
    int i, u, v, w;
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    if (!G) {
        printf("Memory Error");    
        return NULL;
    }
    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &G->V, &G->E);
    G->Adj = (int **)malloc(sizeof(int *) * G->V);
    for (i = 0; i < G->V; i++)
        G->Adj[i] = (int *)malloc(sizeof(int) * G->V);
    for (u = 0; u < G->V; u++)
        for (v = 0; v < G->V; v++)
            G->Adj[u][v] = 0;
    printf("Enter %d edges with weights:\n", G->E);
    for (i = 0; i < G->E; i++) {
        scanf("%d%d%d", &u, &v, &w);   // edge (u, v) with weight w 
        G->Adj[u][v] = w;
        G->Adj[v][u] = w;
    }
    return G;
}

void printAdjMatrix(struct Graph *G) 
{
    int u, v;
    for (u = 0; u < G->V; u++) {
        for (v = 0; v < G->V; v++)
            printf("%d ", G->Adj[u][v]);
        printf("\n");
    }
}

void dijkstra(struct Graph *G, int s) 
{
    int i, j, u, v, min;
    int *distance = (int *)malloc(sizeof(int) * G->V);
    int *visited = (int *)malloc(sizeof(int) * G->V);
    int *path = (int *)malloc(sizeof(int) * G->V);
    for (i = 0; i < G->V; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
        path[i] = -1;
    }
    distance[s] = 0;
    for (i = 0; i < G->V; i++) {
        min = INT_MAX;
        for (j = 0; j < G->V; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (v = 0; v < G->V; v++) {
            if (!visited[v] && G->Adj[u][v] && distance[u] != INT_MAX && distance[u] + G->Adj[u][v] < distance[v]) {
                distance[v] = distance[u] + G->Adj[u][v];
                path[v] = u;
            }
        }
    }
    printf("Shortest paths from source vertex %d:\n", s);
    for (i = 0; i < G->V; i++) {
        if (distance[i] == INT_MAX)
            printf("%d -> %d = %s\n", s, i, "INF");
        else {
            printf("%d -> %d = %d\tPath: %d", s, i, distance[i], i);
            j = i;
            while (path[j] != -1) {
                printf(" <- %d", path[j]);
                j = path[j];
            }
            printf("\n");
        }
    }
}




