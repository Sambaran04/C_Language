#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
} * head;
void create(int size){
    struct node *newnode, *temp;
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
        printf("Linked list is empty\n");
    }
    else{
        temp = head;
        do{
            printf("%d\n", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
void reverse(){
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current = head;
    struct node *prev, *next;
    prev = NULL;
    if (head == NULL){
        printf("The linked list is empty");
    }
    else{
        do{
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);
        head->next = prev;
        head = prev;
    }
}
int main(){
    int size;
    printf("Enter the size of the circular linked list: \n");
    scanf("%d", &size);
    printf("Enter the elements of the circular linked list: \n");
    create(size);
    printf("The elements of the circular linked list are: \n");
    display();
    reverse();
    printf("The reversed circular list is: \n");
    display();
return 0;
}