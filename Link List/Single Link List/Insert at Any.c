#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *add_at_any(struct node *head, int d, int size, int pos){
	struct node *ptr;
	ptr = head;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = d;
	temp -> link = NULL;
	//size --;
	while (size != pos){
		ptr = ptr -> link;
		size --;
	}
	temp -> link = ptr;
	ptr ->link =temp;
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
	int d, pos;
	printf("Enter the Item you want to add: ");
	scanf("%d", &d);
	printf("Enter the position: ");
	scanf("%d", &pos);
	ptr = add_at_any(head, d, pos, size);
	ptr = head;
	printf("List of items are: ");
	while (ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr->link;
}
}
