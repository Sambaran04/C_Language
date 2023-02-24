#include<stdio.h>
#include<stdlib.h>
int len;
struct node{
    int data;
    struct node *link;
};
struct node* head=NULL;
struct node* front=NULL;
struct node* rear=NULL;
void creation();
void traversal();
void insert_at_beg();
void insert_at_end();
void insert_at_any_position();
void delete_beg();
void delete_end();
void delete_any_position();
void reverse();
int length();
void stack_operation();
void push();
void pop();
void queue_operation();
void enqueue();
void deceue();
void display();

void display(){
  struct node *temp;
  temp=front;
  if(temp==NULL){
      printf("The sll is empty\n");
  }
  else{
    while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->link;
    }
	}
    printf("\n");
}
void dequeue(){
  struct node *temp;
  if(front==rear){
    printf("The sll is enpty\n");
  }
  else{
    temp=front;
    printf("%d is deleted\n",temp->data);
    front=front->link;
    free(temp);
  }
}
void enqueue(){
  struct node *temp =(struct node*)malloc(sizeof(struct node));
  temp->link=NULL;
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  if(front==rear){
    front=rear=temp;
  }
  else{
  rear->link=temp;
  temp=rear;
  rear->link=NULL;
  }
}
void queue_operation(){
  int b;
  printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
  while(b != 4){
    printf("\nEnter your choice: ");
    scanf("%d",&b);
    switch (b)
    {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      main();
      break;
    
    default:
      printf("Invalid entry");
      break;
    }
  }
}
void pop(){
   struct node *temp;
  temp=head;
  if(temp==NULL){
      printf("The sll is empty\n");
  }
  else{
       temp=head;
       printf("%d is deleted\n",temp->data);
       head=head->link;
       temp->link=NULL;
       free(temp);
      }
    
    printf("\n");

}
void push(){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  temp->link=head;
  head=temp;
  
}
void stack_operation(){
  int a;
  printf("1.Push\n2.Pop\n3.Display\n4.Exit");
  while(a != 4){
    printf("\nEnter your choice: ");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      traversal();
      break;
    case 4:
      main();
      break;
    
    default:
      printf("Invalid entry\n");
      break;
    }
  }
}
int length(){
  int count=0;
  struct node*temp;
  temp =head;
  while(temp!=NULL){
    count++;
    temp=temp->link;
  }
  return count;
}
void reverse(){
  struct node *prevNode, *curNode;
  if(head != NULL) {
   prevNode = head;
   curNode = head->link;
   head = head->link;
   prevNode->link = NULL; 
   while(head != NULL){
            head = head->link;
            curNode->link = prevNode;
         prevNode = curNode;
            curNode = head;
        }
    head = prevNode; 
    printf("SLL is Reversed\n");
  }
}
void delete_any_position(){
   if(head==NULL){
    printf("SLL is empty\n");
	}
	else if(head->link==NULL){
   		free(head);
   		head=NULL;
   	}
   else{
    struct node*temp=head;
    struct node*ptr=head;
    int i=0,position;
    printf("Enter the position: ");
    scanf("%d",&position);
     	if(head==NULL){
    printf("SLL is empty\n");
  }
  		else if(position==1){
    head=head->link;
    printf("%d is deleted", ptr -> data);
    free(ptr);
    ptr=NULL;
  }
  		else if(position==len){
      		while(temp->link!=NULL){
        	ptr=temp;
        	temp=temp->link;
      	}
    ptr->link=NULL;
    printf("%d is deleted", temp -> data);
    free(temp);
    temp=NULL;
  }
  		else{
    		while(i<position-1){
      		temp=temp->link;
      		i++;
    	}
    ptr=temp->link;;
    temp->link=ptr->link;
    ptr->link=NULL;
    printf("%d is deleted", ptr -> data);
    free(ptr);
  }
}
}
void delete_beg(){
  if(head==NULL){
    printf("SLL is empty\n");
  }
  else{
    struct node *ptr=head;
    head=head->link;
    printf("%d is deleted",ptr->data);
    free(ptr);
    ptr->link=NULL;
  }
}
void delete_end(){
  if(head==NULL){
    printf("SLL is empty\n");
  }
  else if(head->link==NULL){
    free(head);
    head=NULL;
  }
  else{
    struct node *temp=head;
    struct node *ptr=head;
    while(temp->link!=NULL){
      ptr=temp;
      temp=temp->link;
    }
    ptr->link=NULL;
    printf("%d is Deleted", temp -> data);
    free(temp);
    temp=NULL;
  }
}

void insert_at_any_position(){
  int position,i=0;
   struct node *ptr;
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  ptr=head;
  printf("Enter the position: ");
  scanf("%d",&position);
  printf("Enter node data: ");
  scanf("%d",&temp->data);
  temp->link=NULL;
  len=length();
  if(position==1){
    if(head==NULL){
    head=temp;
    }
	else{
     temp->link=head;
     head=temp;
    }
  }
  	else if(position==len){
    	while(ptr->link!=NULL){
      	ptr=ptr->link;
    }
    ptr->link=temp;
  }
  	else{
  		while(i<position-1){
    	ptr=ptr->link;
    	i++;
  }
  temp->link=ptr->link;
  ptr->link=temp; 

  }
}
void insert_at_end(){
  struct node *ptr;
  struct node *temp=(struct node*)malloc(sizeof(struct node*));
    temp->link=NULL;
  	printf("Enter node data: ");
  	scanf("%d",&temp->data);
	ptr = head;
    while(ptr->link!=NULL){
      ptr=ptr->link;
    }
    ptr->link=temp;
  
}
void insert_at_beg(){
  struct node *temp =(struct node*)malloc(sizeof(struct node));
  printf("Enter node data: ");
  scanf("%d",&temp->data);
  temp->link=NULL;
  if(head==NULL){
    head=temp;
  }
  else{
    temp->link=head;
    head=temp;
  }  
}
void traversal(){
  struct node *temp =head;
  if(temp==NULL){
      printf("The sll is empty\n");
  }
  else{
       while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->link;
      }
    }
    printf("\n");
}
void creation(){
  struct node *temp =(struct node*)malloc(sizeof(struct node));
  printf("Enter node data: ");
  scanf("%d",&temp->data);
  temp->link=NULL;
  if(head==NULL){
    head=temp;
  }
  else{
    struct node *ptr;
    ptr=head;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
  }

}
int main(){
    int choice;
    printf("This is LINK LIST Operations: ");
	printf("\n1.Creation of SLL\n2.Traversal of SLL\n3.Insert at beginning\n4.Insert at End\n5.Insert at any point\n6.Delete at Beginning\n7.Delete at End\n8.Delete at any point\n9.Reverse of SLL\n10.Stack Operation\n11.Queue Operation\n12.EXIT\n");
    while(choice != 12){
    	printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                creation();
                break;
            case 2:
                traversal();
                break;
            case 3:
                insert_at_beg();
                break;
             case 4:
                insert_at_end();
                break;
            case 5:
                insert_at_any_position();
                break;
            case 6:
                delete_beg();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                delete_any_position();
                break;
            case 9:
                reverse();
                break;
            case 10:
                stack_operation();
                break;
            case 11:
                queue_operation();
                break;
            case 12:
            	printf("EXIT");
                exit(0);
                break;
            default:
                  printf("invalid\n");
        }

    }
}