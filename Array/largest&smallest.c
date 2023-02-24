#include<stdio.h>
int main(){
	int arr[10], i,n,max,min, max_pos, min_pos;
	printf("Enter the number of elements in an array: ");
	scanf("%d", &n);
	printf("Enter the value of array:\n");
	for (i=0;i<n;i++){
		printf("Enter the element[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	max=min=arr[0];
	
	for (i=0; i<n; i++){
		if (arr[i]>max){
			max=arr[i];
			max_pos = i;}
		if (arr[i]<min){
			min=arr[i];
			min_pos = i;}
	}
	printf("Largest element in the array is: %d and It's position is: %d\n", max, max_pos);
	printf("Smallest element in the array is: %d and It's position is: %d", min, min_pos);
return 0;
}
