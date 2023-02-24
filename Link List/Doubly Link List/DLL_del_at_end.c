#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
} * head, *last;
void dll(int n){
    int i, data;
    struct node *newNode;

    if (n >= 1){
        head = (struct node *)malloc(sizeof(struct node));
        if (head != NULL){
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;
            last = head;
            for (i = 2; i <= n; i++){
                newNode = (struct node *)malloc(sizeof(struct node));
                scanf("%d", &data);

                newNode->data = data;
                newNode->prev = last;
                newNode->next = NULL;

                last->next = newNode;
                last = newNode;
            }
        }
    }
}
void display(){
    struct node *temp;
    if (head == NULL){
        printf("Linked List is empty.");
    }
    else{
        temp = head;
        while (temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void deleteatend(){
    struct node *ptr;
    ptr = head;
    if (head == NULL){
        printf("The linked list is empty");
    }
    else{
        while(ptr->next != NULL){  
            ptr = ptr -> next;   
        }  
        ptr->prev->next = NULL;
        free(ptr);
    }
}
int main(){
    int n;
    head = NULL;

    printf("Enter the size of the doubly linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the doubly linked list: ");
    dll(n);

    deleteatend();
    printf("Elements of the Doubly Linked list are: ");
    display();
return 0;
}