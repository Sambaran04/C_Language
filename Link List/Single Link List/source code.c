#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *add_big(struct node *head, int d){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = d;
	temp -> link = NULL;
	temp -> link = head;
	head = temp;
	return head;}
struct node *add_end(struct node *head, int d){
	struct node *ptr; //= (struct node *)malloc(sizeof(struct node));
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	ptr = head;
	temp -> data = d;
	temp -> link = NULL;
	while (ptr->link != NULL){
		ptr = ptr->link;
	}
		ptr -> link = temp;
	return head;}
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
struct node *del_end(struct node *head){
	if(head == NULL){
		printf("SLL is Empty");
	}
	else if(head -> link == NULL){
		free(head);
		head = NULL;
	}
	else{
		struct node *temp1= (struct node *)malloc(sizeof(struct node));
		temp1 = head;
		struct node *temp2= (struct node *)malloc(sizeof(struct node));
		temp2 = head;
		while (temp1 -> link != NULL){
			temp2 = temp1;
			temp1 = temp1 -> link;
		}
		temp2 -> link = NULL;
		free(temp1);
		temp1 = NULL;
	}
	return head;
}
void user_input_list(struct node *head, struct node *ptr);
void display(struct node *head, struct node *ptr);
void add_at_big(struct node *head, struct node *ptr);
void add_at_end(struct node *head, struct node *ptr);
//void add_at_any();
void delete_at_big(struct node *head, struct node *ptr);
void delete_at_end(struct node *head, struct node *ptr);
//void delete_at_any();
//void reverse_list();

void user_input_list(struct node *head,struct node *ptr){
	//struct node *ptr, *head;
	int size;
	printf("Enter the size: ");
	scanf("%d", &size);
	//struct node *head = (struct node *)malloc(sizeof(struct node));
	printf("Enter the item: ");
	scanf("%d", &(head -> data));
	head -> link = NULL;
	int i;
	//struct node *ptr;
	ptr = head;
	for (i=1; i<size; i++){
		struct node *new_node = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &(new_node -> data));
		new_node -> link = NULL;
		ptr -> link = new_node;
		ptr = ptr -> link;
	}
	/*ptr = head;
	printf("List of items are: ");
	while (ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr->link;
	}*/
}
void display(struct node *head, struct node *ptr){
	ptr = head;
	printf("List of items are: ");
	while (ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr->link;
	}
}
void add_at_big(struct node *head, struct node *ptr){
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

void add_at_end(struct node *head, struct node *ptr){
	int d;
	printf("Enter the Item you want to add: ");
	scanf("%d", &d);
	ptr = add_end(head, d);
	ptr = head;
	printf("List of items are: ");
	while (ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr->link;
}
}

void delete_at_big(struct node *head, struct node *ptr){
	head = del_first(head);
	ptr = head;
	/*printf("List of items are: ");
	while (ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr->link;
}*/
}

void delete_at_end(struct node *head, struct node *ptr){
	ptr = del_end(head);
	ptr = head;
	printf("List of items are: ");
	while (ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr->link;
}
}
int main(){
	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	int choice;
	printf("This is LINK LIST Operations: ");
	printf("\n1.Creation of SLL\n2.Traversal of SLL\n3.Insert at beginning\n4.Insert at End\n5.Insert at any point\n6.Delete at Beginning\n7.Delete at End\n8.Delete at any point\n9.Reverse of SLL\n10.EXIT\n");
	while (choice != 10){
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				user_input_list(head, ptr);
				break;
			case 2:
				display(head, ptr);
				break;
			case 3:
				add_at_big(head, ptr);
				break;
			case 4:
				add_at_end(head, ptr);
				break;
			//case 5:
			//	add_at_any();
			//	break;
			case 6:
				delete_at_big(head, ptr);
				break;
			case 7:
				delete_at_end(head, ptr);
				break;
			//case 8:
			//	delete_at_any();
				break;
			//case 9:
			//	reverse_list();
			//	break;*/
			case 10:
				printf("EXIT");
				exit(0);
		}
	}
return 0;}
