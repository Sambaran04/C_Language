#include <stdio.h>
int stack[10], choice, n, top, x, i;
void push(void);
void pop(void);
void display(void);
int main()
{
    top = -1;
    printf("Enter the size of the Stack:");
    scanf("%d", &n);
    printf("STACK OPERATION USING ARRAY:\n");
    printf("-----------------------------\n");
    printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    do
    {
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("\nEXIT");
            break;
        }
        default:
        {
            printf("INVALID CHOICE....Enter a choice (1-4):\n");
        }
        }
    } while (choice != 4);
    return 0;
}
void push(){
	
    if (top >= n - 1)
    {
        printf("\nStack is in overflow\n");
    }
    else
    {
        printf("Enter the value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top <= -1)
    {
        printf("\nStack is in underflow\n");
    }
    else
    {
        printf("The popped element is:%d\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        printf("\nThe elements in the Stack:\n");
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
        printf("\nPress the Next choice\n");
    }
    else
    {
        printf("\nThe stack is empty\n");
    }
}
