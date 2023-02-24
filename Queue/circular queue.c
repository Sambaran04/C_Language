#include <stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
int Circular[10];
int R = 0; 
int F = 0;
int L=4;
int next=0;

int main()
{
    int ch;
    printf("This is a Circular Queue Operation:");
    printf("\n1.Enqeue_CQ\n2.Dequeue_CQ\n3.Display\n4.EXIT");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch){
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
            break;
            default:
            printf("You have entered an Invalid Choice.\n");
        } 
    } 
} 
void enqueue(){
    int item,next;
    if (F==0){
    	F=1;
    	R=1;
    	printf("Enter the element to be inserted: ");
    	scanf("%d",&item);
    	Circular[F]=item;	
    }  
    else{
    	next=(R%L)+1;
    	   if(next!=F){
				R=next;
				printf("Enter the element to be inserted: ");
				scanf("%d",&item);
				Circular[R]=item;
    	   }
    	   else{
    	   		printf("Queue is full\n");
    	   }
	}
}
void dequeue(){    
   int item;
   if(F==0){
   	printf("\nQueue is empty");
	}	
   else{
   	item=Circular[F];
   	   if(F==R){
   	   	F=0;
   	   	R=0;
   	   }
   	   else{
   	   	F=(F%L)+1;
   	   	printf("\nDeleted element in the circular queue is: %d",item);
   	   }
   }
}
void display(){
	int i;
    
    if (F == 0)
        printf("\nQueue is Empty.");
    else{	
		printf("The Circular Queue is: ");
    	if(F<=R){
    		for(i=1;i<=L;i++){
    			if(i<F || i>R){
    				printf(" *");
    			}
    			else{
    				printf(" %d",Circular[i]);
    			}
    		}
    	}
    	else{
    		for(i=1;i<=R;i++){
    			printf(" %d",Circular[i]);
    		}
    		for(i=R+1;i<F;i++){
    			printf(" * ");
    		}
    		for(i=F;i<=L;i++){
    			printf(" %d",Circular[i]);
    		}
    	}
    }
}