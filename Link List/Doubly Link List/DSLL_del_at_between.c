#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} * head, *last;

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if (head != NULL)
        {
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;

            for (i = 2; i <= n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                scanf("%d", &data);

                newNode->data = data;
                newNode->prev = last;
                newNode->next = NULL;

                last->next = newNode;
                last = newNode;
            }

            printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Linked List is empty.");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void reverse(){
    struct node*temp=NULL;
    struct node*current=head;

    while(current!=NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
}

int main()
{
    int n;

    head = NULL;

    printf("Enter the size of the doubly linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the doubly linked list: ");
    createList(n);

    printf("\nElements of the Doubly Linked list are: \n");
    display();

    reverse();
    printf("\nThe reversed Doubly Linked list is: \n");
    display();

    return 0;
}
