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

            printf("YOUR LIST IS CREATED");
        }else{
            printf("Unable to allocate memory");
        }
    }
}
void display(){
    struct node *temp;

    if (head == NULL){
        printf("List is empty.");
    }
    else{
        temp = head;
        while (temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
int main(){
    int n;
    head = NULL;

    printf("Enter the size of the doubly linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the doubly linked list: ");
    dll(n);

    printf("\nElements of the Doubly Linked list are: ");
    display();

    return 0;
}