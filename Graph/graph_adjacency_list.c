#include<stdio.h> 
#include<stdlib.h> 
int no_vertices; 
struct node{
    int data;
    struct node *next;
};
void readGraph(struct node *adj[]){ 
    struct node *newnode;
    int data; 
    int k;
    for(int i = 0; i < no_vertices; i++){ 
        struct node *last = NULL;
        printf("How many vertices are adjacent to %d: ",i); 
        scanf("%d",&k);
        for(int j = 1; j <= k; j++){
            newnode = (struct node *)malloc(sizeof(struct node *)); 
            printf("Enter the %d neighbour of %d: ",j,i); 
            scanf("%d",&data);
            newnode->data = data; 
            newnode->next = NULL;
    
            if(adj[i] == NULL){
                adj[i] = newnode;
            }
            else{
                last->next = newnode;
            }
            last = newnode;
        }
    }
}

void printGraph(struct node *adj[]){ 
    struct node *temp;
    for(int i = 0; i < no_vertices; i++){ 
        temp = adj[i];
        printf("\nVertices adjacent to %d are: ",i); 
        while(temp != NULL){
            printf("%d\t",temp->data); 
            temp = temp->next;
        }
    }
}

void printGraph(); 
int main(){
    printf("Enter the number of vertices in graph: "); 
    scanf("%d",&no_vertices);
    struct node *adj[no_vertices];
 
    for(int i = 0; i < no_vertices; i++){ 
        adj[i] = NULL;
 
    }
    readGraph(adj); 
    printGraph(adj);
}
