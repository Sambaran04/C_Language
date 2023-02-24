#include<stdio.h>
int main(){
	int arr[100];
	int i,n,key,pos;
	printf("Enter the number of elements in an array: ");
	scanf("%d", &n);
	printf("Enter the value of array: \n");
	for (i=0;i<n;i++){
		printf("Enter the element[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	printf("Input Array elements are: ");
	for (i=0;i<n;i++){
		printf("%d ", arr[i]);}
	printf("\nEnter the element to be inserted: ");
	scanf("%d", &key);
	printf("Enter the position at which the element to be inserted: ");
	scanf("%d", &pos);
	n++;
	for (i=n-1; i>=pos; i--)
		arr[i]=arr[i-1];
	arr[pos]=key;
	printf("The final Array is: ");
	for (i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
return 0;
}
