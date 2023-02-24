#include<stdio.h>
int main(){
	int arr[50];
	int i,j,x,temp,n;
	printf("Enter the number of elements in an array: ");
	scanf("%d", &n);
	printf("Enter the value of array: \n");
	for (i=0;i<n;i++){
		printf("Enter the element[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	printf("Enter the position of the array you want to delete: ");
	scanf("%d", &x);
	if (x>n+1){
		printf("\nDeletion is not possible in the array");
	}
	else {
		for (i=x; i<n-1; i++){
			arr[i]=arr[i+1];
		}
	}
	for (i=0; i<n; i++){
		for (j=i+1; j<n; j++){
			if (arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("The array after sort: ");
	for (i=0; i<n-1; i++){
		printf("%d ", arr[i]);
	}
return 0;}
