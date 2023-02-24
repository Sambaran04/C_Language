#include<stdio.h>
#define n 3
int main()
{
    int queue[n],ch=1,front=0,rear=0,i,j=1,x=n;
    printf("This is QUEUE Operation using Array:");
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    while(ch){
        printf("\nEnter the Choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            if(rear==x)
                printf("\nQueue is Full");
            else{
                printf("Enter no: ");
                scanf("%d",&queue[rear++]);
            }
            break;
        case 2:
            if(front==rear){
                printf("\nQueue is empty");
            }
            else{
                printf("\nDeleted Element is %d",queue[front++]);
                x++;
            }
            break;
        case 3:
            if(front==rear)
                printf("\nQueue is Empty");
            else{	
                printf("\nQueue Elements are:");
                for(i=front; i<rear; i++){
                    printf(" %d",queue[i]);
                }
                break;
            case 4:
            	printf("EXIT");
                exit(0);
            default:
                printf("Wrong Choice: please see the options");
            }
        }
    }
    return 0;
}