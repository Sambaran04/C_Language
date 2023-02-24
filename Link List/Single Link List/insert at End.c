#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *add_at_end(struct node *head, int d){
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	ptr = head;
	temp -> data = d;
	temp -> link = NULL;
	while (ptr->link != NULL){
		ptr = ptr->link;
	}
		ptr -> link = temp;
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
	ptr = add_at_end(head, d);
	ptr = head;
	printf("List of items are: ");
	while (ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr->link;
}
}
