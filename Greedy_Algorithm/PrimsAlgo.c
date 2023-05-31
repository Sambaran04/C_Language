#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
void MST_PRIMS(int G[20][20], int w[20][20], int r, int V) {
    int u, v, i;
    int keys[20];
    int pie[20];
    bool Q[20];
    
    for (u = 0; u < V; u++) {
        keys[u] = INT_MAX;
        pie[u] = -1;
        Q[u] = true;
    }
    keys[r] = 0;
    while (true) {
        int min_key = INT_MAX;
        int min_u = -1;
        for (u = 0; u < V; u++) {
            if (Q[u] && keys[u] < min_key) {
                min_key = keys[u];
                min_u = u;
            }
        }
        if (min_u == -1) break;
        Q[min_u] = false;
        for (v = 0; v < V; v++) {
            if (Q[v] && G[min_u][v] && G[min_u][v] < keys[v]) {
                pie[v] = min_u;
                keys[v] = G[min_u][v];
            }
        }
    }
    printf("Edge \tWeight\n");
    for (u = 1; u < V; u++) {
        printf("%d - %d \t%d \n", pie[u], u, w[u][pie[u]]);
    }
    int total_weight_sum = 0;
    for(u = 1; u < V; u++){
        total_weight_sum += w[u][pie[u]];
    }
    printf("Mimimum cost of the MST is: %d",total_weight_sum);
}
int main() {
    int V, G[20][20], w[20][20];
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    int i, j;
    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
            w[i][j] = G[i][j];
        }
    }
    MST_PRIMS(G, w, 0, V);
    return 0;
}