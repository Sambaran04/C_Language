#include<stdio.h>
int main(){
	int arr[100];
	int i,j,n,m,temp,key,pos;
	printf("Enter the number of elements in an array: ");
	scanf("%d", &n);
	printf("Enter the value of array: \n");
	for (i=0;i<n;i++){
		printf("Enter the element[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	printf("Input array elements are: ");
	for (i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\nEnter the element to be inserted: ");
	scanf("%d", &key);
	n++;
	
	for (i=n-1; i>=pos; i--)
		arr[i]=arr[i-1];
arr[pos]=key;

	for (i=0;i<n;i++){
		for (j=i+1; j<n; j++){
			if (arr[i]>arr[j]){
				temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("\nFinal Array is: ");
	for (i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
return 0;
}
