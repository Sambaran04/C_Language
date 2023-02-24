#include<stdio.h> 

int no_vertices;
void printGraph(int adj[][no_vertices]){ 
    for(int i = 0; i < no_vertices; i++){
    for(int j = 0; j < no_vertices; j++){ 
        printf("%d ",adj[i][j]);
    }
    printf("\n");
    }
}
int main(){
    int start, end;
    printf("Enter the number of vertices: "); 
    scanf("%d",&no_vertices);
    int adj[no_vertices][no_vertices];

    for(int i = 0; i < no_vertices; i++){ 
        for(int j = 0; j < no_vertices; j++){
            adj[i][j] = 0;
        }
    }
    printf("to stop use -1 -1\n");
    while(start != -1 && end != -1){
        printf("Enter an edge from node(0 to %d) to node(0 to %d): ",no_vertices,no_vertices);
        scanf("%d %d",&start,&end); adj[start][end] = 1;
        adj[end][start] = 1;
    }
    printGraph(adj); 
return 0;
}
