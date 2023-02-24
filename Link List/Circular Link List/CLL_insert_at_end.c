#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} * head;
void cll(int size){
    struct node *temp, *newnode;
    head = NULL;
    for (int i = 0; i < size; i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &(newnode->data));
        newnode->next = NULL;
        if (head == NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
    temp->next = head;
}
void display(){
    struct node *temp;
    if (head == NULL){
        printf("CLL is empty");
    }
    else{
        temp = head;
        while (temp->next != head){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
}
void insertatend(int item){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    ptr->data = item;
    if (head == NULL){
        head = ptr;
        ptr->next = head;
    }
    else{
        temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
        printf("After inserting the list is: ");
    }
}

int main(){
    int size, item;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);
    printf("Enter the elements of the linked list: ");
    cll(size);
    printf("The elements of the linked list are: ");
    display();
    printf("\nEnter the element you want to insert at the End: ");
    scanf("%d", &item);
    insertatend(item);
    display();
return 0;
}