#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}  * head;
void cll(int size){
    struct node *newnode, *temp;
    head = NULL;
    for (int i=0; i<size; i++){
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
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
int main(){
    int size;
    printf("Enter the size of the circular linked list: ");
    scanf("%d", &size);
    printf("Enter the elements of the linked list: ");
    cll(size);
    printf("The elements of the linked list are: ");
    display();
return 0;
}