#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000

struct Edge {
    int source;
    int dest;
    int weight;
};
struct Graph {
    int V;
    int E;
    struct Edge edges[MAX_VERTICES];
};
void printPath(int parent[], int dest) {
    if (parent[dest] == -1) {
        printf("%d ", dest);
        return;
    }
    printPath(parent, parent[dest]);
    printf("-> %d", dest);
}
void bellmanFord(struct Graph* graph, int source) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int parent[V];
    int i, j;
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[source] = 0;
    for (i = 1; i < V; i++) {
        for (j = 0; j < E; j++) {
            int u = graph->edges[j].source;
            int v = graph->edges[j].dest;
            int w = graph->edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    for (j = 0; j < E; j++) {
        int u = graph->edges[j].source;
        int v = graph->edges[j].dest;
        int w = graph->edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }
    for (i = 0; i < V; i++) {
        if (i == source){
            continue;
        }
        printf("Shortest distance from %d to %d: %d, Path: ", source, i, dist[i]);
        if (dist[i] == INT_MAX) {
            printf("No path\n");
        } else{
            printPath(parent, i);
            printf("\n");
        }
    }
}
int main() {
    struct Graph graph = {
        .V = 5,
        .E = 8,
        .edges = {
            {0, 1, 10},
            {0, 2, 5},
            {1, 2, 2},
            {1, 3, 1},
            {2, 1, 3},
            {2, 3, 9},
            {2, 4, 2},
            {3, 4, 4},
            {4, 0, 7},
            {4, 3, 6}
        }
    };
    int source = 0;
    bellmanFord(&graph, source);
    return 0;
}