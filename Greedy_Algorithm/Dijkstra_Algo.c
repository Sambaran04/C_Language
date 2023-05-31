#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

struct Node {
    int dest;
    int weight;
    struct Node* next;
};

struct Graph {
    struct Node* head[MAX_NODES];
    int num_nodes;
};

struct Graph* create_graph(int num_nodes) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        graph->head[i] = NULL;
    }
    return graph;
}

void add_edge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->dest = dest;
    node->weight = weight;
    node->next = graph->head[src];
    graph->head[src] = node;
}

void dijkstra(struct Graph* graph, int start_node, int* distance, int* parent) {
    int visited[MAX_NODES] = {0};

    for (int i = 0; i < graph->num_nodes; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[start_node] = 0;

    for (int i = 0; i < graph->num_nodes; i++) {
        int min_distance = INT_MAX;
        int current_node = -1;

        for (int j = 0; j < graph->num_nodes; j++) {
            if (!visited[j] && distance[j] < min_distance) {
                current_node = j;
                min_distance = distance[j];
            }
        }

        if (current_node == -1) {
            break;
        }

        visited[current_node] = 1;

        for (struct Node* node = graph->head[current_node]; node != NULL; node = node->next) {
            int neighbor = node->dest;
            int weight = node->weight;
            int new_distance = distance[current_node] + weight;
            if (new_distance < distance[neighbor]) {
                distance[neighbor] = new_distance;
                parent[neighbor] = current_node;
            }
        }
    }
}

int main() {
    int num_nodes = 5;
    struct Graph* graph = create_graph(num_nodes);
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 5);
    add_edge(graph, 1, 2, 2);
    add_edge(graph, 1, 3, 1);
    add_edge(graph, 2, 1, 3);
    add_edge(graph, 2, 3, 9);
    add_edge(graph, 2, 4, 2);
    add_edge(graph, 3, 4, 4);
    add_edge(graph, 4, 0, 7);
    add_edge(graph, 4, 3, 6);

    int distance[MAX_NODES];
    int parent[MAX_NODES];

    dijkstra(graph, 0, distance, parent);

    printf("Vertex\t Distance\tPath");
    for (int i = 0; i < num_nodes; i++) {
        printf("\n%d\t %d\t\t", i, distance[i]);
        int j = i;
        while (parent[j] != -1) {
            printf("%d <- ", j);
            j = parent[j];
        }
        printf("%d", j);
    }
return 0;
}