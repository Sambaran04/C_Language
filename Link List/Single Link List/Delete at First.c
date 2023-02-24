#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *del_first(struct node *head){
	if(head == NULL){
		printf("SLL is Empty");
	}
	else{
		struct node *temp= (struct node *)malloc(sizeof(struct node));
		temp = head;
		head = head ->link;
		free(temp);
		temp = NULL;
	}
	return head;
}
int main(){
	int size;
	printf("Enter the size: ");
	scanf("%d", &size);
	struct node *head = (struct node *)malloc(sizeof(struct node));
	printf("Enter the item: ");
	scanf("%d", &(head -> data));
	head -> link = NULL;
	int i;
	struct node *ptr;
	ptr = head;
	for (i=1; i<size; i++){
		struct node *new_node = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &(new_node -> data));
		new_node -> link = NULL;
		ptr -> link = new_node;
		ptr = ptr -> link;
	}
	head = del_first(head);
	ptr = head;
	printf("List of items are: ");
	while (ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr->link;
}
}
