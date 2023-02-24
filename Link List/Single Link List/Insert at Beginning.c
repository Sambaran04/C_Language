#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *add_big(struct node *head, int d){
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr -> data = d;
	ptr -> link = NULL;
	ptr -> link = head;
	head = ptr;
	return head;}
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
	int d;
	printf("Enter the Item you want to add: ");
	scanf("%d", &d);
	head = add_big(head, d);
	ptr = head;
	printf("List of items are: ");
	while (ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr->link;
}
}
