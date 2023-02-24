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
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
void deleteatend(){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = (struct node *)malloc(sizeof(struct node));

    if (head == NULL){
        printf("Linked list is empty\n");
    }
    else{
        ptr = head;
        p = head->next;

        while (p->next != head){
            p = p->next;
            ptr = ptr->next;
        }
        ptr->next = head;
        free(p);
    }
}
int main(){
    int size;
    printf("Enter the size of the circular linked list: ");
    scanf("%d", &size);
    printf("Enter the elements of the linked list: ");
    create(size);
    printf("The elements of the linked list are: ");
    display();
    deleteatend();
    printf("\nThe elements of the linked list are: ");
    display();
return 0;
}