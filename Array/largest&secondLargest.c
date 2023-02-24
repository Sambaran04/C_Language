#include<stdio.h>
int main(){
	int arr[10],j, i,n,max,sec, temp;
	printf("Enter the number of elements in an array: ");
	scanf("%d", &n);
	printf("Enter the value of array:\n");
	for (i=0;i<n;i++){
		printf("Enter the element[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	sec=arr[0];
	for (i=0;i<n;i++){
		for (j=i+1; j<n; j++){
			if (arr[i]>arr[j]){
				temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	max=arr[0];
	for (i=0; i<n; i++){
		if (arr[i]>max){
			max=arr[i];
			sec=arr[i-1];}}
	printf("Largest element in the array is: %d\n", max);
	printf("Second Largest element in the array is: %d", sec);
return 0;}
