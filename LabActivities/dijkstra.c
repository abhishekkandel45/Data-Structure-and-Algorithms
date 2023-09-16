//Date :11-9-2023

// From a given vetex in the weighted connected graph, find shortest paths to other vertices using Dijkstra's algorithm.

#include <stdio.h> 
#include <limits.h>
#include <stdlib.h>

struct Graph
{
    int V;
    int E;
    int **adj; // 2D array
};

struct Graph *adjMatrixofGraph()
{
    int u, v, w;
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    if (!G)
    {
        printf("Memory Error");
        return NULL;
    }
    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &G->V, &G->E);
    G->adj = (int **)malloc(sizeof(int *) * G->V);
    for (int i = 0; i < G->V; i++)
    {
        G->adj[i] = (int *)malloc(sizeof(int) * G->V);
        for (int j = 0; j < G->V; j++)
            G->adj[i][j] = 0;
    }
    printf("Enter %d edges with weights:\n", G->E);
    for (int i = 0; i < G->E; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        G->adj[u][v] = w;
        G->adj[v][u] = w;
    }
    return G;
}

void printMatrix(struct Graph *G)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < G->V; i++)
    {
        for (int j = 0; j < G->V; j++)
            printf("%d ", G->adj[i][j]);
        printf("\n");
    }
}

int findMinVertex(int *distance, int *visited, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
            minVertex = i;
    }
    return minVertex;
}


void dijkstra(struct Graph *G, int src)
{
    int *distance = (int *)malloc(sizeof(int) * G->V);
    int *visited = (int *)malloc(sizeof(int) * G->V);
    for (int i = 0; i < G->V; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[src] = 0;
    for (int i = 0; i < G->V - 1; i++)
    {
        int minVertex = findMinVertex(distance, visited, G->V);
        visited[minVertex] = 1;
        for (int j = 0; j < G->V; j++)
        {
            if (G->adj[minVertex][j] != 0 && !visited[j])
            {
                int dist = distance[minVertex] + G->adj[minVertex][j];
                if (dist < distance[j])
                    distance[j] = dist;
            }
        }
    }
    printf("Shortest distances from source vertex %d:\n", src);
    for (int i = 0; i < G->V; i++)
        printf("Vertex %d: %d\n", i, distance[i]);
}

int main()
{
    struct Graph *G = adjMatrixofGraph();
    printMatrix(G);
    dijkstra(G, 0);
    return 0;
}
