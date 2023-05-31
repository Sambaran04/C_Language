#include <stdio.h>
#include <stdlib.h>
    int adjacency_matrix[20][20];
    int visited[20];
    int stack[20];
    int top = -1;
void dfs(int v, int n) {
    visited[v] = 1;
    int i;
    for (i = 0; i < n; i++) {
        if (adjacency_matrix[v][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
    stack[++top] = v;
}
void topological_sort(int n) {
    int i;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i, n);
        }
    }
    printf("Topological Sort: ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
    int u, v;
    printf("Enter an edge (u v): ");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adjacency_matrix[u][v] = 1;
    }
    topological_sort(n);
    return 0;
}